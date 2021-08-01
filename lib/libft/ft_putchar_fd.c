#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (write(fd, &uc, 1) == -1)
		return ;
}
