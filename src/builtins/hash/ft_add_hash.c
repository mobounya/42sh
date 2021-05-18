/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:52:15 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/18 14:49:06 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

/*
**	Functions in ft_hash folder for the hash table and builtin hash
*/

void	ft_add_hash(char *binary, char *path, int increment_hits)
{
	t_hash			*hash;
	unsigned long	n_hash;

	n_hash = hash_str(binary) % HASH_SIZE;
	if (g_hash[n_hash])
	{
		free(g_hash[n_hash]->path);
		g_hash[n_hash]->path = ft_strdup(path);
		g_hash[n_hash]->hits = 0;
	}
	else
	{
		hash = ft_new_hash(ft_strdup(binary), ft_strdup(path));
		if (increment_hits)
			hash->hits++;
		g_hash[n_hash] = hash;
	}
}
