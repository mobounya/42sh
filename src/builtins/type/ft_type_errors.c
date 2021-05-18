/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:38:29 by mobounya          #+#    #+#             */
/*   Updated: 2021/04/29 13:42:22 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_display_type_usage(void)
{
	ft_putendl_fd("type: usage: type [-afptP] name [name ...]", 2);
}

void	ft_type_invalid_option(char option)
{
	ft_putstr_fd("42sh: type: -", 2);
	ft_putchar_fd(option, 2);
	ft_putendl_fd(": invalid option", 2);
	ft_display_type_usage();
}
