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

#ifndef MY_ZSH_LAUNCH_H_
#define MY_ZSH_LAUNCH_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "built_in_helpers.h"
#include "env_built_ins.h"

// Forks the process and executes a new app in the child.
int launch(char **args, char **environment);

// Finds the absolute pathname of the app.
char *find_full_name(char **arguments, char **environment);

// Check whether a file exists.
int file_exists(char *filename);

#endif  // MY_ZSH_LAUNCH_H_
