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

#include "../include/env_built_ins.h"

// Saves the array's head iterates over it printing its values and
// returns the head.
char** my_zsh_env(char** arguments, char** environment)
{
    arguments += 0;
    char** environment_head = environment;
    for (; *environment; environment++)
    {
        write(1, *environment, my_strlen(*environment));
        write(1, "\n", 1);
    }
    return environment_head;
}

// Copies the string from arguments, breaks it up, looks up the variable
// in the environment, replaces it with the copied string.
// If not found appends it at the end.
char** my_zsh_setenv(char** arguments, char** environment)
{
    char* new_string = my_strcpy(arguments[1]);
    char** variable = my_strtok(arguments[1], "=");
    char** environment_head = environment;
    environment = find_variable(environment, variable[0]);
    if (environment)
    {
        free(*environment);
        *environment = new_string;
        environment = environment_head;
    }
    else
    {
        char** environment_copy = copy_environment(environment_head);
        char* tail[2] = {new_string, NULL};
        environment = environment_concat(environment_copy, tail);
        free(environment_copy);
    }
    free(variable);
    return environment;
}

// Copies the environment, finds entry in the copy, replaces it with NULL
// and concatenates two resulting arrays.
char** my_zsh_unsetenv(char** arguments, char** environment)
{
    char** variable = my_strtok(arguments[1], "=");
    environment = copy_environment(environment);
    char** environment_head = environment;
    environment = find_variable(environment, variable[0]);
    char** environment_tail = NULL;
    // If it isn't the last entry.
    if (*(environment + 1)) environment_tail = environment + 1;
    free(*environment);
    *environment = NULL;
    free(variable);
    environment = environment_concat(environment_head, environment_tail);
    if (environment_head != environment) free(environment_head);
    return environment;
}

// Finds and prints the absolute pathname of the app.
char** my_zsh_which(char** arguments, char** environment)
{
    char* full_name = find_full_name(arguments + 1, environment);
    if (full_name)
    {
        write(1, full_name, my_strlen(full_name));
        write(1, "\n", 1);
        free(full_name);
    }
    return environment;
}

// Creates artificial arguments for the built-in function setenv.
char** set_old_pwd(char* current_dir, char** environment)
{
    char* variable = my_strcat("OLDPWD=", current_dir);
    free(current_dir);
    char* oldpwd_equals[2] = {NULL, variable};
    environment = my_zsh_setenv(oldpwd_equals, environment);
    free(variable);
    current_dir = get_current_dir();
    variable = my_strcat("PWD=", current_dir);
    char* pwd_equals[2] = {NULL, variable};
    environment = my_zsh_setenv(pwd_equals, environment);
    free(variable);
    free(current_dir);
    return environment;
}

// Backs up the values and sends them with artificial arguments
// to the built-in function setenv.
char** swap_old_pwd(char** environment)
{
    char** old_pwd_variable = find_variable(environment, "OLDPWD");
    char* old_pwd_string = my_strcpy(*old_pwd_variable + 7);
    char** pwd_variable = find_variable(environment, "PWD");
    char* pwd_string = my_strcpy(*pwd_variable + 4);
    char* variable = my_strcat("PWD=", old_pwd_string);
    free(old_pwd_string);
    char* oldpwd_equals[2] = {NULL, variable};
    environment = my_zsh_setenv(oldpwd_equals, environment);
    free(variable);
    variable = my_strcat("OLDPWD=", pwd_string);
    free(pwd_string);
    char* pwd_equals[2] = {NULL, variable};
    environment = my_zsh_setenv(pwd_equals, environment);
    free(variable);
    return environment;
}
