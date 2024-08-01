/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:47:28 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:26:50 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nelement, size_t size)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(size * nelement);
	if (!res)
		return (0);
	while (i < nelement * size)
		res[i++] = 0;
	return ((void *)res);
}
