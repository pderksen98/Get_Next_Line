#ifndef FT_GET_NEXT_LINE
# define FT_GET_NEXT_LINE
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);
int		main(void);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

#endif
