/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:26:28 by mobounya          #+#    #+#             */
/*   Updated: 2021/05/19 12:32:52 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	ft_execute_type(char **names, int flag)
{
	unsigned int	i;
	int				final_status;
	int				current_status;
	int				format;

	i = 0;
	final_status = 1;
	format = DEFAULT_OUTPUT;
	if (flag & (1 << LOW_T_FLAG))
		format = WORD_OUTPUT;
	while (names[i])
	{
		if (flag & (1 << LOW_A_FLAG))
			current_status = lookup_all_types(names[i], format);
		else if (flag & (1 << LOW_P_FLAG))
			current_status = ft_type_check_if_file(names[i], flag);
		else if (flag & (1 << UPP_P_FLAG))
			current_status = ft_type_force_path_search(names[i], flag);
		else
			current_status = default_lookup(names[i], format);
		if (current_status == 0)
			final_status = 0;
		i++;
	}
	return (final_status);
}
