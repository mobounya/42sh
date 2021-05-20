/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_test_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:58:53 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/20 14:06:05 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

extern t_flags_matcher	g_flags_matcher[];

const char				*g_test_integer_operators[7] =
{
	"-eq",
	"-ne",
	"-gt",
	"-ge",
	"-lt",
	"-le",
	NULL,
};

const char				*g_test_string_operators[3] =
{
	"=",
	"!=",
	NULL,
};

int	ft_in_array(const char **array, char *needle, \
		int (*equals)(const char*, const char*))
{
	unsigned int	i;

	i = 0;
	while (array[i])
	{
		if (equals(needle, array[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_string_operator(char *operator)
{
	return (ft_in_array(g_test_string_operators, operator, &ft_strequ));
}

int	is_integer_operator(char *operator)
{
	return (ft_in_array(g_test_integer_operators, operator, &ft_strequ));
}

int	is_unary_operator(char *operator)
{
	unsigned int	i;

	i = 0;
	while (i < TEST_UNARY_OPERATORS_SIZE)
	{
		if (ft_strequ(operator, g_flags_matcher[i].flag_name))
			return (1);
		i++;
	}
	return (0);
}
