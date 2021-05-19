/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:40:29 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/19 16:23:31 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

const t_flags_matcher g_flags_matcher[TEST_UNARY_OPERATORS_SIZE + 1] =
{
	{"-b", &ft_check_file_type, BLOCK_FILE},
	{"-c", &ft_check_file_type, CHARACTER_FILE},
	{"-d", &ft_check_file_type, DIRECTORY},
	{"-e", &ft_check_file_type, IS_EXIST},
	{"-f", &ft_check_file_type, REGULAR_FILE},
	{"-g", &ft_check_file_type, GROUP_ID},
	{"-L", &ft_check_file_type, SYM_LINK},
	{"-p", &ft_check_file_type, NAMED_PIPE},
	{"-r", &ft_check_file_type, IS_READABLE},
	{"-S", &ft_check_file_type, IS_SOCKET},
	{"-s", &ft_check_file_type, POS_SIZE},
	{"-u", &ft_check_file_type, USER_ID},
	{"-w", &ft_check_file_type, IS_WRITABALE},
	{"-x", &ft_check_file_type, IS_EXECUTABLE},
	{"-z", &ft_check_str_length, 0},
	{NULL, NULL, 0},
};

const char	*g_test_operators[TEST_BINARY_OPERATORS_SIZE + 1] = 
{
	"=",
	"!=",
	"-eq",
	"-ne",
	"-ge",
	"-lt",
	"-le",
	NULL,
};

int		ft_check_str_length(char *str, int flag)
{
	(void)flag;
	if (ft_strlen(str) > 0)
		return (0);
	else
		return (1);
}

char	*ft_get_flag(char **command)
{
	unsigned int	i;

	i = 0;
	while (command[i] && command[i][0] == '-')
	{
		if (i >= 1)
			return (NULL);
		i++;
	}
	return (command[0]);
}

int		do_operation(char *operand1, char *operator, char *operand2)
{

	if (ft_strcmp(operator, "=") == 0 && ft_strcmp(operand1, operand2) == 0)
		return (0);
	if (ft_strcmp(operator, "!=") == 0 && ft_strcmp(operand1, operand2) != 0)
		return (0);
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

int		ft_exec_condition(char **command)
{
	unsigned int	i;
	int				res;
	char			*flag;
	char			*filename;

	i = 0;
	flag = command[0];
	filename = command[1];
	if (filename == NULL)
		return (0);
	while (g_flags_matcher[i].flag_name)
	{
		if (ft_strcmp(g_flags_matcher[i].flag_name, flag) == 0)
		{
			res = g_flags_matcher[i].function(filename, \
					g_flags_matcher[i].flag);
			return (res);
		}
		i++;
	}
	return (3);
}

int		is_binary_operator(char *operator)
{
	unsigned int	i;

	i = 0;
	while (i < TEST_BINARY_OPERATORS_SIZE)
	{
		if (ft_strequ(operator, g_test_operators[i]))
			return (1);
		i++;
	}
	return (0);
}

int		is_unary_operator(char *operator)
{
	unsigned int	i;

	i = 0;
	while (i < TEST_UNARY_OPERATORS_SIZE)
	{
		if (ft_strequ(g_flags_matcher[i].flag_name, operator))
			return (1);
		i++;
	}
	return (0);
}

int		ft_test(char **command)
{
	int		argc;
	int		has_not;

	has_not = 0;
	if (command[1] && command[1][0] == '!')
		has_not = 1;
	command += has_not;
	argc = ft_arraysize(command);
	if (argc > 4)
		return (ft_test_too_many_arguments());
	if (argc == 4)
	{
		if (is_binary_operator(command[2]) == 0)
			return (ft_test_binary_op_expected(command[2]));
		return (has_not ^ do_operation(command[1], command[2], command[3]));
	}
	if (argc == 3)
	{
		if (is_unary_operator(command[1]) == 0)
			return (ft_test_unary_op_expected(command[1]));
		return (has_not ^ ft_exec_condition(command + 1));	
	}
	return (0);
}
