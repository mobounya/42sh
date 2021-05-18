/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:34:10 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/18 15:53:48 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	ft_free_hash(t_hash *hash[])
{
	unsigned int	i;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (hash[i])
		{
			ft_strdel(&(hash[i]->path));
			ft_strdel(&(hash[i]->binary));
			ft_memdel((void **)(hash + i));
		}
		i++;
	}
}
