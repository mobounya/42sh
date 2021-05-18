/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:45:26 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:34:25 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		intlen(int n)
{
	int digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digits++;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char			*ft_itoa(int n)
{
	int		digits;
	char	*str;
	int		i;
	long	num;

	num = n;
	i = 0;
	digits = intlen(num);
	if ((str = malloc(sizeof(*str) * (digits + 1))) == NULL)
		return (NULL);
	str[digits--] = '\0';
	if (num < 0)
	{
		str[i++] = '-';
		num *= -1;
	}
	while (i <= digits)
	{
		str[digits] = (char)(num % 10) + 48;
		num /= 10;
		digits--;
	}
	return (str);
}
