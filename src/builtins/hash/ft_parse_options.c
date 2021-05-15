/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:05:18 by mobounya          #+#    #+#             */
/*   Updated: 2021/04/28 15:52:21 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	ft_set_flags(char *options, int *flag)
{
	unsigned int	i;

	i = 1;
	while (options[i])
	{
		if (options[i] == 'd')
			*flag |= 1 << LOW_D_FLAG;
		else if (options[i] == 'l')
			*flag |= 1 << LOW_L_FLAG;
		else if (options[i] == 'p')
			*flag |= 1 << LOW_P_FLAG;
		else if (options[i] == 'r')
			*flag |= 1 << LOW_R_FLAG;
		else if (options[i] == 't')
			*flag |= 1 << LOW_T_FLAG;
		else
		{
			*flag = -1;
			break ;
		}
		i++;
	}
}

char	**ft_parse_options(char **command, int *flag)
{
	unsigned int	i;

	i = 0;
	while (command[i] && command[i][0] == '-')
	{
		if (ft_strcmp(command[i], "--") == 0)
		{
			i++;
			break ;
		}
		else
			ft_set_flags(command[i], flag);
		if (*flag == -1)
		{
			ft_hash_flag_error(command[i]);
			return (NULL);
		}
		i++;
	}
	return (command + i);
}
