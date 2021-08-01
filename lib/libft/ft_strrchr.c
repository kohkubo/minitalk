#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*e;

	if (c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	e = s + ft_strlen(s);
	while (1)
	{
		if (--e < s)
			break ;
		if ((unsigned char)*e == (unsigned char)c)
			return ((char *)e);
	}
	return (NULL);
}
