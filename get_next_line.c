#include "get_next_line.h"

char	*ft_reader(int fd, char *buf, char *line)
{
	int	buf_count;

	buf_count = 0;
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		printf("buffertje lekker: %s\n", buf);
		buf_count = 0;
		while (buf_count < BUFFER_SIZE)
		{
			if (buf[buf_count] == '\n')
			{
				printf("buf2: %s\n", buf);
				printf("buf_count2: %d\n", buf_count);
				line = ft_line_maker(line, buf, buf_count);
				new_buffer(buf, buf_count);
				return (line);
			}
			buf_count++;
		}
		printf("buf1: %s\n", buf);
		printf("buf_count1: %d\n", buf_count);
		line = ft_line_maker(line, buf, buf_count);
		// new_buffer(buf, buf_count);
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
	printf("buf: %s\n", buf);
	printf("buf_count: %d\n", buf_count);
	line = ft_line_maker(line, buf, buf_count);
	return (ft_reader(fd, buf, line));
}

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf("Line 1: %s", get_next_line(fd));
	printf("Line 2: %s", get_next_line(fd));
	printf("Line 3: %s", get_next_line(fd));
	printf("Line 4: %s", get_next_line(fd));
	// printf("Line 5: %s\n", get_next_line(fd));
	// printf("Line 6: %s\n", get_next_line(fd));
	// printf("Line 7: %s\n", get_next_line(fd));
	// printf("Line 8: %s\n", get_next_line(fd));
	// printf("Line 9: %s\n", get_next_line(fd));
	// printf("Line 10: %s\n", get_next_line(fd));
	return (0);
}
