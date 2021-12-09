#include "get_next_line.h"

//adds buffer to the existing line and returns this newline
char	*ft_line_add_buf(char *line, char *buf, char *newline, int line_count, int buf_count)
{
	int	count;
	int	count1;

	count = 0;
	while (count < line_count)
	{
		newline[count] = line[count];
		count++;
	}
	count1 = 0;
	while (count1 < buf_count)
	{
		newline[count] = buf[count1];
		count++;
		count1++;
	}
	newline[count] = '\0';
	return (newline);
}

//allocates memmory for the newline, makes the newline and frees the 'old' line
char	*ft_line_maker(char *line, char *buf, int buf_count)
{
	int		line_count;
	char	*newline;

	line_count = 0;
	while (line[line_count])
		line_count++;
	newline = (char *)malloc((line_count + buf_count + 1) * sizeof(char));
	if (!newline)
		return(NULL);
	newline = (ft_line_add_buf(line, buf, newline, line_count, buf_count));
	free (line);
	return (newline);
}

void	new_buffer(char *buf, int buf_count)
{
	int	i;

	i = 0;
	while (buf_count < BUFFER_SIZE)
	{
		buf_count++;
		buf[i] = buf[buf_count];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
}

char	*ft_reader(int fd, char *buf, char *line)
{
	int	buf_count;

	buf_count = 0;
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf_count = 0;
		while (buf_count < BUFFER_SIZE)
		{
			if (buf[buf_count] == '\n')
			{
				line = ft_line_maker(line, buf, buf_count);
				new_buffer(buf, buf_count);
				return (line);
			}
			buf_count++;
		}
		line = ft_line_maker(line, buf, buf_count);
		new_buffer(buf, buf_count);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE];
	char			*line;
	int				buf_count;

	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[0] = '\0';
	buf_count = 0;
	while (buf_count < BUFFER_SIZE)
	{
		if (buf[buf_count] == '\n')
		{
			line = ft_line_maker(line, buf, buf_count);
			new_buffer(buf, buf_count);
			return (line);
		}
		buf_count++;
	}
	line = ft_line_maker(line, buf, buf_count);
	return (ft_reader(fd, buf, line));
}

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf("Line 1: %s\n", get_next_line(fd));
	printf("Line 2: %s\n", get_next_line(fd));
	printf("Line 3: %s\n", get_next_line(fd));
	printf("Line 4: %s\n", get_next_line(fd));
	printf("Line 5: %s\n", get_next_line(fd));
	printf("Line 6: %s\n", get_next_line(fd));
	printf("Line 7: %s\n", get_next_line(fd));
	printf("Line 8: %s\n", get_next_line(fd));
	printf("Line 9: %s\n", get_next_line(fd));
	printf("Line 10: %s\n", get_next_line(fd));
	return (0);
}
