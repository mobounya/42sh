/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:47:22 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/19 18:35:39 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

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
