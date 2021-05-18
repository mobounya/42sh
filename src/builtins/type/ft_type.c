/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:56:11 by mobounya          #+#    #+#             */
/*   Updated: 2021/04/29 14:10:34 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
		ft_print_type_hash(name, val, format);
	else if (cmd_type == ALIAS)
		ft_print_type_alias(name, val, format);
	else if (cmd_type == KEYWORD)
		ft_print_type_keyword(name, format);
	else if (cmd_type == BUILTIN)
		ft_print_type_builtin(name, format);
	else if (cmd_type == FILE)
		ft_print_type_binary(name, val, format);
	return (0);
}

/*
**	Lookup name type, print all if name is multiple types
** 	Output format is either [WORD_OUTPUT] or [DEFAULT_OUTPUT].
*/

int	lookup_all_types(char	*name, int format)
{
	char			*val;

	val = is_alias(name);
	if (val)
		ft_print_type_alias(name, val, format);
	if (is_builtin(name))
		ft_print_type_builtin(name, format);
	val = is_binary(name);
	if (val)
		ft_print_type_binary(name, val, format);
	return (1);
}

/*
**	Return path of name, if (type -t NAME) return file.
*/

void	ft_type_check_if_file(char *name, int flag)
{
	char	*value;

	if (get_cmdtype(name, &value) == FILE)
	{
		if (flag & (1 << LOW_T_FLAG))
			ft_putendl("file");
		else
			ft_putendl(value);
	}
}

/*
**	Return path of name, even if (type -t NAME) doesn't return file.
*/

void	ft_type_force_path_search(char *name, int flag)
{
	char	*val;

	val = is_binary(name);
	if (val != NULL)
	{
		if (flag & (1 << LOW_T_FLAG))
			ft_putendl("file");
		else
			ft_putendl(val);
	}
}

int	ft_type(char **command)
{
	unsigned int	i;
	char			*val;
	unsigned int	flag;
	int				format;

	i = 1;
	flag = 0;
	format = DEFAULT_OUTPUT;
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
	if (flag & (1 << LOW_T_FLAG))
		format = WORD_OUTPUT;
	if (command[i] == NULL)
		return (g_exit_code = -1);
	else if (flag & (1 << LOW_A_FLAG))
		return (lookup_all_types(command[i], format));
	else if (flag & (1 << LOW_P_FLAG))
		ft_type_check_if_file(command[i], flag);
	else if (flag & (1 << UPP_P_FLAG))
		ft_type_force_path_search(command[i], flag);
	else
		return (default_lookup(command[i], format));
	return (0);
}
