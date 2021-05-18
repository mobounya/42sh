/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:08:30 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/18 17:54:48 by mobounya         ###   ########.fr       */
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
	size_t			hits_str_len;
	char			*hits_str;
	size_t			num_of_spaces_to_print;

	hits_str = ft_itoa(hits);
	hits_str_len = ft_strlen(hits_str);
	num_of_spaces_to_print = 4 - hits_str_len;
	ft_print_chars(' ', num_of_spaces_to_print);
	ft_putnbr(hits);
	ft_putstr("    ");
	ft_putendl(location);
}

/*
**  Print hash output in reusable format [REUSABLE_FORMAT], e.g.:
**  hash -p /path/to/bin bin
*/

int	ft_print_reusable_output(char *name, char *location)
{
	if (location && name)
	{
		ft_putstr("hash -p ");
		ft_putstr(location);
		ft_putstr(" ");
		ft_putendl(name);
	}
	else
	{
		ft_name_not_found(name);
		return (1);
	}
	return (0);
}

/*
**  Print binary location [LOCATION_FORMAT], e.g.:
**  /path/to/bin
*/

int	ft_print_location(char *name, char *location)
{
	if (name && location)
	{
		ft_putstr(name);
		ft_putstr(" ");
		ft_putendl(location);
	}
	else
	{
		ft_name_not_found(name);
		return (1);
	}
	return (0);
}

/*
**	Print all hashed from the g_hash table,
**	format can be DEFAULT_FORMAT || REUSABLE_FORMAT || LOCATION_FORMAT
*/

void	ft_print_all(int format)
{
	unsigned int	i;

	i = 0;
	if (ft_get_hash_size() == 0)
	{
		ft_putendl("hash: hash table empty");
		return ;
	}
	if (format == DEFAULT_FORMAT)
		ft_putendl("hits    command");
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

int	ft_print_names(char **names, int format)
{
	unsigned int	i;
	int				error;

	i = 0;
	error = 0;
	while (names[i])
	{
		if (format == REUSABLE_FORMAT)
		{
			if (ft_print_reusable_output(names[i], ft_get_hash_location(names[i])))
				error = 1;
		}
		else if (format == LOCATION_FORMAT)
		{
			if (ft_print_location(names[i], ft_get_hash_location(names[i])))
				error = 1;
		}
		i++;
	}
	return (error);
}
