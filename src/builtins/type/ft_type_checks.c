/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:15:14 by mobounya          #+#    #+#             */
/*   Updated: 2021/04/29 14:04:01 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
**	shell keywords:
**	while until time select if function for case do done
**	elif else esac fi for function in then until
**  ! [[ ]] { }
*/

char	*is_binary(char *name)
{
	char	**paths;
	uint	i;
	char	*temp;
	char	*path_bin;

	i = 0;
	paths = ft_getpath();
	path_bin = NULL;
	if (paths != NULL && paths[0])
	{
		while (paths[i])
		{
			temp = ft_strjoin(paths[i], "/");
			path_bin = ft_strjoin(temp, name);
			ft_memdel((void **)&temp);
			if (access(path_bin, F_OK) == 0)
				break ;
			ft_memdel((void **)&path_bin);
			i++;
		}
	}
	ft_free_arr(paths);
	return (path_bin);
}

char	*is_alias(char *name)
{
	t_alias		*alias;

	alias = g_env.al;
	while (alias)
	{
		if (ft_strcmp(alias->alias, name) == 0)
			return (alias->str);
		alias = alias->next;
	}
	return (NULL);
}

char	*is_hashed(char *name)
{
	char	*path;

	path = ft_get_hash_location(name);
	return (path);
}

int	is_keyword(char *name)
{
	unsigned int	i;
	static char		*keywords[] = {"while", "until", "time", "select",
	"if", "function", "for", "case", "do",
	"done", "elif", "else", "esac", "fi",
	"for", "function", "in", "then", "until",
	"!", "[[", "]]", "{", "}", NULL};

	i = 0;
	while (keywords[i])
	{
		if (ft_strcmp(keywords[i], name) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	get_cmdtype(char *name, char **val)
{
	*val = is_alias(name);
	if (*val)
		return (ALIAS);
	*val = is_hashed(name);
	if (*val)
		return (HASH);
	if (is_builtin(name))
		return (BUILTIN);
	*val = is_binary(name);
	if (*val)
		return (FILE);
	if (is_keyword(name))
		return (KEYWORD);
	return (0);
}
