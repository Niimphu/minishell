/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:51:46 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/09/19 20:17:26 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

static t_file	*create_new_file_node(void);
static char		*create_heredoc(void);

t_parser	*file_away(t_parser *parser_node, t_lexer *current, t_lexer *next)
{
	t_file	*node;

	node = create_new_file_node();
	if (current->token > 5 && current->token != HEREDOC)
	{
		node->filename = ft_strdup(next->string);
		node->operator = current->token;
	}
	if (current->token == HEREDOC)
	{
		node->filename = create_heredoc();
		node->delimiter = ft_strdup(next->string);
		node->operator = HEREDOC;
	}
	if (!parser_node->files)
		parser_node->files = ft_lstnew(node);
	else
		ft_lstadd_back(&parser_node->files, ft_lstnew(node));
	return (parser_node);
}

static t_file	*create_new_file_node(void)
{
	t_file	*new_node;

	new_node = ft_calloc(sizeof(t_file), 1);
	if (!new_node)
		return (NULL);
	new_node->delimiter = NULL;
	new_node->fd = 0;
	new_node->filename = NULL;
	new_node->operator = -1;
	return (new_node);
}

static char	*create_heredoc(void)
{
	static int	id;
	char		*filename;
	char		*temp;
	int			file_exists;

	if (!id)
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

/* 
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
} */
