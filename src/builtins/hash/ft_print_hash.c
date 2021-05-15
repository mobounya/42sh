/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:08:30 by mobounya          #+#    #+#             */
/*   Updated: 2021/04/28 16:06:00 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

/*
**  Print hash output in the default format [DEFAULT_FORMAT], e.g. :
**  hits    command
**   1      /path/to/bin
*/

void	ft_print_default_output(uint hits, char *location)
{
	ft_putnbr(hits);
	ft_putstr("    ");
	ft_putendl(location);
}

/*
**  Print hash output in reusable format [REUSABLE_FORMAT], e.g.:
**  hash -p /path/to/bin bin
*/

void	ft_print_reusable_output(char *name, char *location)
{
	if (location && name)
	{
		ft_putstr("hash -p ");
		ft_putstr(location);
		ft_putstr(" ");
		ft_putendl(name);
	}
	else
		ft_name_not_found(name);
}

/*
**  Print binary location [LOCATION_FORMAT], e.g.:
**  /path/to/bin
*/

void	ft_print_location(char *name, char *location)
{
	if (name && location)
	{
		ft_putstr(name);
		ft_putstr(" ");
		ft_putendl(location);
	}
	else
		ft_name_not_found(name);
}

/*
**	Print all hashed from the g_hash table,
**	format can be DEFAULT_FORMAT || REUSABLE_FORMAT || LOCATION_FORMAT
*/

void	ft_print_all(int format)
{
	unsigned int	i;

	i = 0;
	if (format == DEFAULT_FORMAT)
	{
		if (ft_get_hash_size() > 0)
			ft_putendl("hits     command");
		else
		{
			ft_putendl("hash: hash table empty");
			return ;
		}
	}
	while (i < HASH_SIZE)
	{
		if (g_hash[i])
		{
			if (format == DEFAULT_FORMAT)
				ft_print_default_output(g_hash[i]->hits, g_hash[i]->path);
			else if (format == REUSABLE_FORMAT)
				ft_print_reusable_output(g_hash[i]->binary, g_hash[i]->path);
		}
		i++;
	}
}

void	ft_print_names(char **names, int format)
{
	unsigned int	i;

	i = 0;
	while (names[i])
	{
		if (format == REUSABLE_FORMAT)
			ft_print_reusable_output(names[i], ft_get_location(names[i]));
		else if (format == LOCATION_FORMAT)
			ft_print_location(names[i], ft_get_location(names[i]));
		i++;
	}
}
