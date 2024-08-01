/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:15:06 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:26:54 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(void *mem, int search, size_t n)
{
	char	*p;
	size_t	i;

	p = mem;
	i = 0;
	while (i < n)
	{
		if ((char)search == p[i])
			return (&mem[i]);
		i++;
	}
	return (NULL);
}
