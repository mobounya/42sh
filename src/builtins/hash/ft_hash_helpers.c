/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:54:26 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/18 16:03:15 by mobounya         ###   ########.fr       */
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

int	ft_hash_names(char **names)
{
	unsigned int	i;
	char			*path;
	int				error;

	i = 0;
	error = 0;
	while (names[i])
	{
		if (!check_builtins(names[i]))
		{
			path = try_every_possibility(names[i], \
				env_get(g_shell_env, "PATH"));
			if (ft_strequ(path, names[i]))
			{
				error = 1;
				ft_name_not_found(names[i]);
			}
			else
				ft_add_hash(names[i], path, 0);
			free(path);
		}
		i++;
	}
	return (error);
}

char	*ft_get_hash(char *bin)
{
	unsigned int	i;
	unsigned int	n_hash;

	i = 0;
	n_hash = hash_str(bin) % HASH_SIZE;
	if (g_hash[n_hash] == NULL)
		return (NULL);
	else
	{
		g_hash[n_hash]->hits++;
		return (g_hash[n_hash]->path);
	}
}
