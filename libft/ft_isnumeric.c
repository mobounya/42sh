/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:37:31 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/19 19:04:25 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isnumeric(char *str)
{
    unsigned int    i;
    int             is_num;

    is_num = 1;
    str = ft_strtrim(str);
    i = 0;
    if (*str == '-' || *str == '+')
        i = 1;
    while(str[i])
    {
        if (ft_isdigit(str[i]) == 0)
        {
            is_num = 0;
            break ;
        }
        i++;
    }
    ft_strdel(&str);
    return (is_num);
}
