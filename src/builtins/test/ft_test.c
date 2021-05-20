/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:40:29 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/20 16:32:34 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

const t_flags_matcher	g_flags_matcher[TEST_UNARY_OPERATORS_SIZE + 1] =
{
	{"-b", &ft_check_file, BLOCK_FILE},
	{"-c", &ft_check_file, CHARACTER_FILE},
	{"-d", &ft_check_file, DIRECTORY},
	{"-e", &ft_check_file, IS_EXIST},
	{"-f", &ft_check_file, REGULAR_FILE},
	{"-g", &ft_check_file, GROUP_ID},
	{"-L", &ft_check_file, SYM_LINK},
	{"-p", &ft_check_file, NAMED_PIPE},
	{"-r", &ft_check_file, IS_READABLE},
	{"-S", &ft_check_file, IS_SOCKET},
	{"-s", &ft_check_file, POS_SIZE},
	{"-u", &ft_check_file, USER_ID},
	{"-w", &ft_check_file, IS_WRITABALE},
	{"-x", &ft_check_file, IS_EXECUTABLE},
	{"-z", &ft_check_str_length, 0},
	{NULL, NULL, 0},
};

int	ft_check_str_length(char *str, int flag)
{
	(void)flag;
	if (ft_strlen(str) == 0)
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

int	ft_exec_condition(char **command)
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

int	ft_test(char **command)
{
	int		argc;
	int		not;
	int		op_result;

	not = 0;
	if (command[1] && ft_strequ(command[1], "!"))
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
