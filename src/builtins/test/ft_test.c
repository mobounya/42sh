/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:40:29 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/19 19:04:38 by mobounya         ###   ########.fr       */
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

const char	*g_test_integer_operators[7] = 
{
	"-eq",
	"-ne",
	"-gt",
	"-ge",
	"-lt",
	"-le",
	NULL,
};

const char	*g_test_string_operators[3] = 
{
	"=",
	"!=",
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

int 	ft_in_array(const char **array, char *needle, int (*equals)(const char*, const char*))
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

int		is_string_operator(char *operator)
{
	return (ft_in_array(g_test_string_operators, operator, &ft_strequ));
}

int		is_integer_operator(char *operator)
{
	return (ft_in_array(g_test_integer_operators, operator, &ft_strequ));
}

int		is_unary_operator(char *operator)
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

int		ft_test(char **command)
{
	int		argc;
	int		not;
	int		op_result;

	not = 0;
	if (command[1] && command[1][0] == '!')
		not = 1;
	command += not;
	argc = ft_arraysize(command);
	if (argc > 4)
		return (ft_test_too_many_arguments());
	if (argc == 4)
	{
		op_result = do_operation(command);
		if (op_result == 2)
			return (op_result);
		return (not ^ op_result);
	}
	if (argc == 3)
	{
		if (is_unary_operator(command[1]) == 0)
			return (ft_test_unary_op_expected(command[1]));
		return (not ^ ft_exec_condition(command + 1));
	}
	return (0);
}
