/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:40:08 by mobounya          #+#    #+#             */
/*   Updated: 2021/04/28 16:06:34 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	ft_hash_usage(void)
{
	ft_putendl_fd("hash: usage: hash [-lr] [-p pathname] [-dt] [name ...]", 2);
}

void	ft_hash_arg_error(char *flag)
{
	ft_putstr_fd("42sh hash: ", 2);
	ft_putstr_fd(flag, 2);
	ft_putendl_fd(": option requires an argument", 2);
	ft_hash_usage();
}

void	ft_hash_flag_error(char *flag)
{
	ft_putstr_fd("42sh hash: ", 2);
	ft_putstr_fd(flag, 2);
	ft_putendl_fd(": invalid option", 2);
	ft_hash_usage();
}

void	ft_name_not_found(char *name)
{
	ft_putstr_fd("42sh: hash: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": not found", 2);
}
