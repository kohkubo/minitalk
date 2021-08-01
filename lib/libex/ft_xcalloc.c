#include "libex.h"

static void	ft_fatalx(const char *emsg)
{
	errno = 0;
	ft_fatal(emsg);
}

void	*ft_xcalloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		ft_fatalx("xcalloc: zero size");
	ptr = malloc(size);
	if (ptr == NULL)
		ft_fatal("xcalloc: ");
	ft_bzero(ptr, size);
	return (ptr);
}
