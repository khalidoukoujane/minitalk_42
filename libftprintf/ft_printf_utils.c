/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:58:51 by khoukouj          #+#    #+#             */
/*   Updated: 2024/11/09 09:18:49 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *index)
{
	write(1, &c, 1);
	(*index)++;
}

void	ft_putnbr(int n, int *index)
{
	char	*num;

	num = ft_itoa(n);
	if (!num)
	{
		*index = -1;
		return ;
	}
	ft_putstr(num, index);
	free(num);
}

void	ft_putunbr(unsigned int nbr, int *index)
{
	if (nbr > 9)
		ft_putunbr(nbr / 10, index);
	*index += write(1, &"0123456789"[nbr % 10], 1);
}

void	ft_putstr(char *s, int *index)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		*index += write(1, "(null)", 6);
		return ;
	}
	while (s[i])
	{
		*index += write(1, &s[i], 1);
		i++;
	}
}
