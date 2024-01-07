/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:33:01 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/04/13 14:32:09 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  #define BUFFER_SIZE 10

#include "get_next_line.h"

// strjoin:
// joins two strings together as a third new string.
// the function checks whether the line and the buffer exist
// if it exists it will then allocate enough memory for both of them
// then it makes new string called new_line equal to line by iterating through
// it afterwards it does the same with the buffer as long as there
// is no terminating '\0' character or new line '\n' character
// if buffy is at a new line then we have to make sure we copy it
// correctly by also adding a '\n' to our new_line after
// which we end with a terminating character '\0'

static char	*ft_strjoingnl(char *line, char const *buffy)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_line = ft_callocgnl(sizeof(char), (ft_strlengnl(line)
				+ ft_strlengnl(buffy) + 1));
	if (!new_line)
		return (free(line), NULL);
	while (line[i] != '\0')
		new_line[i++] = line[j++];
	j = 0;
	while (buffy[j] != '\n' && buffy[j] != '\0')
		new_line[i++] = buffy[j++];
	if (buffy[j] == '\n')
	{
		new_line[i] = '\n';
		i++;
	}
	free(line);
	return (new_line);
}

// trim_buffy:
// this function itterates through buffy until it either reaches
// a '\n' new line or a '\0' terminating character
// if it is a terminating character then buffy should be
// at the end therefore we are adding a '\0' as well
// if we go out of the while loop because we have a 
// '\n' then we should + once more to add space for the
// '\0' terminating character that comes afterwards
// then we make a buffer[after] which is equal to our
// previous buffer up until it reached the '\0' or '\n'

static void	trim_buffy(char *buffy)
{
	size_t	before;
	size_t	after;

	before = 0;
	after = 0;
	while (buffy[before] != '\n' && buffy[before] != '\0')
		before++;
	if (buffy[before] == '\0')
	{
		buffy[0] = '\0';
		return ;
	}
	before++;
	while (buffy[before])
	{
		buffy[after] = buffy[before];
		after++;
		before++;
	}
	buffy[after] = '\0';
}

// trim_malloc:
// this functions is similar to trim buffy but it trims
// malloc instead to make sure that you don't allocate too
// much memory which can lead to memory leaks
// this is done by allocating space for the length of the line
// and making extra space for the terminating character '\0'
// then we say that the char result is equal to the line
// and finally add the terminating '\0' character

static char	*trim_malloc(char *line)
{
	char	*result;
	int		length;
	int		i;
	int		j;

	i = 0;
	j = 0;
	length = ft_strlengnl(line);
	result = ft_callocgnl(sizeof(char), (length + 1));
	if (!result)
		return (free(line), NULL);
	while (line[j])
	{
		result[i] = line[j];
		i++;
		j++;
	}
	free(line);
	return (result);
}

// line_ongoing:
// we will go into the while loop as long as buffy
// is not at a "\n" newline, then it reads and checks
// whether read is not negative or empty, frees and returns
// then we add a "\0" terminating character and join the strings
// if what we read is smaller than buffer size we break out of it
// if there is no line then we return NULL

static char	*line_ongoing(char *line, char *buffy, int fd)
{
	int	is_read;

	while (checkchar(buffy) != 1 && line)
	{
		if (*buffy != '\0')
			line = ft_strjoingnl(line, buffy);
		if (!line)
			return (NULL);
		is_read = read(fd, buffy, BUFFER_SIZE);
		if (is_read == -1 || (is_read == 0 && *line == '\0'))
		{
			buffy[0] = '\0';
			free(line);
			return (NULL);
		}
		buffy [is_read] = '\0';
		if (is_read < BUFFER_SIZE)
			break ;
	}
	line = ft_strjoingnl(line, buffy);
	return (line);
}

// get_next_line:
// this function allocates space for our BUFFER_SIZE
// if calls line_ongoing which reads and fills line
// as long as it is not at a "\n" new line
// otherwise it calls trim buffy and trim malloc
// which makes sure that there is not too much space
// allocated and we don't have any leaks

char	*get_next_line(int fd)
{
	static char	buffy[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0)
		return (NULL);
	line = ft_callocgnl(sizeof(BUFFER_SIZE + 1), 1);
	if (!line)
		return (NULL);
	line = line_ongoing(line, buffy, fd);
	if (!line)
	{
		buffy[0] = '\0';
		return (NULL);
	}
	trim_buffy(buffy);
	line = trim_malloc(line);
	if (!line)
		buffy[0] = '\0';
	return (line);
}

// int	main(void)
// {
// 	char *line;
// 	int fd;

// 	fd = open("text.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while(line)
// 	{
// 		printf("%s", line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }