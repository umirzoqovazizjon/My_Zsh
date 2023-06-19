/*Copyright (C) 2023 Timur Timak

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public
License along with this program. If not, see
<https://www.gnu.org/licenses/>. */

#include "../include/built_ins.h"

// Strips the double quotes off and prints the arguments.
// Removes the leading dollar sign and prints the variable.
char** my_zsh_echo(char** arguments, char** environment)
{
// Starts from the second entry, adds one to the pointer,
// until it reaches the end of the list.
    for (arguments++; *arguments; arguments++)
    {
        if (*arguments[0] == '$')
        {
            char** variable = find_variable(environment, *arguments + 1);
            write(1, *variable, my_strlen(*variable));
        }
        else
        {  // Non-variable echo.
            char** entry = my_strtok(*arguments, "\"");
            char** entry_head = entry;
            for (; *entry; entry++)
            {
                write(1, *entry, my_strlen(*entry));
            }
            free(entry_head);
        }
        write(1, " ", 1);
    }
    write(1, "\n", 1);
    return environment;
}

// Handles an empty, a hyphen and usual arguments to cd.
// Calls for two helper functions.
char** my_zsh_cd(char** arguments, char** environment)
{
    if (arguments[1] == NULL)
    {
        char* error = "my_zsh: expected argument to \"cd\"\n";
        write(2, error, my_strlen(error));
    }
    else if (my_strcmp(arguments[1], "-") == 0)
    {
        char** old_pwd = find_variable(environment, "OLDPWD");
        if (old_pwd)
        {
            if (chdir(*old_pwd + 7) != 0)  // Skip the "OLDPWD="
                perror("my_zsh");
            else
                environment = swap_old_pwd(environment);
        }
        else
        {
            char* error = "my_zsh: cd: OLDPWD not set\n";
            write(2, error, my_strlen(error));
        }
    }
    else
    {  // The normal case.
        char* current_dir = get_current_dir();
        if (chdir(arguments[1]) != 0)
        {
            perror("my_zsh");
            free(current_dir);
        }
        else
        {
            environment = set_old_pwd(current_dir, environment);
        }
    }
    return environment;
}

char** my_zsh_pwd(char** arguments, char** environment)
{
    arguments += 0;
    environment += 0;
    char string[1024];
    getcwd(string, sizeof(string));
    write(1, string, my_strlen(string));
    write(1, "\n", 1);
    return environment;
}

// Additions of zero to avoid the compiler's warning.
char** my_zsh_exit(char** arguments, char** environment)
{
    arguments += 0;
    environment += 0;
    return NULL;
}
