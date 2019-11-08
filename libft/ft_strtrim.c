/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:45:46 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/08 16:05:07 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t i;
	unsigned char *ptr_1;
	unsigned char *ptr_2;

	if (dst == NULL && src == NULL)
		return (dst);
	ptr_1 = (unsigned char *)dst;
	ptr_2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(ptr_1 + i) = *(ptr_2 + i);
		i++;
	}
	return (dst);
}

size_t	find_charset_begin(char const *s1, char const *set)
{
	size_t i;

	i = 0;
	if ((char)s1[i] == (char)set[i])
	{
		while ((char)s1[i] && (char)set[i] && (char)s1[i] == (char)set[i] && i < ft_strlen((char*)set))
		{
			i++;
		}
	}
	if (i == ft_strlen((char*)set))
		return (i);
	return (0);
}

size_t	find_charset_end(char const *s1, char const *set)
{
	size_t i;
	size_t j;

	i = ft_strlen((char *)s1) - 1;
	j = ft_strlen((char *)set) - 1;
	if ((char)s1[i] == (char)set[j])
	{
		while ((char)s1[i] && (char)set[j] && (char)s1[i] == (char)set[j] && j > 0)
		{
			i--;
			j--;
		}
	}
	if (j == 0)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (find_charset_begin(s1, set) == 1 && find_charset_end(s1, set) == 1)
	{
		if(!(ptr = malloc(sizeof(char) * (ft_strlen(s1) - 2 * ft_strlen(set) + 1))))
			return (NULL);
		ft_memcpy(ptr, s1 + find_charset_begin(s1, set), sizeof(char) * ft_strlen(s1) - 2 * ft_strlen(set) + 1);
	}
	else if (find_charset_begin(s1, set) == 1)
	{
		if (!(ptr = malloc(sizeof(char) * (ft_strlen(s1) - 2 * ft_strlen(set) + 1))))
			return (NULL);
		ft_memcpy(ptr, s1 + find_charset_begin(s1, set), sizeof(char) * ft_strlen(s1) - ft_strlen(set)); // si charset at BEING : on copie vers ptr, en sautant les i premiers caractères car ce sont ceux du charset
	}
	else if (find_charset_end(s1, set) == 1)
	{
		if (!(ptr = malloc(sizeof(char) * (ft_strlen(s1) - 2 * ft_strlen(set) + 1))))
			return (NULL);
		ft_memcpy(ptr, s1, sizeof(char) * ft_strlen(s1) - 2 * ft_strlen(set) + 1);
	}
	else // si set pas trouvé renvoyer s1
	{
		if (!(ptr = malloc(sizeof(char) * (ft_strlen(s1)))))
			return (NULL);
		ft_memcpy(ptr, s1, sizeof(char) * (ft_strlen(s1)));
	}
	ptr[ft_strlen(ptr) - 1] = '\0'; // ajouter null-terminating character
	return (ptr);
}
