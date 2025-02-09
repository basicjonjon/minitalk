/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:51:05 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/02 16:09:01 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	verif_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < '0' || pid[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(2, "\033[1;31mWRONG ARGUMENT NUMBER\033[0m", 31);
		return (1);
	}
	if (verif_pid(argv[1]) || ft_atoi(argv[1]) <= 3)
	{
		write(2, "\033[1;31mINCORRECT PID\033[0m", 31);
		return (1);
	}
	if (signal(SIGUSR1, cli_signal_handler) == SIG_ERR)
	{
		write(2, "\033[1;31mSIG ERROR\033[0m", 31);
		return (1);
	}
	ft_launch_information(getpid(), ft_atoi(argv[1]));
	ft_launch_information(ft_strlen(argv[2]), ft_atoi(argv[1]));
	ft_launch_str(argv[2], ft_atoi(argv[1]));
	return (0);
}
