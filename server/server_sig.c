/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:30:34 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/02 15:55:20 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	next_step_struct(t_data *data)
{
	data->i = 1;
	data->value = 0;
	data->counter = 0;
	data->trigger--;
}

int	get_pid_and_length(int signum, t_data *data)
{
	if (signum == SIGUSR2)
	{
		data->value += (1 * data->i);
		data->i *= 2;
	}
	else
		data->i *= 2;
	data->counter++;
	return (data->value);
}

char	*get_str(int signum, t_data *data)
{
	static char	*str;

	if (str == NULL)
	{
		str = malloc(sizeof(char) * data->length + 1);
		if (str == NULL)
			return (NULL);
	}
	if (signum == SIGUSR2)
	{
		data->value += (1 * data->i);
		data->i *= 2;
	}
	else
		data->i *= 2;
	data->counter++;
	if (data->counter == 8)
	{
		str[data->y] = data->value;
		data->value = 0;
		data->i = 1;
		data->y++;
		data->counter = 0;
	}
	return (str);
}

void	srv_signal_handler(int signum)
{
	static t_data	data = {0, 0, NULL, 0, 2, 0, 1, 0};

	if (data.trigger == 2 || data.trigger == 1)
	{
		if (data.trigger == 2)
			data.pid_cli = get_pid_and_length(signum, &data);
		else
			data.length = get_pid_and_length(signum, &data);
		if (data.counter == 32)
			next_step_struct(&data);
	}
	else
	{
		data.str = get_str(signum, &data);
		if (data.y == data.length)
		{
			write(1, data.str, data.length);
			data.trigger = 2;
			data.y = 0;
			data.str = NULL;
			kill(data.pid_cli, SIGUSR1);
		}
	}
}
