/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:30:06 by khoukouj          #+#    #+#             */
/*   Updated: 2024/11/09 09:21:40 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(ap, s);
	if (write(1, "", 0) == -1)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				break ;
			ft_print_args(ap, s[i], &i, &size);
			if (size == -1)
				return (-1);
		}
		else
			size += write(1, &s[i++], 1);
	}
	return (size);
}
