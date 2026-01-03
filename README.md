*This project has been created as part of the 42 curriculum by niverdie*

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

Instructions
-----------

There is three files to be compiled : get\_next\_line.c,
get\_next\_line.h, get\_next\_line\_utils.c.

To compile the project, you need to de-comment the main.

You’ll use cc compilator with the usual flags required by the
subject (-Wall -Wextra - Werror).

To test it, you will need to create a file.txt and give it as
argument in the main.

Algorithm
-----------
```ruby

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			readbyte;
	int			i;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0) # security to avoid reading compromised file or if Buffer size is negative
		return (NULL);
	readbyte = 1; # setting readbyte at 1 for the first run to enter the while condition later
	while (readbyte > 0) # if readbyte egal 0 it mean we read the whole file so the program can terminate
	{
		i = 0;
		if (newline_finder(buffer, &i) != -1) # if this function find a newline we enter the condition
			return (final_line(line, buffer, i)); # newline found, meaning we can return the line
		if (buffer[0] != '\0') # if buffer is not empty 
			line = ft_strjoin(line, buffer); #join line (old buffer) and buffer  (the actual one)
		readbyte = read(fd, buffer, BUFFER_SIZE); # the function read fill the buffer 
		buffer[readbyte] = '\0'; # we put a '\0' at the end of readbyte in case readbyte < BUFFER_SIZE 
		if (readbyte < 0) #if readbyte didn't worked
			return (ft_free(line)); #free the malloc 
		if (readbyte == 0) #if there is nothing else to read 
			return (line); #return the last line
	}
	return (NULL); #if all conditions before are not filled we must return NULL 
}

```

Ressources
----------

Fichier test :
<https://raw.githubusercontent.com/mxw/grmr/master/src/finaltests/bible.txt>

C\_profiler used : gprof 