/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:05:55 by jle-doua          #+#    #+#             */
/*   Updated: 2024/08/02 15:16:55 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		count[2];
// 	char	*res;
// 	size_t	s1size;
// 	size_t	s2size;

// 	count[0] = 0;
// 	count[1] = 0;
// 	s1size = ft_strlen(s1);
// 	s2size = ft_strlen(s2);
// 	res = malloc(sizeof(char) * (s1size + s2size) + 1);
// 	if (!res)
// 		return (0);
// 	while (s1[count[1]])
// 		res[count[0]++] = s1[count[1]++];
// 	count[1] = 0;
// 	while (s2[count[1]])
// 		res[count[0]++] = s2[count[1]++];
// 	res[s1size + s2size] = '\0';
// 	return (res);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = -1;
	j = 0;
	if (!s2)
	{
		s2 = malloc(1);
		if (!s2)
			return (NULL);
		s2[0] = '\0';
	}
	if (!s1)
		return (ft_strdup(s2));
	res = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (res == NULL)
		return (free(s1), NULL);
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
