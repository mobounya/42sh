/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type_options.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:51:22 by mobounya          #+#    #+#             */
/*   Updated: 2021/04/29 13:53:11 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_parse_type_options(char *value, unsigned int *flag)
{
	unsigned int	i;

	i = 0;
	if (value && value[i] == '-')
		i++;
	while (value[i])
	{
		if (value[i] == 'a')
			*flag |= 1 << LOW_A_FLAG;
		else if (value[i] == 'f')
			*flag |= 1 << LOW_F_FLAG;
		else if (value[i] == 'P')
			*flag |= 1 << UPP_P_FLAG;
		else if (value[i] == 'p')
			*flag |= 1 << LOW_P_FLAG;
		else if (value[i] == 't')
			*flag |= 1 << LOW_T_FLAG;
		else
		{
			ft_type_invalid_option(value[i]);
			return (1);
		}
		i++;
	}
	return (0);
}
