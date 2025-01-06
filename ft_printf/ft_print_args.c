/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:47:51 by khoukouj          #+#    #+#             */
/*   Updated: 2024/11/08 14:09:19 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_args(va_list ap, char c, int *index, int *size)
{
	if (*size == -1)
		return ;
	if (c == 'c')
		ft_putchar((char)va_arg(ap, int), size);
	else if (c == 'd' || c == 'i')
		ft_putnbr((int)va_arg(ap, int), size);
	else if (c == 's')
		ft_putstr((char *)va_arg(ap, char *), size);
	else if (c == 'u')
		ft_putunbr((unsigned int)va_arg(ap, unsigned int), size);
	else if (c == 'p')
		print_address((unsigned long)va_arg(ap, unsigned long), size);
	else if (c == 'x')
		print_lowcase_hex((long)va_arg(ap, long), size);
	else if (c == 'X')
		print_upcase_hex((long)va_arg(ap, long), size);
	else if (c == '%')
		ft_putchar('%', size);
	else
		write(1, &c, 1);
	(*index)++;
}
