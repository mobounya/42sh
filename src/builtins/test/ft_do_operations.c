/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:15:09 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/20 13:52:17 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static int	do_string_operation(char *operand1, char *operator, char *operand2)
{
	if (ft_strequ(operator, "="))
		return (ft_strequ(operand1, operand2));
	if (ft_strequ(operator, "!="))
		return (!ft_strequ(operand1, operand2));
	return (2);
}

static int	do_integer_operation(char *operand1, char *operator, char *operand2)
{
	if (ft_strcmp(operator, "-eq") == 0)
		if (ft_atoi(operand1) == ft_atoi(operand2))
			return (0);
	if (ft_strcmp(operator, "-ne") == 0)
		if (ft_atoi(operand1) != ft_atoi(operand2))
			return (0);
	if (ft_strcmp(operator, "-gt") == 0)
		if (ft_atoi(operand1) > ft_atoi(operand2))
			return (0);
	if (ft_strcmp(operator, "-ge") == 0)
		if (ft_atoi(operand1) >= ft_atoi(operand2))
			return (0);
	if (ft_strcmp(operator, "-lt") == 0)
		if (ft_atoi(operand1) < ft_atoi(operand2))
			return (0);
	if (ft_strcmp(operator, "-le") == 0)
		if (ft_atoi(operand1) <= ft_atoi(operand2))
			return (0);
	return (1);
}

static char	*which_operand_is_not_numeric(char *operator1, char *operator2)
{
	if (ft_isnumeric(operator1) == 0)
		return (operator1);
	else if (ft_isnumeric(operator2) == 0)
		return (operator2);
	return (NULL);
}

int	do_operation(char **command)
{
	char	*operator;

	if (is_string_operator(command[2]))
		return (do_string_operation(command[1], command[2], command[3]));
	else if (is_integer_operator(command[2]))
	{
		operator = which_operand_is_not_numeric(command[1], command[3]);
		if (operator == NULL)
			return (do_integer_operation(command[1], command[2], command[3]));
		return (ft_test_integer_expected(operator));
	}
	return (ft_test_binary_op_expected(command[2]));
}
