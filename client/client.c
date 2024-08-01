/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:51:05 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/01 17:50:52 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// static int	ft_countnbsize_base(int n, char *base)
// {
// 	int		i;
// 	long	num;
// 	int		base_len;

// 	i = 0;
// 	num = n;
// 	base_len = ft_strlen(base);
// 	if (num == 0)
// 		return (1);
// 	if (num < 0)
// 		num *= -1;
// 	while (num > 0)
// 	{
// 		num /= base_len;
// 		i++;
// 	}
// 	return (i);
// }

void	bin_print(int c)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (c & (1 << i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		i--;
	}
	printf("\n");
}

void	ft_launch_pid(int pid_cli, int pid_srv)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (pid_cli & (1 << i))
		{
			kill(pid_srv, SIGUSR2);
		}
		else
		{
			kill(pid_srv, SIGUSR1);
		}
		i++;
		usleep(500);
	}
}

void	ft_launch_length(int length, int pid_srv)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (length & (1 << i))
		{
			kill(pid_srv, SIGUSR2);
		}
		else
		{
			kill(pid_srv, SIGUSR1);
		}
		i++;
		usleep(500);
	}
}
void	ft_launch_str(char *str, int pid_srv)
{
	int	i;
	int	y;

	i = 0;
	while (str[i])
	{
		y = 0;
		while (y < 8)
		{
			if (str[i] & (1 << y))
			{
				kill(pid_srv, SIGUSR2);
			}
			else
			{
				kill(pid_srv, SIGUSR1);
			}
			y++;
			usleep(500);
		}
		i++;
		
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	ft_launch_pid(getpid(), ft_atoi(argv[1]));
	ft_launch_length(ft_strlen(argv[2]), ft_atoi(argv[1]));
	ft_launch_str(argv[2], ft_atoi(argv[1]));
	return (0);
}
