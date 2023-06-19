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

#include "../include/main.h"

int main(int argc, char** argv, char** environment)
{
    argc += 0;
    argv += 0;
    environment = copy_environment(environment);
    char* line = NULL;
    size_t len = 0;
    int read;
    prompt();
    while (environment && (read = getline(&line, &len, stdin)) != -1)
    {
        if (read == 0) break;  // CTRL + d
        line[read - 1] = '\0';
        char** commands = my_strtok(line, " ");
        char** environment_copy = environment;
        if (commands[0]) environment = execute(commands, environment);
        line = free_in_loop(environment_copy, environment, commands, line);
        prompt();
    }
    free_after_loop(environment, line);
    write(1, "\n", 1);
    return 0;
}

int prompt()
{
    char string[1024];
    write(1, "[", 1);
    getcwd(string, sizeof(string));
    write(1, string, my_strlen(string));
    write(1, "]>", 2);
    return 0;
}

char* free_in_loop(char** environment_copy, char** environment,
                   char** commands, char* line)
{
    if (environment_copy != environment) free_environment(environment_copy);
    free(commands);
    free(line);
    return NULL;
}

char* free_after_loop(char** environment, char* line)
{
    if (environment) free_environment(environment);
    if (line) free(line);
    return NULL;
}
