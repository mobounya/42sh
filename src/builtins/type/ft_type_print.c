/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:59:56 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/19 11:41:25 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	ft_print_type_hash(char *name, char *path, int format)
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
	return (0);
}

int	ft_print_type_alias(char *name, char *alias_value, int format)
{
	if (format == WORD_OUTPUT)
		ft_putendl("alias");
	else
	{
		ft_putstr(name);
		ft_putstr(" is an alias for ");
		ft_putendl(alias_value);
	}
	return (0);
}

int	ft_print_type_keyword(char *name, int format)
{
	if (format == WORD_OUTPUT)
		ft_putendl("keyword");
	else
	{
		ft_putstr(name);
		ft_putendl(" is a shell keyword");
	}
	return (0);
}

int	ft_print_type_builtin(char *name, int format)
{
	if (format == WORD_OUTPUT)
		ft_putendl("builtin");
	else
	{
		ft_putstr(name);
		ft_putendl(" is a shell builtin");
	}
	return (0);
}

int	ft_print_type_binary(char *name, char *path, int format)
{
	if (format == WORD_OUTPUT)
		ft_putendl("file");
	else
	{
		ft_putstr(name);
		ft_putstr(" is ");
		ft_putendl(path);
	}
	return (0);
}
