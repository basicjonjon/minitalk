/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:16:16 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/02 15:52:59 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/include/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define NC "\033[0m"

typedef struct s_data
{
	int		pid_cli;
	int		length;
	char	*str;
	int		counter;
	int		trigger;
	int		value;
	int		i;
	int		y;
}			t_data;

void		cli_signal_handler(int signum);
void		ft_launch_information(int info, int pid_srv);
void		ft_launch_str(char *str, int pid_srv);

void		next_step_struct(t_data *data);
int			get_pid_and_length(int signum, t_data *data);
char		*get_str(int signum, t_data *data);
void		srv_signal_handler(int signum);

#endif
