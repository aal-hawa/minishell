/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:12:57 by aal-hawa          #+#    #+#             */
/*   Updated: 2025/01/09 16:57:31 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sentence_division(char **str, t_info *info)
{
	
}

int	readline_func(t_info *info)
{
	char	*input_data;
	char	**splt;

	while (1)
	{
		input_data = readline("miniShell> ");
		add_history(input_data);
		splt = ft_split(input_data, ' ');

		printf("your input is: %s\n", input_data);
		free(input_data);
		input_data = NULL;
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
