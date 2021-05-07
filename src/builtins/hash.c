/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 09:55:21 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/06 14:41:01 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

t_t	*get_new_node(char *key, char *value)
{
	t_t		*root;

	root = (t_t *)ft_memalloc(sizeof(t_t));
	root->key = ft_strdup(key);
	root->value = ft_strdup(value);
	root->count = 1;
	root->left = NULL;
	root->right = NULL;
	return (root);
}

t_t	*insert_name(t_t *root, char *key, char *value)
{
	if (root == NULL)
	{
		root = get_new_node(key, value);
		return (root);
	}
	if (ft_strcmp(key, root->key) < 0)
		root->left = insert_name(root->left, key, value);
	else if (!ft_strcmp(key, root->key))
		root->count++;
	else
		root->right = insert_name(root->right, key, value);
	return (root);
}

void	print_hash(t_t *root)
{
	static int	i = 0;
	static int	f_time = 0;
	int			len;

	if (root == NULL && f_time == 0)
	{
		ft_printf(1, "hash: hash table empty\n");
		return ;
	}
	if (root != NULL)
	{
		if (root->left)
			print_hash(root->left);
		if (i++ == 0)
			ft_printf(1, "hits    command\n");
		len = ft_nbrlen(root->count);
		while (len++ < 4)
			ft_printf(1, " ");
		ft_printf(1, "%d    %s\n", root->count, root->value);
		if (root->right)
			print_hash(root->right);
	}
}

char	*find_key_in_hash(t_t *root, char *key)
{
	char	*value;

	if (root == NULL)
		return (NULL);
	if (!ft_strcmp(root->key, key))
	{
		root->count++;
		return (root->value);
	}
	value = find_key_in_hash(root->left, key);
	if (value)
		return (value);
	value = find_key_in_hash(root->right, key);
	if (value)
		return (value);
	return (NULL);
}

void	free_hash(t_t **root)
{
	t_t	*tail;

	if (*root == NULL)
		return ;
	tail = *root;
	free_hash(&(tail->left));
	free_hash(&(tail->right));
	ft_strdel(&(tail->key));
	ft_strdel(&(tail->value));
}
