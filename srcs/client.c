#include "minitalk.h"

static void	send_char(pid_t pid, char c)
{
	int				bit;
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (i < 8)
	{
		usleep(50);
		bit = (uc >> i) & 0x01;
		if (kill(pid, SIGUSR1 + bit) == -1)
			ft_error_exit("kill error");
		i++;
	}
}

static void	send_string(pid_t pid, char *str)
{
	if (ft_strlen(str) > BUFSIZE - 1)
		ft_error_exit("string is too long");
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\0');
}

static void	client_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (sig == SIGUSR2)
		ft_putendl_fd("Successfull", 1);
	exit(0);
}

static void	client(char **av)
{
	pid_t	pid;

	pid = (pid_t)ft_atoi(av[1]);
	if (pid < 1 || !is_available_pid(pid))
		ft_error_exit("pid error");
	receiver(client_handler);
	send_string(pid, av[2]);
	if (!sleep(5))
		ft_error_exit("time out");
}

int	main(int ac, char **av)
{
	if (ac != 3)
		ft_error_exit("Usage: %s <pid> <str>");
	client(av);
	return (0);
}
