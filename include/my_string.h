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

#ifndef MY_ZSH_MY_STRING_H_
#define MY_ZSH_MY_STRING_H_

#include <stdlib.h>
#include <stddef.h>

#include "constructors.h"

// Returns the glued up string or NULL if any of the arguments is NULL.
char* my_strcat(char* first_string, char* second_string);

// Returns the length of a given null terminated string.
int my_strlen(char* string);

// Compares one string to another. Returns 0 if they are equal,
// 1 if ascii codes of the first one are bigger and 2 in the opposite case,
// -1 if one but not both of the arguments are NULL;
int my_strcmp(char* string1, char* string2);

// Copies one string to another.
char* my_strcpy(char* origin_string);

// Fills the string with the characters up to a length.
char* my_memset(char* string, char character, int length);

// Returns a NULL terminated array of tokens of the string.
char** my_strtok(char* string, char* delimiter);

// Finds the first occurence of delimiter in the string.
int my_strspan(char* string, char* delimiter);

#endif  // MY_ZSH_MY_STRING_H_
