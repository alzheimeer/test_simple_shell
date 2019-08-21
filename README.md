# Simple Shell
## Description
The project consists in the creation of a simple shell that will allow the user to interact with the system using commands.

It handles the PATH to find the programs it will execute.
It will use the execve() system call to perform the commands.
The execution of the programs will be done under children processes using fork().
CTRL+C won't close the program, with the command exit close the shell.
### Instructions
The program was tested and compiled on Ubuntu 14.04 LTS using the gcc command (gcc 4.8.4): (gcc -Wall -Werror -Wextra -pedantic *.c -o h)
Following this, the expected way to execute the program is by typing:
(./h)
You can exit the program at any time using the exit command (Also with a status):
exit or exit 98
