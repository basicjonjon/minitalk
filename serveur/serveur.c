/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:51:34 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/02 11:54:09 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	bin_print(int c)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (c & (1 << i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		i++;
	}
	printf("\n");
}

void	signal_handler(int signum)
{
	static int	i = 1;
	static int	y = 0;
	static char	*str = NULL;
	static int	counter = 0;
	static int	trigger = 2;
	static int	length = 0;
	static int	pid = 0;
	static int	c = 0;
	int			u_value;

	u_value = 500;
	if (trigger == 2)
	{
		if (signum == SIGUSR2)
		{
			c += (1 * i);
			i *= 2;
		}
		else
			i *= 2;
		counter++;
		if (counter == 32)
		{
			pid = c;
			i = 1;
			c = 0;
			counter = 0;
			trigger--;
			// printf("PID CLI : %i\n", pid);
			usleep(u_value);
		}
	}
	else if (trigger == 1)
	{
		if (signum == SIGUSR2)
		{
			c += (1 * i);
			i *= 2;
		}
		else
		{
			i *= 2;
		}
		counter++;
		if (counter == 32)
		{
			length = c;
			i = 1;
			c = 0;
			counter = 0;
			trigger--;
			// printf("LENGTH : %i\n", length);
			usleep(u_value);
		}
	}
	else
	{
		if (str == NULL)
		{
			str = malloc(sizeof(char) * length + 1);
			if (str == NULL)
				return ;
		}
		if (signum == SIGUSR2)
		{
			c += (1 * i);
			i *= 2;
		}
		else
		{
			i *= 2;
		}
		counter++;
		if (counter == 8)
		{
			str[y] = c;
			c = 0;
			i = 1;
			y++;
			counter = 0;
		}
		if (y == length)
		{
			write(1, str, length);
			trigger = 2;
			y = 0;
			str = NULL;
			kill(pid, SIGUSR1);
		}
	}
}

int	main(void)
{
	struct sigaction sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	else if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	printf("PID : %i\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}