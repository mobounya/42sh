/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:40:29 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/19 13:42:10 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

const t_flags_matcher g_flags_matcher[] =
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

int		ft_check_str_length(char *str, int flag)
{
	(void)flag;
	if (ft_strlen(str) > 0)
		return (0);
	else
		return (1);
}

int		ft_check_file_type(char *filename, int flag)
{
	struct stat buf;

	if (access(filename, F_OK) == 0)
	{
		if (flag == IS_EXIST)
			return (0);
		if (lstat(filename, &buf) == 0)
		{
			if (flag == SYM_LINK)
			{
				ft_putendl("TODO: Come back to this later");
				return (0);
			}
			if ((flag == BLOCK_FILE) && S_ISBLK(buf.st_mode))
				return (0);
			if ((flag == CHARACTER_FILE) && S_ISCHR(buf.st_mode))
				return (0);
			if ((flag == DIRECTORY) && S_ISDIR(buf.st_mode))
				return (0);
			if ((flag == REGULAR_FILE) && S_ISREG(buf.st_mode))
				return (0);
			if ((flag == GROUP_ID) && buf.st_mode & S_ISGID)
				return (0);
			if ((flag == NAMED_PIPE) && S_ISFIFO(buf.st_mode))
				return (0);
			if ((flag == IS_READABLE) && access(filename, R_OK) == 0)
				return (0);
			if ((flag == IS_SOCKET) && S_ISSOCK(buf.st_mode))
				return (0);
			if ((flag == POS_SIZE) && buf.st_size > 0)
				return (0);
			if ((flag == USER_ID) && buf.st_mode & S_ISUID)
				return (0);
			if ((flag == IS_WRITABALE) && access(filename, W_OK) == 0)
				return (0);
			if ((flag == IS_EXECUTABLE) && access(filename, X_OK) == 0)
				return (0);
			return (1);
		}
	}
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

int		do_operation(char **command)
{
	char	*operator;
	char	*operand1;
	char	*operand2;

	operator = command[1];
	operand1 = command[0];
	operand2 = command[2];
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

void	unknown_flag(char *flag)
{
	ft_putstr("test: ");
	ft_putstr("unknown condition: ");
	ft_putendl(flag);
}

int		ft_exec_condition(char **command)
{
	unsigned int	i;
	int				res;
	char			*flag;
	char			*filename;

	i = 0;
	flag = command[0];
	if ((filename = command[1]) == NULL)
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
	unknown_flag(flag);
	return (1);
}

int		ft_test(char **command)
{
	int				res;
	int				size;
	int				not;

	not = 0;
	if (command[1] == NULL)
		return (0);
	if (command[1][0] == '!')
		not = 1;
	if ((!not && !command[1]) || (not && !command[2]))
		return (0);
	if ((!not && command[1][0] == '-') || (not && command[2][0] == '-'))
	{
		if ((size = ft_arraysize(command + ((not) ? 2 : 1))) > 2)
			return (0);
		res = ft_exec_condition(command + ((not) ? 2 : 1));
	}
	else
	{
		size = ft_arraysize(command + ((not) ? 2 : 1));
		if (size > 3)
			return (0);
		if (size < 3)
		{
			ft_putstr_fd("42sh: parse error: condition expected: ", 2);
			ft_putendl_fd(*(command + ((not) ? 2 : 1)), 2);
			return (1);
		}
		res = do_operation(command + ((command[1][0] == '!') ? 2 : 1));
	}
	if (not && res)
		res = 0;
	else if (not && !res)
		res = 1;
	return (0);
}
