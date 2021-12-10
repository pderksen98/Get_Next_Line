#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_reader(int fd, char *buf, char *line);
char	*get_next_line(int fd);
char	*ft_line_add_buf(char *line, char *buf, char *newline, int line_count, int buf_count);
char	*ft_line_maker(char *line, char *buf, int buf_count);
void	new_buffer(char *buf, int buf_count);
#endif
