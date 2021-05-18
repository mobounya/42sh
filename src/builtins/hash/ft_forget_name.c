/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forget_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:59:49 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/18 14:11:04 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

/*
**	Functions for deleting (forgeting) a hashed binary.	
*/

int	ft_forget_name(char *name)
{
	unsigned long	n_hash;

	n_hash = hash_str(name) % HASH_SIZE;
	if (g_hash[n_hash] != NULL)
	{
		ft_memdel((void **)&(g_hash[n_hash]->binary));
		ft_memdel((void **)&(g_hash[n_hash]->path));
		ft_memdel((void **)&g_hash[n_hash]);
		return (0);
	}
	return (1);
}

int	ft_forget_names(char **names)
{
	unsigned int		i;
	int					error;

	i = 0;
	error = 0;
	while (names[i])
	{
		if (ft_forget_name(names[i]))
		{
			error = 1;
			ft_name_not_found(names[i]);
		}
		i++;
	}
	return (error);
}
