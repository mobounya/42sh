/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ter_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:52:43 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/30 16:53:33 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ter_p(int bool, void *val1, void *val2)
{
	if (bool)
		return (val1);
	return (val2);
}
