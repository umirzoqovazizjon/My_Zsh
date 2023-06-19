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

#ifndef MY_ZSH_BUILT_IN_HELPERS_H_
#define MY_ZSH_BUILT_IN_HELPERS_H_

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

#include "my_string.h"
#include "environment.h"
#include "env_built_ins.h"

char* get_current_dir();

// Looks up a variable in the environment.
// Returns NULL if it hasn't been found, or any of the arguments are NULL.
char** find_variable(char** environment, char* variable);

// Looks up the PATH variable in the environment.
char** find_path(char** environment);

// Looks up the app's location in the directories of the PATH variable.
char* search_for_app(char** path, char* app);

#endif  // MY_ZSH_BUILT_IN_HELPERS_H_
