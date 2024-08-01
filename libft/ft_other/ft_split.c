/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:22:35 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:26:49 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_split_length(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static void	*ft_freeall(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (NULL);
}

static char	**ft_init_res(char const *s, char c, int *res_len)
{
	char	**res;

	*res_len = ft_split_length(s, c);
	res = malloc(sizeof(char *) * (unsigned long)(*res_len + 1));
	if (!res)
		return (NULL);
	return (res);
}

static void	ft_init_counter(int *i, int *y, int *z)
{
	*i = 0;
	*y = 0;
	*z = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		y;
	int		z;
	int		res_len;

	ft_init_counter(&i, &y, &z);
	res = ft_init_res(s, c, &res_len);
	if (!res)
		return (NULL);
	while (z < res_len)
	{
		while (s[i] == c)
			i++;
		y = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		res[z] = malloc(sizeof(char) * (i - y + 1));
		if (!res[z])
			return (ft_freeall(res));
		ft_strlcpy(res[z], &s[y], (i - y + 1));
		z++;
	}
	res[z] = NULL;
	return (res);
}
