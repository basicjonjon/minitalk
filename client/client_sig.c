/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:24:59 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/02 15:58:03 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	cli_signal_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("%sok%s", GREEN, NC);
}

void	ft_launch_information(int info, int pid_srv)
{
	int	i;
	int	u_value;

	i = 0;
	u_value = 100;
	while (i < 32)
	{
		if (info & (1 << i))
		{
			kill(pid_srv, SIGUSR2);
		}
		else
		{
			kill(pid_srv, SIGUSR1);
		}
		i++;
		usleep(u_value);
	}
}

void	ft_launch_str(char *str, int pid_srv)
{
	int	i;
	int	y;
	int	u_value;

	i = 0;
	u_value = 100;
	while (str[i])
	{
		y = 0;
		while (y < 8)
		{
			if (str[i] & (1 << y))
				kill(pid_srv, SIGUSR2);
			else
				kill(pid_srv, SIGUSR1);
			y++;
			usleep(u_value);
		}
		i++;
	}
}
