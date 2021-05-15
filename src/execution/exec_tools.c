/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:11:49 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/06 14:45:33 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	check_file(char *path)
{
	if (access(path, F_OK) != -1)
		return (1);
	return (0);
}

int	check_file_permissions(char *path)
{
	struct stat	st;

	if (!check_file(path)
		|| access(path, X_OK) == -1
		|| lstat(path, &st) == -1
		|| S_ISDIR(st.st_mode))
		return (0);
	return (1);
}

char	*try_every_possibility(char *cmd, char *path_env)
{
	char	**ab;
	char	*tmp;
	char	*tmp2;
	int		i;

	ab = ft_strsplit(path_env, ':');
	if (!path_env || !ab)
		return (ft_strdup(cmd));
	i = -1;
	tmp = NULL;
	tmp2 = NULL;
	while (ab[++i])
	{
		tmp = ft_strjoin(ab[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (check_file_permissions(tmp2))
		{
			ft_free_strings_array(ab);
			return (tmp2);
		}
		free(tmp2);
	}
	ft_free_strings_array(ab);
	return (ft_strdup(cmd));
}

char	*get_full_path(char *cmd)
{
	char	*full_path;
	char	*value;

	value = NULL;
	// You are supposed to look for a hash key here
	if (!value)
	{
		if (!ft_strchr(cmd, '/') && !check_builtins(cmd))
		{
			full_path = try_every_possibility(cmd,
					env_get(g_shell_env, "PATH"));
			// suppose to add bin path to hash table.
		}
		else
			full_path = ft_strdup(cmd);
		return (full_path);
	}
	else
		return (ft_strdup(value));
}
