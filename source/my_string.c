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

#include "../include/my_string.h"

char* my_strcat(char* first_string, char* second_string)
{
    if (!first_string) return NULL;
    if (!second_string) return NULL;
    int length = my_strlen(first_string) + my_strlen(second_string) + 1;
    char* return_string = malloc(sizeof(char) * length);
    int i = 0;
    int j = 0;
    for (i = 0; first_string[i] != '\0'; i++)
    {
        return_string[i] = first_string[i];
    }
    for (j = 0; second_string[j] != '\0'; j++)
    {
        return_string[i + j] = second_string[j];
    }
    return_string[length - 1] = '\0';
    return return_string;
}

int my_strlen(char* string)
{
    if (!string) return -1;
    int i = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
        continue;
    }
    return i;
}

int my_strcmp(char* string1, char* string2)
{
    if (string1 == NULL && string2 == NULL) return 0;
    if (string1 == NULL || string2 == NULL) return -1;
    int i = 0;
    for (i = 0; string1[i] != '\0' || string2[i] != '\0'; i++)
    {
        if (string1[i] > string2[i]) return 1;
        if (string1[i] < string2[i]) return 2;
    }
    if (string1[i] == '\0' && string2[i] == '\0') return 0;
    if (string1[i] == '\0') return 2;
    if (string2[i] == '\0') return 1;
    return 0;
}

char* my_strcpy(char* origin_string)
{
    if (!origin_string) return NULL;
    int length = my_strlen(origin_string) + 1;
    char* target_string = malloc(sizeof(char) * length);
    for (int i = 0; i < length; i++)
    {
        target_string[i] = origin_string[i];
    }
    target_string[length - 1] = '\0';
    return target_string;
}

char* my_memset(char* string, char character, int length)
{
    for (int i = 0; i < length; i++)
    {
        string[i] = character;
    }
    return string;
}

// Looks up the first position of the delimiter in the string,
// saves the position to an array.
// In the end creates a new compact array and writes the positions to it.
char** my_strtok(char* string, char* delimiter)
{
    if (!string || !delimiter) return NULL;
    int string_length = my_strlen(string);
    int delimiter_length = my_strlen(delimiter);
    int* addresses = malloc(sizeof(int) * string_length);
    array_to_zero(addresses, string_length);
    int address_count = 0;
    char* string_head = string;
    while (string)
    {
        int first_delimiter = my_strspan(string, delimiter);
        if (first_delimiter > 0) string[first_delimiter] = '\0';
        if (first_delimiter != 0 && string[0] != '\0')
        {
            addresses[address_count] = string - string_head;
            address_count++;
        }
        if (first_delimiter < 0) break;
        string += first_delimiter + delimiter_length;
    }
    char** string_array = malloc(sizeof(char*) * (address_count + 1));
    for (int i = 0; i < address_count; i++)
    {
        string_array[i] = &string_head[addresses[i]];
    }
    string_array[address_count] = NULL;
    free(addresses);
    return string_array;
}

// Finds the first character, then checks if the delimiter is fully present.
int my_strspan(char* string, char* delimiter)
{
    int string_length = my_strlen(string);
    int delimiter_length = my_strlen(delimiter);
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == delimiter[0])
        {
            int j = 1;
            for (j = 1; (i + j) < string_length && j < delimiter_length; j++)
            {
                if (string[i + j] != delimiter[j])
                {
                    break;
                }
            }
            if (j == delimiter_length)
            {
                return i;
            }
        }
    }
    return -1;
}
