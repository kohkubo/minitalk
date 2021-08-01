#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <errno.h>
# include <sys/types.h>
# include "../lib/libex/libex.h"
# include "../lib/libft/libft.h"
# define BUFSIZE 10001

void	receiver(void handler(int, siginfo_t *, void *));

#endif
