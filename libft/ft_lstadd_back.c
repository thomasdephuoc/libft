/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:52:26 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/11 19:04:28 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*node;

	if (alst && new)
	{
		new->next = NULL;
		if (alst == NULL)
		{
			alst = &new;
			return ;
		}
		node = *alst;
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
}
