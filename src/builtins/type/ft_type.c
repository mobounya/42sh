/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:56:11 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/18 18:58:01 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

/*
**	Lookup name type in the default order.
** 	Output format is either [WORD_OUTPUT] or [DEFAULT_OUTPUT].
*/

int	default_lookup(char *name, int format)
{
	int		cmd_type;
	char	*val;

	cmd_type = get_cmdtype(name, &val);
	if (cmd_type == HASH)
	{
		ft_print_type_hash(name, val, format);
		return (0);
	}
	else if (cmd_type == ALIAS)
	{
		ft_print_type_alias(name, val, format);
		return (0);
	}
	else if (cmd_type == KEYWORD)
	{
		ft_print_type_keyword(name, format);
		return (0);
	}
	else if (cmd_type == BUILTIN)
	{
		ft_print_type_builtin(name, format);
		return (0);
	}
	else if (cmd_type == FILE)
	{
		ft_print_type_binary(name, val, format);
		return (0);
	}
	ft_type_not_found(name);
	return (1);
}

/*
**	Lookup name type, print all if name is multiple types
** 	Output format is either [WORD_OUTPUT] or [DEFAULT_OUTPUT].
*/

int	lookup_all_types(char	*name, int format)
{
	char	*val;
	int		status;

	status = 1;
	val = is_alias(name);
	if (val)
	{
		ft_print_type_alias(name, val, format);
		status = 0;
	}
	if (check_builtins(name))
	{
		ft_print_type_builtin(name, format);
		status = 0;
	}
	val = is_binary(name);
	if (val)
	{
		ft_print_type_binary(name, val, format);
		status = 0;
	}
	if (status)
		ft_type_not_found(name);
	return (status);
}

/*
**	Return path of name, if (type -t NAME) return file.
*/

int		ft_type_check_if_file(char *name, int flag)
{
	char	*value;
	int		type;

	type = get_cmdtype(name, &value);
	if (type == 0)
		return (1);
	if (type == FILE)
	{
		if (flag & (1 << LOW_T_FLAG))
			ft_putendl("file");
		else
			ft_putendl(value);
	}
	return (0);
}

/*
**	Return path of name, even if (type -t NAME) doesn't return file.
*/

int		ft_type_force_path_search(char *name, int flag)
{
	char	*val;

	val = is_binary(name);
	if (val != NULL)
	{
		if (flag & (1 << LOW_T_FLAG))
			ft_putendl("file");
		else
			ft_putendl(val);
		return (0);
	}
	return (1);
}

int	ft_type(char **command)
{
	unsigned int	i;
	unsigned int	flag;
	int				format;

	i = 1;
	flag = 0;
	format = DEFAULT_OUTPUT;
	while (command[i] && command[i][ 0] == '-')
	{
		if (ft_strncmp(command[i], "--", 2) == 0)
		{
			i++;
			break ;
		}
		if (ft_parse_type_options(command[i], &flag))
			return (1);
		i++;
	}
	if (command[i] == NULL)
		return (1);
	if (flag & (1 << LOW_T_FLAG))
		format = WORD_OUTPUT;
	if (flag & (1 << LOW_A_FLAG))
		return (lookup_all_types(command[i], format));
	else if (flag & (1 << LOW_P_FLAG))
		return (ft_type_check_if_file(command[i], flag));
	else if (flag & (1 << UPP_P_FLAG))
		return (ft_type_force_path_search(command[i], flag));
	else
		return (default_lookup(command[i], format));
	return (0);
}
