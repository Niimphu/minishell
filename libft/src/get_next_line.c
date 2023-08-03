/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:30:29 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/07/30 12:13:55 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_gnl(char *dest, char *src)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!dest)
	{
		dest = malloc(sizeof(char *) * 1);
		dest[0] = '\0';
	}
	if (!dest || !src)
		return (NULL);
	str = malloc(sizeof(char *) * (ft_strlen(dest) + ft_strlen(src)) + 1);
	if (!str)
		return (NULL);
	while (dest[++i])
		str[i] = dest[i];
	while (src[j])
		str[i++] = src[j++];
	str[i] = '\0';
	return (free(dest), str);
}

char	*cleanup(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	new_str = ft_substr(str, (unsigned int)i, (ft_strlen(str) - i));
	return (free(str), new_str);
}

char	*cpy_str(char *src)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (src[0] == '\0')
		return (NULL);
	while (src[len] && src[len] != '\n')
		len++;
	if (src[len] == '\n')
		len++;
	return (ft_substr(src, 0, len));
}

char	*read_fd(int fd, char *str)
{
	char	*buffer;
	int		buf_len;

	buf_len = 1;
	buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(str, '\n') && buf_len != 0)
	{
		buf_len = read(fd, buffer, BUFFER_SIZE);
		if (buf_len == -1)
			return (free(buffer), NULL);
		buffer[buf_len] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*print;

	print = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_fd(fd, str);
	if (!str)
		return (NULL);
	print = cpy_str(str);
	str = cleanup(str);
	return (print);
}
