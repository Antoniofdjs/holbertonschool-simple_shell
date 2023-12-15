# Holberton - Simple Shell

### Table of Contents

- [Description](#description)
- [Files](#files)
- [Commands](commands)
- [Use](#use)
- [Examples](#examples)
- [Resources](#resources)
- [Credits](#credits)

## Description

This was a simple recreation of a Unix command interpreter, capable of running basic commands. It mirrors a `sh` in a simple way.


## Files

- `README.md` - Contains a decription of the project.
- `AUTHORS` - Contains the programs creators.
- `functions` - Contains `get_tokens`, `get_path`and `my_exe` functions. 
- `main.h` - Contains the header and function prototypes.
- `simple_shell.c` - Our running shell program.
- `small_help_functions.c` - Contains `white_spaces`, `free_array` and `remove_newline` functions.

## Commands

  ### Some of the commands our shell can run:
  
- ls (-a, -l, -r and others) - list files in the current directory
- pwd - prints the current working directory
- rm (-r)- delete files
- echo - prints to stdin or sends text to a file
- cp - copy a file from one location to another
- mv - move or rename a file
- touch - create a file
- cat - prints a files content
- chmod - change a files properties (read, write or execute permissions)

## Use 
To compile, first have all files in the same directory.

The compilation used for this was:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
In the terminal:

```
./hsh
/bin/ls
ls
```
To run commands in interactive mode (run commands from characters)

```
echo "ls" | ./hsh
echo "pwd" | ./hsh
```
To run commands non-interactive mode (runs commands from outside our shell)


## Examples

```
juancalpz23@penguin:~/holbertonschool-simple_shell$ ls
get_path.c  main.h    README.md         simple_shell    stest
hsh         my_exe.c  remove_newline.c  simple_shell.c  tokens_to_args.c
juancalpz23@penguin:~/holbertonschool-simple_shell$ ./hsh
($) /bin/ls
get_path.c  main.h    README.md         simple_shell    stest
hsh         my_exe.c  remove_newline.c  simple_shell.c  tokens_to_args.c
($)exit
juancalpz23@penguin:~/holbertonschool-simple_shell$
```
```
juancalpz23@penguin:~/holbertonschool-simple_shell$ pwd
/home/juancalpz23/holbertonschool-simple_shell
juancalpz23@penguin:~/holbertonschool-simple_shell$ ./hsh
($) pwd
/home/juancalpz23/holbertonschool-simple_shell
($)exit
juancalpz23@penguin:~/holbertonschool-simple_shell$
```
```
juancalpz23@penguin:~/holbertonschool-simple_shell$ pwd
/home/juancalpz23/holbertonschool-simple_shell
juancalpz23@penguin:~/holbertonschool-simple_shell$ echo "pwd" | ./hsh
/home/juancalpz23/holbertonschool-simple_shell
juancalpz23@penguin:~/holbertonschool-simple_shell$ 
```

## Resources

 - *[Unix shell](https://en.wikipedia.org/wiki/Unix_shell)*
 - *[Thompson Shell](https://en.wikipedia.org/wiki/Thompson_shell)*
 - *[Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)*
 - *[Everything you need to know to start coding your own shell](https://intranet.hbtn.io/concepts/900)*

## Credits

 - *[Antonio De Jesus Santiago](https://github.com/Antoniofdjs)*
 - *[Juan C Lopez Loyola](https://github.com/juancalpz23)*
 - *[Livan Hernandez Mejias](https://github.com/Livanhernandez)*
