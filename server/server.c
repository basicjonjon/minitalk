/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:51:34 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/02 16:09:19 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	if (!argv || argc > 1)
	{
		write(2, "\033[1;31mNO ARGUMENT ALLOWED\033[0m", 31);
		return (1);
	}
	if (signal(SIGUSR1, srv_signal_handler) == SIG_ERR)
	{
		write(2, "\033[1;31mSIG ERROR\033[0m", 31);
		return (1);
	}
	else if (signal(SIGUSR2, srv_signal_handler) == SIG_ERR)
	{
		write(2, "\033[1;31mSIG ERROR\033[0m", 31);
		return (1);
	}
	ft_printf("PID : %i\n", getpid());
	while (1)
		pause();
	return (0);
}
