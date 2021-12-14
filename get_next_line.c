#include "get_next_line.h"

char	*ft_reader(int fd, char *buf, t_list x)
{
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		x.buf_count = 0;
		while (x.buf_count < BUFFER_SIZE)
		{
			if (buf[x.buf_count] == '\n')
			{
				x.buf_count++;
				x.line = ft_line_maker(buf, x);
				new_buffer(buf, x);
				return (x.line);
			}
			x.buf_count++;
		}
		x.line = ft_line_maker(buf, x);
		new_buffer(buf, x);
	}
	if (!*x.line)
	{
		free (x.line);
		return (NULL);
	}
	return (x.line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	t_list		x;

	if (fd < 0 || fd > 1024 || read(fd, buf, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	x.line = (char *)malloc(sizeof(char));
	if (!x.line)
		return (NULL);
	x.line[0] = '\0';
	x.buf_count = 0;
	while (x.buf_count < BUFFER_SIZE)
	{
		if (buf[x.buf_count] == '\n')
		{
			x.buf_count++;
			x.line = ft_line_maker(buf, x);
			new_buffer(buf, x);
			return (x.line);
		}
		x.buf_count++;
	}
	x.line = ft_line_maker(buf, x);
	new_buffer(buf, x);
	return (ft_reader(fd, buf, x));
}

// int	main(void)
// {
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("Line 1: %s\n", get_next_line(fd));
// 	printf("Line 2: %s\n", get_next_line(fd));
// 	printf("Line 3: %s\n", get_next_line(fd));
// 	printf("Line 4: %s\n", get_next_line(fd));
// 	printf("Line 5: %s\n", get_next_line(fd));
// 	printf("Line 6: %s\n", get_next_line(fd));
// 	printf("Line 7: %s\n", get_next_line(fd));
// 	printf("Line 8: %s\n", get_next_line(fd));
// 	printf("Line 9: %s\n", get_next_line(fd));
// 	printf("Line 10: %s\n", get_next_line(fd));
// 	printf("Line 11: %s\n", get_next_line(fd));
// 	printf("Line 12: %s\n", get_next_line(fd));
// 	return (0);
// }