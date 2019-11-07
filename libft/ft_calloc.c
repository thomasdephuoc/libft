/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:11:54 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/07 16:00:18 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	if (!(ptr = malloc(count * size)))
		return (NULL);
	while (i <= count)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
