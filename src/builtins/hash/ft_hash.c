/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:31:31 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/18 15:13:57 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	ft_set_path_name(char *binary, char *path)
{
	if (binary == NULL || path == NULL)
	{
		ft_hash_arg_error("-p");
		return (1);
	}
	else
		ft_add_hash(binary, path, 0);
	return (0);
}

int	ft_exec_t_option(char **names, int flag)
{
	if (names[0] == NULL)
	{
		ft_hash_arg_error("-t");
		return (1);
	}
	else if (flag & (1 << LOW_L_FLAG))
		return (ft_print_names(names, REUSABLE_FORMAT));
	else
		return (ft_print_names(names, LOCATION_FORMAT));
	return (0);
}

int	ft_exec_d_option(char **names)
{
	if (names[0])
		return (ft_forget_names(names));
	else
		ft_print_all(DEFAULT_FORMAT);
	return (0);
}

int	ft_default_hash(char **names)
{
	int		error;

	error = 0;
	if (names[0] == NULL)
		ft_print_all(DEFAULT_FORMAT);
	else
		error = ft_hash_names(names);
	return (error);
}

int	ft_hash(char **command)
{
	int		flag;

	flag = 0;
	command = ft_parse_options(command + 1, &flag);
	if (command == NULL)
		return (1);
	if (flag & (1 << LOW_R_FLAG))
	{
		ft_empty_hash();
		if (*(command))
			return (ft_hash_names(command));
	}
	else if ((flag & (1 << LOW_D_FLAG)))
		return (ft_exec_d_option(command));
	else if (flag & (1 << LOW_P_FLAG))
		return (ft_set_path_name(*(command + 1), *command));
	else if (flag & (1 << LOW_T_FLAG))
		return (ft_exec_t_option(command, flag));
	else if (flag & (1 << LOW_L_FLAG))
		ft_print_all(REUSABLE_FORMAT);
	else
		return (ft_default_hash(command));
	return (0);
}
