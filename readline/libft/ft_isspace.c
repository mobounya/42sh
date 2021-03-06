/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 23:55:19 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:50:59 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch == '\t' || ch == '\v' || ch == '\f' || ch == '\n' || ch == '\r'
		|| ch == ' ')
		return (1);
	else
		return (0);
}
