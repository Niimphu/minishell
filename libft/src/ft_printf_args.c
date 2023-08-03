/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:24:52 by kekuhne           #+#    #+#             */
/*   Updated: 2023/07/10 14:31:03 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	arg_str(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

size_t	arg_digit(int n)
{
	size_t	i;

	i = 0;
	ft_putnbr_fd(n, 1);
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	while (n != 0)
	{
		if (n < 0)
		{
			n = n * -1;
			i++;
		}
		n = n / 10;
		i++;
	}
	return (i);
}

size_t	arg_unsigned_digit(unsigned int n)
{
	size_t	i;

	i = 0;
	ft_unsigend_putnbr_fd(n, 1);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

size_t	arg_hex(unsigned long long nb)
{
	static int			i;
	char				rem;

	i = 0;
	if (nb != 0)
	{
		arg_hex(nb / 16);
		if (nb % 16 < 10)
			rem = nb % 16 + '0';
		else
			rem = nb % 16 + 87;
		ft_putchar_fd(rem, 1);
		i++;
	}
	return (i);
}

size_t	arg_hex_upper(unsigned long long nb)
{
	static int		i;
	char			rem;

	i = 0;
	if (nb != 0)
	{
		arg_hex_upper(nb / 16);
		if (nb % 16 < 10)
			rem = nb % 16 + '0';
		else
			rem = nb % 16 + 55;
		ft_putchar_fd(rem, 1);
		i++;
	}
	return (i);
}
