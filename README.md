# Welcome to My Zsh
***

## Task
Write a user-facing shell of Linux kernel, with a bunch of built-in commands\
and error reporting. The challenge is to learn how to use fork and execve\
system calls and work with the null terminated array of pointers of shell\
environments.

## Description
I looked up how other people wrote simple shells and draw inspiration from\
that. I had to look up how to work with files and directories as well,\
because I didn't really remember it from my tar. Learned a bit how to work\
with different threads and print raw values in gdb. Did some practice with\
pointers to variables in dynamic allocations, with pointers to functions in\
the static allocation.

First I implemented "cd -" in the main routine,\
commit 1cadb000fe6ddd23047964f4221700e2ec6bfa90. Then I reimplemented it\
using the OLDPWD environment variable, for it to be more canonical.

Gandalf asks for the "quit" command, assignment seems to be asking for\
"exit", I had to add both.

Function call graphs are in graph.png graph.svg built_ins_graph.txt\
Builtins are separated from main by function pointers array, hence\
the disparity.

## Installation
Download and run make, a file named my_zsh should appear in the directory.

## Usage
Works pretty much like every other shell, no fancy stuff though.

```
$ ./my_zsh 
[/home/teteabcmail/downloads/qwasar/season2/my_zsh]>echo "hi there"
hi there 
[/home/teteabcmail/downloads/qwasar/season2/my_zsh]>cat built-ins
echo, cd, setenv, unsetenv, env, exit, pwd and which
[/home/teteabcmail/downloads/qwasar/season2/my_zsh]>cd /tmp/
[/tmp]>touch a
[/tmp]>ls -l -a a
-rw-r--r-- 1 teteabcmail teteabcmail 0 Apr  8 11:10 a
[/tmp]>pwd
/tmp
[/tmp]>cd -
[/home/teteabcmail/downloads/qwasar/season2/my_zsh]>pwd
/home/teteabcmail/downloads/qwasar/season2/my_zsh
[/home/teteabcmail/downloads/qwasar/season2/my_zsh]>exit
[/home/teteabcmail/downloads/qwasar/season2/my_zsh]>
$ 
```
### The Core Team
Timur Timak  
Azizjon Umirzoqov

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
