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

#ifndef MY_ZSH_ENVIRONMENT_H_
#define MY_ZSH_ENVIRONMENT_H_

#include <stdlib.h>

#include "my_string.h"

// Creates a copy of environment.
char** copy_environment(char** environment);

// Iteratively frees all the entries of the environment and
// the array itself.
int free_environment(char** environment);

// Concatenates two NULL terminated arrays.
char** environment_concat(char** head, char** tail);

// Returns the number of entries in the environment.
int environment_length(char** environment);

#endif  // MY_ZSH_ENVIRONMENT_H_
