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
	while (count1 < buf_count) //(count1 <= buf_count): If you want to print the newline (\n) aswell
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
		return (NULL);
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
