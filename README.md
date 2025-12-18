This project
has been created as part of the 42 curriculum by niverdie

GET\_NEXT\_LINE
===============

char
\*get\_next\_line(int
fd);

Description
-----------

The goal of
get\_next\_line is to return the first line it encounter in a text on
the first occurrence, then on the n occurrence, the program should
return the n line, n being the number of time the user call the
function.

The end of a line is
represented by a ‘\n’. The function get\_next\_line take a file
descriptor as parameter.

The challenging part
of the program is that the buffer given can be any size. This mean it
can contain many lines or only a chunk of a line. When the function
return the line it need to store the remaining part of the buffer
when the buffer goes further after the end of newline (\n). The read
function has an in-built index saver which mean we don’t need to
store the index ourselves.

Inscription
-----------

There is three files to be compiled : get\_next\_line.c,
get\_next\_line.h, get\_next\_line\_utils.c.

To compile the project, you need to de-comment the main.

You’ll use cc compilator with the usual flags required by the
subject (-Wall -Wextra - Werror).

To test it, you will need to create a file.txt and give it as
argument in the main.

Ressources
----------

Fichier test :
<https://raw.githubusercontent.com/mxw/grmr/master/src/finaltests/bible.txt>

C\_profiler used : gprof as shown below

Each sample counts as 0.01
seconds.

% cumulative self
self total

time seconds seconds
calls ns/call ns/call name

60.00 0.03 0.03
502914 59.65 59.65 ft\_strlen

20.00 0.04 0.01
201366 49.66 168.97 ft\_strjoin

20.00 0.05 0.01
100182 99.82 99.82 ft\_memmove

0.00 0.05 0.00
203783 0.00 0.00 newline\_finder

0.00 0.05 0.00
100183 0.00 499.09 get\_next\_line

0.00 0.05 0.00
100182 0.00 328.44 final\_line

0.00 0.05 0.00
100182 0.00 159.47 nxt\_buffer