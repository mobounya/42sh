/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:47:22 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/20 15:12:03 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	ft_check_file_permissions(char *file, int permission_to_check)
{
	if (permission_to_check == IS_WRITABALE)
	{
		if (access(file, W_OK) == 0)
			return (0);
	}
	else if (permission_to_check == IS_READABLE)
	{
		if (access(file, R_OK) == 0)
			return (0);
	}
	else if (permission_to_check == IS_EXECUTABLE)
	{
		if (access(file, X_OK) == 0)
			return (0);
	}
	return (1);
}

int	ft_is_block_or_char_device(char *file, int device)
{
	struct stat	buffer;

	if (lstat(file, &buffer) == -1)
		return (1);
	if (device == BLOCK_FILE)
	{
		if (S_ISBLK(buffer.st_mode))
			return (0);
	}
	else if (device == CHARACTER_FILE)
	{
		if (S_ISCHR(buffer.st_mode))
			return (0);
	}
	return (1);
}

int	ft_is_group_or_user_id_set(char *file, int id)
{
	struct stat	buffer;

	if (lstat(file, &buffer) == -1)
		return (1);
	if (id == GROUP_ID)
	{
		if (buffer.st_mode & S_ISGID)
			return (0);
	}
	else if (id == USER_ID)
	{
		if (buffer.st_mode & S_ISUID)
			return (0);
	}
	return (1);
}

int	ft_check_file_type(char *filename, int type)
{
	struct stat	buffer;

	if (lstat(filename, &buffer) == -1)
		return (1);
	if (type == DIRECTORY)
	{
		if (S_ISDIR(buffer.st_mode))
			return (0);
	}
	else if (type == REGULAR_FILE)
	{
		if (S_ISREG(buffer.st_mode))
			return (0);
	}
	else if (type == NAMED_PIPE)
	{
		if (S_ISFIFO(buffer.st_mode))
			return (0);
	}
	else if (type == SYM_LINK)
	{
		if (S_ISLNK(buffer.st_mode))
			return (0);
	}
	return (1);
}

int	ft_check_file(char *filename, int flag)
{
	struct stat	buffer;

	if (flag == IS_EXIST)
	{
		if (access(filename, F_OK) == -1)
			return (1);
		else
			return (0);
	}
	if (lstat(filename, &buffer) == -1)
		return (1);
	if ((flag == IS_SOCKET) && S_ISSOCK(buffer.st_mode))
		return (0);
	if ((flag == POS_SIZE) && buffer.st_size > 0)
		return (0);
	if (flag == IS_WRITABALE || flag == IS_READABLE || flag == IS_EXECUTABLE)
		return (ft_check_file_permissions(filename, flag));
	if (flag == BLOCK_FILE || flag == CHARACTER_FILE)
		return (ft_is_block_or_char_device(filename, flag));
	if (flag == GROUP_ID || flag == USER_ID)
		return (ft_is_group_or_user_id_set(filename, flag));
	if (flag == DIRECTORY || flag == REGULAR_FILE || flag == NAMED_PIPE || \
		flag == SYM_LINK)
		return (ft_check_file_type(filename, flag));
	return (1);
}
