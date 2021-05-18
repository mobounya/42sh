/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:15:14 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/18 18:04:54 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

/*
**	shell keywords:
**	while until time select if function for case do done
**	elif else esac fi for function in then until
**  ! [[ ]] { }
*/

char	*is_binary(char *name)
{
	char	*path;
	char	*binary_location;
	
	path = env_get(g_shell_env, "PATH");
	binary_location = try_every_possibility(name, path);
	if (ft_strequ(binary_location, name))
		return (NULL);
	else
		return (binary_location);
}

char	*is_alias(char *name)
{
	// Get alias
	(void)name;
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
	if (check_builtins(name))
		return (BUILTIN);
	*val = is_binary(name);
	if (*val)
		return (FILE);
	if (is_keyword(name))
		return (KEYWORD);
	return (0);
}
