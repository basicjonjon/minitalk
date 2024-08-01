/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:02:15 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:26:56 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (temp == NULL)
		return (0);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
