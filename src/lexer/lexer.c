/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kekuhne <kekuehne@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:57:14 by Kekuhne           #+#    #+#             */
/*   Updated: 2023/08/10 17:12:50 by Kekuhne          ###   ########.fr       */
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

char *replace_whitespaces(char *str)
{
	int		i;

	i = 0;
	if (check_quotes(str))
	{
		while(str[i])
		{
			if(str[i] == '"' || str[i] == '\'')
			{
				i += skip_quotes(str + i);
			}
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
	while (str[i] && str[i][0] != '|')
	{
		printf("str in count cmd is %s\n", str[i]);
		i++;
	}
	printf("here2\n");
	return (i);
}

t_lexer	*new_node(char **str)
{
	int	i;
	int cmd_count; 
	t_lexer	*node;

	i = -1;
	cmd_count = count_cmd(str);
	printf("cmd count =  %d\n", cmd_count);
	node = malloc(sizeof(t_lexer));
	node->cmd = malloc(sizeof(char *) * cmd_count + 1);
	while(++i < cmd_count)
	{
		node->cmd[i] = ft_strdup(str[i]);
		if (node->cmd[i] == NULL)
			return (NULL);
		printf("new_node->cmd[%d] %s\n", i, node->cmd[i]);
	}
	node->cmd[cmd_count] = NULL;
	if (str[i] && str[i][0] == '|')
	{
		node->token = ft_strdup(str[i]);
		printf("token added %s\n", node->token);
		if (node->token == NULL)
			return(NULL);
	}
	else
	{
		node->token = NULL;
		printf("token added (null)\n");
	}
	node->next = NULL;
	return (node);
}

t_lexer	*lexer_list_init(char **str)
{
	int	i;
	t_lexer *root;
	t_lexer *node;

	i = 0;
	printf("counting throught split_str[%d] element\n", i);
	root = new_node(str + i);
	printf("new node added\n");
	while(str[i][0] != '|' && str[i])
		i++;
	while(str[i++])
	{
		printf("counting throught split_str[%d] element\n", i);
		printf("starting here %s\n", str[i]);
		node = new_node(str + i);
		if (node == NULL)
			return (NULL);
		add_new_node(&root, node);
		printf("new node added\n");
		printf("string before count_cmd %s\n", str[i]);
		i += count_cmd(str + i);
		printf("string after count_cmd %s\n", str[i]);
		
	}
	return (root);
}

void	lexer(t_lexer *input)
{
	int i;
	int j;
	char **split_str;
	
	i = 0;
	j = 0;
	input->raw_input = replace_whitespaces(input->raw_input);
	printf("raw string is %s\n", input->raw_input);
	split_str = ft_split(input->raw_input, 26);
	while (split_str[i])
		printf("split_str = '%s'\n", split_str[i++]);
	input = lexer_list_init(split_str);
	j = 0;
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
