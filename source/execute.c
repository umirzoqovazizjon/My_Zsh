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

#include "../include/execute.h"

// In the for loop checks if the command calls for a function is in the
// array of pointers to built-in functions.
// Then launches the command if it is external.
char** execute(char** arguments, char** environment)
{
    char* builtin_strings[] = {"echo",   "cd",       "pwd",   "exit", "env",
                               "setenv", "unsetenv", "which", NULL};
    char** (*builtin_functions[])(char**, char**) = {
        my_zsh_echo, my_zsh_cd,     my_zsh_pwd,      my_zsh_exit,
        my_zsh_env,  my_zsh_setenv, my_zsh_unsetenv, my_zsh_which};
    int built_in = 0;
    if (my_strcmp(arguments[0], "quit") == 0)
    {
        environment = builtin_functions[3](arguments, environment);
        built_in = 1;
    }
    for (int i = 0; builtin_strings[i]; i++)
    {
        if (my_strcmp(arguments[0], builtin_strings[i]) == 0)
        {
            environment = builtin_functions[i](arguments, environment);
            built_in = 1;
        }
    }
    if (!built_in) launch(arguments, environment);
    return environment;
}
