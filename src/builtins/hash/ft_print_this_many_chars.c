/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_this_many_chars.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:18:02 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/18 14:19:12 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	ft_print_chars(char c, uint times)
{
	unsigned int	i;

	i = 0;
	while (i < times)
	{
		ft_putchar(c);
		i++;
	}
}
