/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:47:49 by kekuhne           #+#    #+#             */
/*   Updated: 2023/02/15 18:44:27 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	sort_hex(char c, va_list args)
{
	unsigned int	hex;

	if (c == 'x' || c == 'X')
	{
		hex = va_arg(args, unsigned long);
		if (hex == 0)
		{
			ft_putchar_fd('0', 1);
			return (1);
		}
		if (c == 'x')
			return (arg_hex(hex));
		else
			return (arg_hex_upper(hex));
	}
	if (c == 'p')
		return (arg_pointer(args));
	return (0);
}

size_t	arg_pointer(va_list args)
{
	unsigned long	hex;

	hex = va_arg(args, unsigned long long);
	if (hex == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	return (arg_hex(hex) + 2);
}

size_t	sort_arg(char c, va_list args)
{
	size_t				arg_len;

	arg_len = 0;
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (c == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		return (1);
	}
	if (c == 's')
		return (arg_str((char *)va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (arg_digit((size_t)va_arg(args, int)));
	if (c == 'u')
		return (arg_unsigned_digit(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X' || c == 'p')
		return (sort_hex(c, args));
	if (c == 'p')
		return (arg_pointer(args));
	return (arg_len);
}
