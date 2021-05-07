/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcsetpgrp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:20:17 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/07 13:26:53 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"
#include <sys/ioctl.h>

int	ft_tcsetpgrp(int fildes, pid_t pgid_id)
{
	return (ioctl(fildes, TIOCSPGRP, &pgid_id));
}
