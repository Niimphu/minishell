/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kekuhne <kekuhne@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:42:54 by kekuhne           #+#    #+#             */
/*   Updated: 2023/01/18 00:11:31 by kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *format, ...)
{
	size_t	len;
	va_list	args;

	len = 0;
	va_start (args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += sort_arg(*format, args);
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
			len++;
		}
	}
	va_end (args);
	return ((int)len);
}
