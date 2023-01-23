<p align="center">

  <img src="assets/generalbark.png" height="300\"/>

<br>


<h1><p align="center">General Bark - A C based shell</h1></p></font>

# General Bark

General Bark is a shell on top of the Kernal, hence the title general.
Its task is to wrap around the Kernal and make interaction more civil,
hence the name Bark, like the tree bark. The general takes most of the 
basics of commands that are present in the bash shell and communicate 
them to the Kernal in a soldierly manner. This shell is built as an exercies to  
learn C. The initial project was done as a group project and 
was hosted here [here](https://github.com/hileamlakB/simple_shell). 
The group project was  great and I leanred a lot from it. I amm rebuilding
this one again from the in order to learn the other parts of the project
my team mate worked one.

`General` works like the bash and other basic C shells, though it has some 
to be yet build features.

The General can be compiled with GCC >=4.8.5.

## File

## Example of how to launch the shell after compiling:
`./gbk`

* Output: prompt to terminal: `$ `

## Syntax

The shell works by using commands given by the user input. The shell commands 
take in the following syntax: `command name {arguments}[;||&& other command]`. 
The shell executes a command after it is written by user using the command 
followed by the arguments until all the commands in one line are completed

`cat gbk.h`

The above example takes in a command by the user followed with the arguments. 
In this case the command is `cat` (to view file without opening file) followed 
by argument the file name in this case `gbk.h`.

For more information on cat, you can use the `man` command which will show a manual 
of the given command or any command you wish to know more information on.


### Compilation and installation


If you want a controlled install you can clone this repository to your local machine 
and compile all the `c` files using `GCC`, but if you are looking for a binary you can run
the program just like others, such as bash. But depending on your machine the compiled version
might not work so you can compile the program as follows.

First
```
git clone https://github.com/hileamlakB/GBK.git
```
Then
```
cd GBK
```
After this you can use the make file to compile every thing as follows
```
make
```


### Builtins
GBK also contains a couple of built-in functions, which are commands that are within the shell itself. Some of the built-ins are 

|Builtin   | use|
|----------|--------------------------------------------|
|`alias` | to create aliases|
|`help` | to get help on built-in functions |
|`cd` | change working directories|
|`history` | list of commands that have already been typed|
|`env` and `printenv` | prints environmental variables|
|`set` | sets new environmental variables|
|`exit` | exit out of gbk|
|`unset` | unsets envrionmental variables|


### Exiting commands and the shell
To exit out of a command or process the user can't use `ctrl c`. `Control c (SIGINT)` has been overiden to do nothing as in many shells so if one wants to kill a runnign process of GBK they will either have to use the exit command or send a SIGKILL signal from the parent process. 

The user can also utilize the command `ctrl D` which will just exit. When the command `ctrl D` is used an exit status of 0 is given. Using exit, you can input its exit status or it is defaulted to the status of the last command executed.

## Files
* `README.md` : Current file, contains information about this project
* `gbk.h` : Header file, contains all prototypes for funcitons used, as well as libriaries
* `help.h` : Header file, contains all the macros for the help section
* `generalbark.png`: Image in the readme file

### TODO'S

### Comments

### Authors
* Hileamlak*
