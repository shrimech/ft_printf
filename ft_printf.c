/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:09:34 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/22 12:05:34 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_putnbr_hex(n / 16);
	i += ft_putchar("0123456789abcdef"[n % 16]);
	return (i);
}

int	ft_putnbr_hex_upper(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_putnbr_hex_upper(n / 16);
	i += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (i);
}

int	ft_printf_data(char str, va_list ap)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (str == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if ((str == 'd') || (str == 'i'))
		count += ft_putnbr(va_arg(ap, int));
	else if (str == 'u')
		count += ft_putnbr(va_arg(ap, unsigned int));
	else if (str == 'x')
		count += ft_putnbr_hex(va_arg(ap, unsigned int));
	else if (str == 'X')
		count += ft_putnbr_hex_upper(va_arg(ap, unsigned int));
	else if (str == 'p')
		count += ft_putptr(va_arg(ap, void *));
	if (str == '%')
		count += ft_putchar(str);
	return (count);
}

int	check_last(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == '%' && str[i - 2] != '%')
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	if (check_last(format) == 1)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_printf_data(format[i], ap);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
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
// }*/
// #include "ft_printf.h"

// int main()
// {
// 	char *c = "salah";
// 	int a = ft_printf("%p--%s--%d--%i--%c--%u--%x--%X--%%--\n",c,c,c,c,c,c,c,c,c);
// 	int b = ft_printf("%p--%s--%d--%i--%c--%u--%x--%X--%%--\n",c,c,c,c,c,c,c,c,c);
// 	ft_printf("%d    %d\n",a, b);
// =	// printf("%d\n",b);
// }
