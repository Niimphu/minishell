/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:57:14 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/22 14:50:48 by Kekuhne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_quotes(char *str, char qoutes)
{
	int	i;
	int	found_c;

	i = 0;
	found_c = 0;
	while (str[i])
	{
		if (str[i] == qoutes)
			found_c++;
		i++;
	}
	return (found_c);
}

int skip_quotes(char *str)
{
	int	i;
	char c;
	
	i = 1;
	c = str[0];
	while(str[i])
	{
		if (str[i] == c)
			return (i);
		else
			i++;
	}
	perror("Didnt find closing quotes");
	return (0);
}

int	check_quotes(char *str)
{
	int	double_quotes;
	int	single_quotes;

	double_quotes = count_quotes(str, '"');
	single_quotes = count_quotes(str, '\'');
	if (double_quotes == 0 && single_quotes == 0)
		return (1);
	if ((ft_strchr(str, '"') && double_quotes % 2 == 0)
		|| (ft_strchr(str, '\'') && single_quotes % 2 == 0))
		return(1);
	else
		return(0);
}

int	check_token(char c)
{
	if (c == '|')
		return (1);
	if (c == '>')
		return (1);
	if (c == '<')
		return (1);
	return (0);
}

char	*replace_whitespaces(char *str)
{
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	if (check_quotes(str))
	{
		while(str[i])
		{
			if(str[i] == '"' || str[i] == '\'')
				i += skip_quotes(str + i);
			if (str[i] == ' ' || str[i] == '\t')
				str[i] = 26;
			i++;
		}
	}
	else
		return ("Close your quotes brav");
	return (str);
}

int	char_count(char *str, char c)
{
	int	i;
	int	found;
	i = 0;
	found = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			i += skip_quotes(str + i);
		if (str[i] == c)
			found++;
		i++;
	}
	return(found);
}

void	add_new_node(t_lexer **root, t_lexer *new)
{
	t_lexer	*current;

	current = *root;
	while(current->next)
		current = current->next;
	current->next = new;
}

int	count_cmd(char **str)
{
	int	i;

	i = 0;
	while (str[i] && !check_token(str[i][0]))
		i++;
	return (i);
}

t_lexer	*new_node(char **str)
{
	int	i;
	int cmd_count; 
	t_lexer	*node;

	i = -1;
	cmd_count = count_cmd(str);
	node = malloc(sizeof(t_lexer));
	node->cmd = malloc(sizeof(char *) * cmd_count + 1);
	while(++i < cmd_count)
	{
		node->cmd[i] = ft_strdup(str[i]);
		if (node->cmd[i] == NULL)
			return (NULL);
	}
	node->cmd[cmd_count] = NULL;
	if (str[i] && check_token(str[i][0]))
	{
		node->token = ft_strdup(str[i]);
		if (node->token == NULL)
			return(NULL);
	}
	else
		node->token = NULL;
	node->next = NULL;
	return (node);
}

t_lexer	*lexer_list_init(char **str)
{
	int	i;
	t_lexer *root;
	t_lexer *node;

	i = 0;
	root = new_node(str + i);
	i += count_cmd(str + i);
	while(str[i++])
	{
		node = new_node(str + i);
		if (node == NULL)
			return (NULL);
		add_new_node(&root, node);
		i += count_cmd(str + i);
		
	}
	return (root);
}

void	lexer(t_lexer *input, t_envp *tools)
{
	int i;
	int j;
	char **split_str;
	
	i = 0;
	j = 0;
	input->raw_input = replace_whitespaces(input->raw_input);
	if (!input->raw_input)
		quit(0);
	if (!ft_strncmp(input->raw_input, "", 1))
		return ;
	split_str = ft_split(input->raw_input, 26);
	if (!ft_strncmp(split_str[0], "exit", 4))
		quit(0);
	input = lexer_list_init(split_str);
	tools->lexer_struct = input;
	j = 0;
	expander(&input, tools);
	printf("*printing created linked list now*\n");
	while (input)
	{
		i = 0;
		while (input->cmd[i])
		{
			printf("cmd[%d] of %d note is : %s\n", i, j, input->cmd[i]);
			i++;
		}
		printf("token of %d note is : %s\n", j ,  input->token);
		j++;
		input = input->next;
	}
}
