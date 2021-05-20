/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_test_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:48:49 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/20 13:49:21 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	ft_test_condition_expected(char *condition)
{
	ft_putstr_fd("42sh: parse error: condition expected: ", 2);
	ft_putendl_fd(condition, 2);
}

int	ft_test_too_many_arguments(void)
{
	ft_putendl_fd("42sh: test: too many arguments", 2);
	return (2);
}

int	ft_test_binary_op_expected(char *op)
{
	ft_putstr_fd("42sh: test: ", 2);
	ft_putstr_fd(op, 2);
	ft_putendl_fd(": binary operator expected", 2);
	return (2);
}

int	ft_test_unary_op_expected(char *op)
{
	ft_putstr_fd("42sh: test: ", 2);
	ft_putstr_fd(op, 2);
	ft_putendl_fd(": unary operator expected", 2);
	return (2);
}

int	ft_test_integer_expected(char *str)
{
	ft_putstr_fd("42sh: test: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": integer expression expected", 2);
	return (2);
}
