# Simple Shell
## Description
The project consists in the creation of a simple shell that will allow the user to interact with the system using commands.

It handles the PATH to find the programs it will execute.
Stat() will be used to check if the found file can be executed.
It will use the execve() system call to perform the commands.
The execution of the programs will be done under children processes using fork().
CTRL+C won't close the program, CTRL+D will do.
### Instructions
The program was tested and compiled on Ubuntu 14.04 LTS using the gcc command (gcc 4.8.4): (gcc -Wall -Werror -Wextra -pedantic *.c -o hsh)
Following this, the expected way to execute the program is by typing:
(./hsh)
You can exit the program at any time using the exit command (Also with a status):
exit or exit 98\# test_simple_shell