/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:13:10 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/13 20:40:48 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*expand_var(char *str, t_god *god_struct);
char	*set_var(char *str, t_god *god_struct, int n);
char	*insert_sub(char *str);
int		strlen_to_char(char *str, char c);

char	**expander(char **split_str, t_god *god_struct)
{
	int	i;
	
	i = 0;
	while (split_str[i])
	{
		if (ft_strchr(split_str[i], '$'))
			split_str[i] = expand_var(split_str[i], god_struct);
		i++;
	}
	return (split_str);
}

int	strlen_to_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	printf("first '=' in str: %s is %d\n", str, i);
	return (i);
}

char	*expand_var(char *str, t_god *god_struct)
{
	int		i;

	i = 0;
	while (god_struct->env[i])
	{
		if (ft_strnstr(god_struct->env[i], str, strlen_to_char(god_struct->env[i], '=')))
			str = set_var(str, god_struct, count_char(str, '$'));
		i++;
	}
	return (str);
}

char	*set_var(char *str, t_god *god_struct, int n)
{
	int		i;
	int		j;
	char	*tmp;
	char	*var;

	i = 0;
	while (n > 0)
	{
		i = strlen_to_char(str, '$');
		tmp = ft_substr(str, 0, i);
		var = get_var(str + i, god_struct);
		tmp = ft_strjoin(tmp, var);
		free (var);
		n--;
	}
	return (free(str), tmp);
}
