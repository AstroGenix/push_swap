/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:18:05 by dberehov          #+#    #+#             */
/*   Updated: 2022/12/05 18:18:06 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Repeated calls (ex, using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.

• Your function should return the line that was read.
If there is nothing to read or if an error occurred, it should return NULL.

• Make sure that your function works as expected both when reading a file and
when reading from the standard input.

• Please note that the returned line should include the \n character,
except if the end of file was reached and does not end with a \n character.

• Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.

• Add all the helper functions you need in the get_next_line_utils.c file.

• Because you will have to read files in get_next_line(), add this option to
your compiler call: -D BUFFER_SIZE=n
It will define the buffer size for read().
The buffer size value will be modified by your peer-evaluators and the
Moulinette in order to test your code.

• Compile your code as follows (a buffer size of 42 is used as an example):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

• We consider that get_next_line() has an undefined behavior if the file
pointed to by the file descriptor changed since the last call whereas read()
didn’t reach the end of file.

• We also consider that get_next_line() has an undefined behavior when reading
a binary file. However, you can implement a logical way to handle this
behavior if you want to.
_______________________________________________________________________________
Function Name | get_next_line
Prototype     | char *get_next_line(int_fd);
Turn in files | get_next_line.c, get_next_line_utils.c, get_next_line.h
Parameters    | fd: The file descriptor to read from
Return Value  | Read line: correct behavior
              | NULL: there is nothing else to read, or an error
			  | occurred
External func.| read, malloc, free
Description   | Write a function that returns a line read from a file
              | descriptor	
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
- - Forbidden - -
• No use of libft.
• lseek() isn't allowed.
• No global variables are allowed.
*/

#include "../include/push_swap.h"

char	*after_line(char *buffer)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = malloc(sizeof(char) * ((ft_strlen(buffer) - i) + 1));
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	next[j] = '\0';
	free(buffer);
	return (next);
}

char	*write_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*join_free(char *buffer, char *buffer_append)
{
	char	*temp_string;

	temp_string = ft_strjoin(buffer, buffer_append);
	free(buffer);
	return (temp_string);
}

char	*read_line(int fd, char *buffer_output)
{
	char	*text_buffer;
	int		bytes_read;

	if (!buffer_output)
		buffer_output = (char *)ft_calloc(1, sizeof(char));
	text_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!text_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, text_buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && buffer_output == NULL))
		{
			free(buffer_output);
			free(text_buffer);
			return (NULL);
		}
		text_buffer[bytes_read] = '\0';
		buffer_output = join_free(buffer_output, text_buffer);
		if (ft_strchr(text_buffer, '\n'))
			break ;
	}
	free(text_buffer);
	return (buffer_output);
}

char	*get_next_line(int fd)
{
	static char	*buffer_stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_stash = read_line(fd, buffer_stash);
	if (!buffer_stash)
		return (NULL);
	line = write_line(buffer_stash);
	buffer_stash = after_line(buffer_stash);
	return (line);
}

/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	fd1 = open("text/beescript.txt", O_RDONLY);
	i = 1;
	while (i < 17)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	printf("\n");
	close(fd1);
	return (0);
}
*/
