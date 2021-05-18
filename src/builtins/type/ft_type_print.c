/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:59:56 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/18 16:46:23 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	ft_print_type_hash(char *name, char *path, int format)
{
	if (format == WORD_OUTPUT)
		ft_putendl("file");
	else
	{
		ft_putstr(name);
		ft_putstr(" is hashed (");
		ft_putstr(path);
		ft_putendl(")");
	}
}

void	ft_print_type_alias(char *name, char *alias_value, int format)
{
	if (format == WORD_OUTPUT)
		ft_putendl("alias");
	else
	{
		ft_putstr(name);
		ft_putstr(" is an alias for ");
		ft_putendl(alias_value);
	}
}

void	ft_print_type_keyword(char *name, int format)
{
	if (format == WORD_OUTPUT)
		ft_putendl("keyword");
	else
	{
		ft_putstr(name);
		ft_putendl(" is a shell keyword");
	}
}

void	ft_print_type_builtin(char *name, int format)
{
	if (format == WORD_OUTPUT)
		ft_putendl("builtin");
	else
	{
		ft_putstr(name);
		ft_putendl(" is a shell builtin");
	}
}

void	ft_print_type_binary(char *name, char *path, int format)
{
	if (format == WORD_OUTPUT)
		ft_putendl("file");
	else
	{
		ft_putstr(name);
		ft_putstr(" is ");
		ft_putendl(path);
	}
}
