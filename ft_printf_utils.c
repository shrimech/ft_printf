/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:09:34 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/22 12:00:58 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		ft_putchar(*str);
		str++;
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int		i;
	long	nb;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		i++;
	}
	nb = n;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (i);
}

int	ft_putptr(void *ptr)
{
	int					i;
	unsigned long		addr;

	i = 0;
	addr = (unsigned long)ptr;
	if (addr == 0)
		i += ft_putstr("(nil)");
	else if (addr != 0)
	{
		i += ft_putstr("0x");
		i += ft_putnbr_hex(addr);
	}
	return (i);
}
