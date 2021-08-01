#include "libex.h"

void	safe_free(void **p)
{
	free(*p);
	*p = NULL;
}
