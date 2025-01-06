/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:10:27 by khoukouj          #+#    #+#             */
/*   Updated: 2024/12/29 10:14:22 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handler(int signo, siginfo_t *info, void *content)
{
	static char		c;
	static int		move_bit = 7;
	static pid_t	pid;

	(void)content;
	if (info->si_pid != pid)
	{
		move_bit = 7;
		c = 0;
		pid = info->si_pid;
	}
	if (signo == SIGUSR2)
		c |= (1 << move_bit);
	move_bit--;
	if (move_bit < 0)
	{
		ft_printf("%c", c);
		c = 0;
		move_bit = 7;
	}
}

void	sa_setup(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("\x1b[31mError\x1b[0m\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("\x1b[31mError\x1b[0m\n");
}

void	print_banner(pid_t pid)
{
	ft_printf("\n\n%s%s%s", LINE1, LINE2, LINE3);
	ft_printf("\t\t PID: \
	%d\t\x1b[36;4mby: khoukouj\x1b[0m\n\n", pid);
	ft_printf("Printing Area:\n\n");
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	(void)av;
	if (ac != 1)
		return (1);
	pid = getpid();
	print_banner(pid);
	sa_setup();
	while (1)
		pause();
	return (0);
}
