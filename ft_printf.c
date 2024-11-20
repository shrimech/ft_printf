/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:09:34 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/15 11:36:33 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long n)
{
	int i;

	i = 0;
	if (n >= 16)
		ft_putnbr_hex(n / 16);
	i += ft_putchar("0123456789abcdef"[n % 16]);
	return (i);
}

int	ft_putnbr_hex_upper(unsigned int n)
{
	int i;

	i = 0;
	if (n >= 16)
		ft_putnbr_hex_upper(n / 16);
	i += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (i);
}

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int i;

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
			count += ft_putnbr(va_arg(args, int));
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			count += ft_putstr(va_arg(args, char *));
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			count += ft_putchar((char)va_arg(args, int));
			i+=2;
		}
		else if (format[i] == '%' && format[i + 1] == 'p')
		{
			count += ft_putptr(va_arg(args, void *));
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'u')
		{
			count += ft_putnbr(va_arg(args, unsigned int));
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'x')
		{
			count += ft_putnbr_hex(va_arg(args, unsigned int));
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'X')
		{
			count += ft_putnbr_hex_upper(va_arg(args, unsigned int));
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			count += ft_putchar('%');
			i += 2;
		}
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
int main()
{
	char *a = "abc";
//	int c = ft_printf("%%\n", NULL);
	int b = printf("%x\n" , NULL);
//	printf("%d\n%d\n", c, b);
}*/
