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

#include "../include/environment.h"

char** copy_environment(char** environment)
{
    int length = environment_length(environment);
    char** new_environment = malloc(sizeof(char*) * (length + 1));
    int i = 0;
    for (; *environment; environment++)
    {
        new_environment[i] = my_strcpy(*environment);
        i++;
    }
    new_environment[length] = NULL;
    return new_environment;
}

int free_environment(char** environment)
{
    char** environment_head = environment;
    for (; *environment; environment++) free(*environment);
    free(environment_head);
    return 0;
}

// Allocates a new pointer array.
// Copies and frees old entries as it goes.
char** environment_concat(char** head, char** tail)
{
    if (!head && !tail) return NULL;
    if (!head) return copy_environment(tail);
    if (!tail) return head;
    int head_length = environment_length(head);
    int tail_length = environment_length(tail);
    char** new_head = malloc(sizeof(char*) * (head_length + tail_length + 1));
    int i = 0;
    for (; *head; head++)
    {
        new_head[i] = my_strcpy(*head);
        free(*head);
        i++;
    }
    for (; *tail; tail++)
    {
        new_head[i] = my_strcpy(*tail);
        free(*tail);
        i++;
    }
    new_head[i] = NULL;
    return new_head;
}

int environment_length(char** environment)
{
    int length = 0;
    for (; *environment; environment++) length++;
    return length;
}
