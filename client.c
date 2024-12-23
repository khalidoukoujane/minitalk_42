/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:43:31 by khoukouj          #+#    #+#             */
/*   Updated: 2024/12/22 15:23:11 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	parsing_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Try runing: ./%s <server's PID> <message>\n", av[0]);
		return (1);
	}
	if (av[1][i] == '+')
		i++;
	while (av[1][i])
	{
		if (av[1][i] < '0' || av[1][i] > '9')
		{
			ft_printf("Invalid PID\n");
			return (1);
		}
		i++;
	}
	if (av[2][0] == '\0')
		return (1);
	return (0);
}

void	send_chars(int pid, char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (str[i])
	{
		1 && (c = str[i], j = 7);
		while (j >= 0)
		{
			if ((c >> j & 1) == 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					return ;
			}
			if ((c >> j & 1) == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					return ;
			}
			usleep(515);
			j--;
		}
		i++;
	}
}

int	ft_atoi(char *s)
{
	int	pid;
	int	i;

	i = 0;
	pid = 0;
	if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		pid = pid * 10 + (s[i] - '0');
		i++;
	}
	return (pid);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (parsing_args(ac, av))
		return (1);
	pid = ft_atoi(av[1]);
	if (pid == 0)
		return (1);
	if (kill(pid, 0) == -1)
		return (ft_printf("Invalid PID\n"), 1);
	send_chars(pid, av[2]);
	ft_printf("\x1b[32mMessage sent !\x1b[0m\n");
	return (0);
}
