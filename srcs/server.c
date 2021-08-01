#include "minitalk.h"

static void	print_pid(char *s)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd(s, 1);
	ft_putstr_fd(" : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

static int	receipt_completed(unsigned char *buf, int index, siginfo_t *info)
{
	ft_putendl_fd((char *)buf, 1);
	ft_bzero(buf, index);
	kill(info->si_pid, SIGUSR2);
	return (0);
}

static void	server_handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	buf[BUFSIZE];
	static int				index;
	static int				i;
	static unsigned char	uc;

	(void)ucontext;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR2)
			uc |= (1 << i);
		i++;
	}
	if (i == 8)
	{
		if (index > BUFSIZE - 1)
			ft_error_exit("server: buffer overflow");
		if (uc == 0)
			index = receipt_completed(buf, index, info);
		else
			buf[index++] = uc;
		i = 0;
		uc = 0;
	}
}

int	main(void)
{
	print_pid("server pid");
	receiver(server_handler);
	while (1)
		;
	return (0);
}
