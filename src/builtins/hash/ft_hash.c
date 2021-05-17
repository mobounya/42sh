/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:31:31 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/17 19:37:41 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	ft_set_path_name(char *binary, char *path)
{
	if (binary == NULL || path == NULL)
		ft_hash_arg_error("-p");
	else
		ft_add_hash(binary, path);
}

void	ft_exec_t_option(char **names, int flag)
{
	if (names[0] == NULL)
		ft_hash_arg_error("-t");
	else if (flag & (1 << LOW_L_FLAG))
		ft_print_names(names, REUSABLE_FORMAT);
	else
		ft_print_names(names, LOCATION_FORMAT);
}

void	ft_exec_d_option(char **names)
{
	if (names[0])
		ft_forget_names(names);
	else
		ft_print_all(DEFAULT_FORMAT);
}

int		ft_default_hash(char **names)
{
	int		error;

	error = 0;
	if (names[0] == NULL)
		ft_print_all(DEFAULT_FORMAT);
	else
		error = ft_hash_names(names);
	return (error);
}

int		ft_hash(char **command)
{
	int		flag;

	flag = 0;
	command = ft_parse_options(command + 1, &flag);
	if (command == NULL)
		return (1);
	else if (flag & (1 << LOW_R_FLAG))
	{
		ft_empty_hash();
		if (*(command))
			return ft_hash_names(command);
	}
	else if ((flag & (1 << LOW_D_FLAG)))
		ft_exec_d_option(command);
	else if (flag & (1 << LOW_P_FLAG))
		ft_set_path_name(*(command + 1), *command);
	else if (flag & (1 << LOW_T_FLAG))
		ft_exec_t_option(command, flag);
	else if (flag & (1 << LOW_L_FLAG))
		ft_print_all(REUSABLE_FORMAT);
	else
		return (ft_default_hash(command));
	return (0);
}
