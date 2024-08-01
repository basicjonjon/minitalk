/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:05:22 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:31:25 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (dst[i] != '\0' && i < n)
		i++;
	y = i;
	while (src[i - y] != '\0' && i < n - 1)
	{
		dst[i] = src[i - y];
		i++;
	}
	if (y < n)
		dst[i] = '\0';
	return (y + ft_strlen(src));
}
