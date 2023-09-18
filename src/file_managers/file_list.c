/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:51:46 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/18 15:59:30 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

t_file	*create_new_file_node(void);
char	*create_heredoc(void);
int		heredoc(char *file_name, char *limiter);

void	file_away(t_list **files, t_lexer *operator, t_lexer *word)
{
	t_list	*ptr;
	t_file	*node;

	ptr = ft_calloc(sizeof(t_list), 1);
	node = create_new_file_node();
	if (!node)
		return ;
	node->operator = operator->token;
	if (node->operator > 5 && node->operator != 8)
		node->filename = word->string;
	if (node->operator == 8)
	{
		node->heredoc = true;
		node->filename = create_heredoc();
		node->delimiter = word->string;
	}
	ptr->content = node;
	*(files) = ptr;
}

t_file	*create_new_file_node(void)
{
	t_file	*new_node;

	new_node = ft_calloc(sizeof(t_file), 1);
	if (!new_node)
		return (NULL);
	new_node->delimiter = NULL;
	new_node->fd = 0;
	new_node->filename = NULL;
	new_node->heredoc = false;
	new_node->operator = -1;
	return (new_node);
}

char	*create_heredoc(void)
{
	static int	id;
	char		*filename;
	char		*temp;
	int			file_exists;

	id = 0;
	file_exists = 0;
	filename = NULL;
	while (!file_exists)
	{
		free_string(&filename);
		temp = ft_itoa(id);
		filename = ft_strjoin("heredoc", temp);
		free_string(&temp);
		file_exists = access(filename, F_OK);
		id++;
	}
	return (filename);
}

int	heredoc(char *file_name, char *limiter)
{
	int		fd;
	char	*input;

	input = NULL;
	printf("%s\n", file_name);
	fd = open(file_name, O_RDWR | O_CREAT, 0666);
	while (fd != -1)
	{
		input = get_next_line(STDIN_FILENO);
		if (ft_strncmp(input, limiter, ft_strlen(input) - 1) == 0
			&& ft_strlen(input) == ft_strlen(limiter) + 1)
		{
			free_string(&input);
			break ;
		}
		write(fd, input, ft_strlen(input));
		free_string(&input);
	}
	close(fd);
	return (fd);
}
