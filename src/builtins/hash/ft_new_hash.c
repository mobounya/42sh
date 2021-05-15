/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:00:04 by mobounya          #+#    #+#             */
/*   Updated: 2021/04/27 16:30:04 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

/*
**	allocate a new t_hash struct
*/

t_hash	*ft_new_hash(char *binary, char *path)
{
	t_hash		*hash;

	hash = ft_memalloc(sizeof(t_hash));
	if (hash == NULL)
		exit(ENOMEM);
	hash->binary = binary;
	hash->path = path;
	hash->hits = 0;
	return (hash);
}
