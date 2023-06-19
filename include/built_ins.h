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

#ifndef MY_ZSH_BUILT_INS_H_
#define MY_ZSH_BUILT_INS_H_

#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include "my_string.h"
#include "env_built_ins.h"
#include "built_in_helpers.h"

// Echoes back the input.
// In-shell usage: echo "hello"
char **my_zsh_echo(char **arguments, char **environment);

// Changes current directory.
// In-shell usage: cd /
char **my_zsh_cd(char **arguments, char **environment);

// Prints working directory.
// In-shell usage: pwd
char **my_zsh_pwd(char **arguments, char **environment);

// Sends signal to exit shell.
// In-shell usage: exit
char **my_zsh_exit(char **arguments, char **environment);

#endif  // MY_ZSH_BUILT_INS_H_
