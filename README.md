# Basic-Linux-Unix-Shell
Designing a simple unix shell in C

Linux (and other Unix like OSes), have “shells” which provides an interface to the unix system.

The program handles the following 2 types of commands through a command line interface for the shell:-
1) Internal Commands: Those which are interpreted by the shell program itself, without requiring a different program to handle the expected operations.
2) External Commands: Those commands which are not handled directly by the shell program but by an external program.

This shell can handle 3 internal commands("pwd","echo","cd") and 5 external commands("ls","date","cat","rm","mkdir"). 
The shell and its commands have been implemented using standard C libraries and linux system calls; the external commands have been handled by executing fork(), exec() & wait() family of system calls. A thread based execution using pthread_create()/system() can also be used for running these commands. The program also throws error messages if invalid commands are entered by the user.

Each command is capable of handling 2 different options. The following options have been handled for each command:-

1. echo: used to display any text/string that is passed as an argument after ‘echo’.
Options:
● echo -n: does not print a trailing newline character after its execution.
● echo -e(\b only): removes all spaces between the text passed as argument.

2. pwd: prints the working directory.
Options:
● pwd -L: displays value of PWD environment variable along with absolute path
name.
● pwd -P: displays absolute path name of the active directory.

3. cd: used as change directory command.
Options:
● cd .. : used to switch to the parent directory.
● cd / : used to change directory to the root directory.

4. ls: used to list the contents of a directory.
Options:
● ls -a: shows all the files including hidden files.
● ls -l: show files in a long list format.

5. cat: reads data from files and displays its contents in different formats.
Options:
● cat -n: displays contents of a file along with line numbers.
● cat -E: appends “$” character after every line in the file and prints the output.

6. mkdir: used to create new directories.
Options:
● mkdir -v: displays message after creating the directory.
● mkdir -p: creates parent directories as well if they do not exist.

7. rm: used to remove objects from a directory.
Options:
● rm -i: displays prompt before removing file.
● rm -f: removes a file forcefully.

8. date: used to display system date, time and other information.
Options:
● date -u: displays GMT.
● date “+%D”: displays date in dd/mm/yyyy format.

Steps to run the program:-
1) Clone the entire repository.
2) make; it should successfully compile all the programs.
3) Run the following command: ./shell
4) make clean; after exiting the program

Notes:
For thread based execution; enter "&t" after the command.
The program should be run preferably in unix based system



