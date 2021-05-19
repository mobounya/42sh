/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:56:11 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/19 12:33:56 by mobounya         ###   ########.fr       */
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
	char	*value;

	cmd_type = get_cmdtype(name, &value);
	if (cmd_type == HASH)
		return (ft_print_type_hash(name, value, format));
	else if (cmd_type == ALIAS)
		return (ft_print_type_alias(name, value, format));
	else if (cmd_type == KEYWORD)
		return (ft_print_type_keyword(name, format));
	else if (cmd_type == BUILTIN)
		return (ft_print_type_builtin(name, format));
	else if (cmd_type == FILE)
		return (ft_print_type_binary(name, value, format));
	ft_type_not_found(name);
	return (1);
}

/*
**	Lookup name type, print all if name is multiple types
** 	Output format is either [WORD_OUTPUT] or [DEFAULT_OUTPUT].
*/

int	lookup_all_types(char	*name, int format)
{
	char	*value;
	int		status;

	status = 1;
	value = is_alias(name);
	if (value)
	{
		ft_print_type_alias(name, value, format);
		status = 0;
	}
	if (check_builtins(name))
	{
		ft_print_type_builtin(name, format);
		status = 0;
	}
	value = is_binary(name);
	if (value)
	{
		ft_print_type_binary(name, value, format);
		status = 0;
	}
	if (status)
		ft_type_not_found(name);
	return (status);
}

/*
**	Return path of name, if (type -t NAME) return file.
*/

int	ft_type_check_if_file(char *name, int flag)
{
	char	*valueue;
	int		type;

	type = get_cmdtype(name, &valueue);
	if (type == 0)
		return (1);
	if (type == FILE)
	{
		if (flag & (1 << LOW_T_FLAG))
			ft_putendl("file");
		else
			ft_putendl(valueue);
	}
	return (0);
}

/*
**	Return path of name, even if (type -t NAME) doesn't return file.
*/

int	ft_type_force_path_search(char *name, int flag)
{
	char	*value;

	value = is_binary(name);
	if (value != NULL)
	{
		if (flag & (1 << LOW_T_FLAG))
			ft_putendl("file");
		else
			ft_putendl(value);
		return (0);
	}
	return (1);
}

int	ft_type(char **command)
{
	unsigned int	i;
	unsigned int	flag;

	i = 1;
	flag = 0;
	while (command[i] && command[i][0] == '-')
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
		return (0);
	return (ft_execute_type(command + i, flag));
}
