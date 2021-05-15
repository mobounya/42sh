/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:54:26 by mobounya          #+#    #+#             */
/*   Updated: 2021/04/28 15:45:10 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

/*
**	Get the number of allocated pointers in the g_hash array
*/

size_t	ft_get_hash_size(void)
{
	size_t			size;
	unsigned int	i;

	size = 0;
	i = 0;
	while (i < HASH_SIZE)
	{
		if (g_hash[i] != NULL)
			size++;
		i++;
	}
	return (size);
}

void	ft_empty_hash(void)
{
	unsigned int		i;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (g_hash[i])
		{
			ft_memdel((void **)&g_hash[i]->binary);
			ft_memdel((void **)&g_hash[i]->path);
			ft_memdel((void **)&g_hash[i]);
		}
		i++;
	}
}

char	*ft_get_location(char *name)
{
	unsigned long	n_hash;

	n_hash = hash_str(name) % HASH_SIZE;
	if (g_hash[n_hash])
		return (g_hash[n_hash]->path);
	else
		return (NULL);
}

void	ft_hash_names(char **names)
{
	unsigned int	i;
	unsigned long	n_hash;
	char			*path;

	i = 0;
	while (names[i])
	{
		ft_forget_name(names[i]);
		path = ft_find_executable(names[i]);
		if (path == NULL)
		{
			g_exit_code = 0;
			ft_putstr_fd("42sh: hash: ", 2);
			ft_putstr_fd(names[i], 2);
			ft_putendl_fd(": not found", 2);
		}
		else
		{
			n_hash = hash_str(names[i]) % HASH_SIZE;
			g_hash[n_hash] = ft_new_hash(ft_strdup(names[i]), path);
		}
		i++;
	}
}
