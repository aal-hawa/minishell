/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:12:57 by aal-hawa          #+#    #+#             */
/*   Updated: 2025/01/11 14:20:43 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	order_commands(t_precedence *precedence, t_command *commands)
{
	t_command *new_commands;
	int	i;
	int	order_precedence;

	order_precedence = 50;
	i = 0;
	new_commands = malloc(sizeof(t_command) * 100);
	
	while(commands[i].order_precedence < order_precedence)
	{
		order_precedence = commands[i].order_precedence;
		i++;
	}
}

t_command *sentence_division(char **split, t_precedence *precedence)
{
	int	i;
	int	j;
	int	x;
	char **order_str;
	t_command *commands;

	i = 0;
	x = 0;
	commands = malloc(sizeof(t_command) * 100);
	if (!commands)
		return (NULL);
	while (split[i])
	{
		j = 0;
		while (precedence->precedence[j])
		{
			if (split[i] == precedence->precedence[j])
			{
				commands[x].order_precedence = j;
				commands[x].order_sentence = x;
				commands[x].cmd = ft_strjoin(split[i - 1], split[i + 1]);
				x++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (commands);
}

int	readline_func(t_precedence *precedence)
{
	char	*input_data;
	char	**split;
	t_command *commands;
	
	while (1)
	{
		input_data = readline("miniShell> ");
		add_history(input_data);
		split = ft_split(input_data, ' ');
		commands = sentence_division(split,  precedence);
		printf("your input is: %s\n", input_data);
		free(input_data);
		input_data = NULL;
		free(commands);
		commands = NULL;
	}
	return (0);
}

void	init_precedence(t_precedence *precedence)
{
	precedence->precedence[0] = "()";
	precedence->precedence[1] = ">";
	precedence->precedence[2] = ">>";
	precedence->precedence[3] = "<";
	precedence->precedence[4] = "2>";
	precedence->precedence[5] = "|";
	precedence->precedence[6] = "&&";
	precedence->precedence[7] = "||";
	precedence->precedence[8] = ";";
	precedence->precedence[9] = "&";
	precedence->precedence[10] = "\0";
	
}
void	init_info(t_info *info)
{
	
}




int	main() //int ac, char **arg
{
	t_info	info;
	
	init_info(&info);
	readline_func(&info);
	return (0);
}
