/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:09:34 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/15 11:09:40 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putnbr_hex(unsigned int n)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16);
	ft_putchar("0123456789abcdef"[n % 16]);
}

void	ft_putnbr_hex_upper(unsigned int n)
{
	if (n >= 16)
		ft_putnbr_hex_upper(n / 16);
	ft_putchar("0123456789ABCDEF"[n % 16]);
}

void	ft_putptr(void *ptr)
{
	unsigned long addr = (unsigned long)ptr;
	ft_putstr("0x");
	if (addr == 0)
		ft_putstr("0");
	else
		ft_putnbr_hex(addr);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			ft_putnbr(va_arg(args, int));
			count++;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			ft_putstr(va_arg(args, char *));
			count++;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			ft_putchar((char)va_arg(args, int));
			count++;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'p')
		{
			ft_putptr(va_arg(args, void *));
			count++;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'u')
		{
			ft_putnbr_unsigned(va_arg(args, unsigned int));
			count++;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'x')
		{
			ft_putnbr_hex(va_arg(args, unsigned int));
			count++;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'X')
		{
			ft_putnbr_hex_upper(va_arg(args, unsigned int));
			count++;
			i += 2;
		}
		else
		{
			ft_putchar(format[i]);
			count++;
			i++;
		}
	}

	va_end(args);
	return (count);
}

#include <stdio.h>
int main()
{
	ft_printf("how many %s in the cluster : %d\nsalaaaaah", "salah", 1);
}
