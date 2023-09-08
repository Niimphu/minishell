/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:07:11 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/07 17:41:06 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_string(char **string)
{
	free(*string);
	*string = NULL;
}

void	free_string_array(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i] != NULL)
	{
		printf("freeing %s\n", (*array)[i]);
		free_string(&(*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}
