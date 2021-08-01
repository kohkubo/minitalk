#include "libex.h"

void	show_unsigned_char_bit(unsigned char x)
{
	int	i;

	printf("%4u  %02x  ", x, x);
	i = 7;
	while (i >= 0)
	{
		printf("%d", (x >> i) & 1);
		i--;
	}
	printf("\n");
}
