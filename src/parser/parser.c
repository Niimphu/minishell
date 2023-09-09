/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:16:08 by yiwong            #+#    #+#             */
/*   Updated: 2023/09/08 15:07:49 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// check for double or beginning operator
// handle oe or more heredoc
// input output files
// git branch -a 

void	parse(char *input, t_god *god_struct)
{
	t_list	*parsed_list;
	char	**split_str;

	input = lex(input);
	if (!input)
		return ;
	if (!ft_strncmp(input, "", 1))
		return ;
	split_str = ft_split(input, 26);
	parsed_list = create_parser_list(split_str);
	god_struct->parser_list = parsed_list;
	expander(&parsed_list, god_struct);
	print_parser_list(god_struct->parser_list);
}

void	print_parser_list(t_list *parsed_list)
{
	t_parser	*node;
	int			i;
	int			j;

	printf("\n=== Parser linked list ===\n\n");
	j = 0;
	while (parsed_list)
	{
		i = 0;
		node = (t_parser *)parsed_list->content;
		while (node->cmd[i])
		{
			printf("cmd[%d] of node %d is : %s\n", i, j, node->cmd[i]);
			i++;
		}
		printf("command line operator ID of node %d is: %i\n",
			j, node->operator);
		printf("this node is%s an outfile\n\n", node->outfile ? "" : " not");
		j++;
		parsed_list = parsed_list->next;
	}
	printf("===    End of list     ===\n\n");
}
