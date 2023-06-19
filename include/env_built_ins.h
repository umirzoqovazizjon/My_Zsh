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

#ifndef MY_ZSH_ENV_BUILT_INS_H_
#define MY_ZSH_ENV_BUILT_INS_H_

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

#include "my_string.h"
#include "environment.h"
#include "launch.h"

// Lists the environment variables.
// In-shell usage: env.
char** my_zsh_env(char** arguments, char** environment);

// Sets an environment variable.
// In-shell usage: setenv VAR=abc.
char** my_zsh_setenv(char** arguments, char** environment);

// Deletes an environment variable.
// In-shell usage: unsetenv VAR.
char** my_zsh_unsetenv(char** arguments, char** environment);

// Outputs the first occurence of an app in the PATH variable entries.
// In-shell usage: which ls.
char** my_zsh_which(char** arguments, char** environment);

// Sets the values of PWD and OLDPWD environment variables.
char** set_old_pwd(char* current_dir, char** environment);

// Swaps the values of PWD and OLDPWD environment variables.
char** swap_old_pwd(char** environment);

#endif  // MY_ZSH_ENV_BUILT_INS_H_
