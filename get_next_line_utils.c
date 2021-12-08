#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)s + i);
	}
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	length;
	char	*ptr;

	i = 0;
	length = ft_strlen(s1) + 1;
	ptr = (char *)malloc(length * sizeof(char));
	if (ptr == NULL)
		return (0);
	while (i < length)
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}
