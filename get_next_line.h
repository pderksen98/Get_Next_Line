#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	char	*line;
	char	*newline;
	int		line_count;
	int		buf_count;
}	t_list;

char	*ft_reader(int fd, char *buf, t_list x);
char	*get_next_line(int fd);
char	*ft_line_add_buf(char *buf, t_list x);
char	*ft_line_maker(char *buf, t_list x);
void	new_buffer(char *buf, t_list x);
#endif
