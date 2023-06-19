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

#include "../include/launch.h"

// Check whether called program exists.
// Finds absolute path of the app if only its name was given.
// Creates a new process with fork() which returns 0 in the child process.
// Executes an app in the child.
// exit() reports failure cause on failure.
// Parent waits for the child to terminate. Checks the current status
// of the child through WIFEXITED and WIFSIGNALED macro instructions.
// WUNTRACED makes waitpid() return even if the child has been stopped.
int launch(char** arguments, char** environment)
{
    int check = file_exists(arguments[0]);
    char* full_name = NULL;
    if (check)
    {
        full_name = arguments[0];
    }
    else
    {
        full_name = find_full_name(arguments, environment);
    }
    if (full_name)
    {
        pid_t pid = fork();
        if (pid == 0)
        {  // Child process.
            if (execve(full_name, arguments, environment) == -1)
                perror("my_zsh");
            exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {  // Error forking.
            perror("my_zsh");
        }
        else
        {  // Parent process.
            int status = 0;
            do
            {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
            char* segfault = "Segmentation fault!\n";
            if (WTERMSIG(status) == 11)
                {write(2, segfault, my_strlen(segfault));
            }
        }
        if (!check) free(full_name);
    }
    else if (!check)
    {
        char* not_found = "my_zsh: command not found!\n";
        write(2, not_found, my_strlen(not_found));
    }
    return 1;
}

// Finds the PATH variable, makes a copy of it, breaks it up
// and searches for the app's path.
char* find_full_name(char** arguments, char** environment)
{
    char* full_name = NULL;
    char* literal = "PATH=";
    int length = my_strlen(literal);
    environment = find_variable(environment, literal);
    if (*environment)
    {
        char* string_copy = my_strcpy(*environment + length);
        char** path_array = my_strtok(string_copy, ":");
        full_name = search_for_app(path_array, arguments[0]);
        free(string_copy);
        free(path_array);
    }
    return full_name;
}

int file_exists(char* filename)
{
    struct stat buffer;
    if (stat(filename, &buffer) == 0) return 1;
    return 0;
}
