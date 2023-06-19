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

#include "../include/built_in_helpers.h"

char* get_current_dir()
{
    char* current_dir = malloc(sizeof(char) * 1024);
    my_memset(current_dir, '\0', 1024);
    getcwd(current_dir, 1024);
    return current_dir;
}

// Iterates over the array and searches for a match.
char** find_variable(char** environment, char* variable)
{
    if (!environment || !variable) return NULL;
    int length = my_strlen(variable);
    int found = 0;
    for (; *environment && !found; environment++)
    {
        int i = 0;
        for (i = 0; i < length; i++)
        {
            if ((*environment)[i] != variable[i]) break;
        }
        if (i == length)
        {
            found = 1;
            break;
        }
    }
    if (!found) return NULL;
    return environment;
}

// Finds the first directory containing the app
// and appends a slash and the app's name to it.
char* search_for_app(char** path, char* app)
{
    DIR* dir;
    struct dirent* entry;
    char* full_name = NULL;
    for (; *path && !full_name; path++)
    {
        if ((dir = opendir(*path)))
        {
            while ((entry = readdir(dir)) != NULL)
                if (my_strcmp(entry->d_name, app) == 0)
                {
                    char* slash = my_strcat(*path, "/");
                    full_name = my_strcat(slash, entry->d_name);
                    free(slash);
                    break;
                }
            closedir(dir);
        }
    }
    return full_name;
}
