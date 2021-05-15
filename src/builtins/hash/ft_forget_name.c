/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forget_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:59:49 by mobounya          #+#    #+#             */
/*   Updated: 2021/04/28 13:57:01 by mobounya         ###   ########.fr       */
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

void	ft_forget_names(char **names)
{
	unsigned int		i;

	i = 0;
	while (names[i])
	{
		if (ft_forget_name(names[i]))
		{
			ft_putstr_fd("42sh: hash: ", 2);
			ft_putstr_fd(names[i], 2);
			ft_putendl_fd(": not found", 2);
		}
		i++;
	}
}
