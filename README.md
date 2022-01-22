# get_next_line

school42 project

Subject of this project also located in this repository.

INTRODUCTION:

The purpose of this project is to create program which will read a line from gived file descriptor.

Program reading one line it a time. If it calls in a loop, if will read all file or given number of lines.

It use parameter BUFFER_SIZE, which is a number of bytes which will be reading from file. If it not contain symbol of newline, program will read onew more piece

If it contain more than one newline, it will save extra symbols for the next calling.

Mandatory part for only one file descriptor.

Bonus part for several files. For example, if you can read from the file descriptors 3, 4 and 5, you will be able to read from a different fd per call without losing the reading thread of each
file descriptor or returning a line from another fd. It means that you should be able to call get_next_line() to read from fd 3, then fd 4, then 5, then once again 3, once again 4, and so forth.


USING:

Copy this repository by using command git clone git@github.com:cnearing27/get_next_line.git

cd get_next_line - move into the folder

compile by this way for one given fd: gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

for a few fd: gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils-bonus.c

(Parameter BUFFER_SIZE will be modified if you want)
