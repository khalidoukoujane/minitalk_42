/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:31:28 by khoukouj          #+#    #+#             */
/*   Updated: 2024/11/08 21:43:24 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_print_args(va_list ap, char c, int *index, int *size);
void	ft_putchar(char c, int *index);
void	ft_putnbr(int n, int *index);
void	ft_putstr(char *s, int *index);
char	*ft_itoa(int n);
void	ft_putunbr(unsigned int nbr, int *index);
void	print_upcase_hex(unsigned int nbr, int *size);
void	print_lowcase_hex(unsigned int nbr, int *size);
void	print_address(unsigned long add, int *size);
#endif