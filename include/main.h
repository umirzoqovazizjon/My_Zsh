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

#ifndef MY_ZSH_MAIN_H_
#define MY_ZSH_MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "my_string.h"
#include "execute.h"
#include "environment.h"

int main(int argc, char **argv, char **environment);

// Writes prompt.
int prompt();

// Frees multiple allocations inside the main loop.
char *free_in_loop(char **environment_copy, char **environment,
                   char **commands, char *line);

// Frees multiple allocations after the main loop.
char *free_after_loop(char **environment, char *line);

#endif  // MY_ZSH_MAIN_H_
