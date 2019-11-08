/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-phuo <tde-phuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:45:46 by tde-phuo          #+#    #+#             */
/*   Updated: 2019/11/08 19:15:13 by tde-phuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	trim_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
void	*trim_memcpy(void *restrict dst, const void *restrict src, size_t n)
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

*/

int		find_begin(char const *s1, char const *set)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while ((char)s1[i])
	{
		while ((char)s1[i] != (char)set[j] && (char)set[j])
			j++;
		if ((char)s1[i] == (char)set[j])
			j = 0;
		if ((char)set[j] == '\0')
			break;
		i++;
	}
	if ((char)s1[i] == '\0')
		return (-1);
	return (i);
}

/*
** Returns position of the first character of the charset if charset is found
** if looking for "yop" in "helloyop", will return 5
*/

size_t find_end(char const *s1, char const *set)
{
	size_t i;
	size_t j;

	i = trim_strlen((char *)s1) - 1;
	j = 0;
	while ((char)s1[i])
	{
		while ((char)s1[i] != (char)set[j] && (char)set[j])
			j++;
		if ((char)s1[i] == (char)set[j])
			j = 0;
		if ((char)set[j] == '\0')
			break;
		i--;
	}
	return (i);
}

char *ft_strtrim(char const *s1, char const *set)
{
	int begin;
	int end;
	int i;
	char *ptr;

	i = 0;
	begin = find_begin(s1, set);
	end = find_end(s1, set);
	if (begin == -1)
	{
		if (!(ptr = malloc(sizeof(char) * 1)))
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (!(ptr = malloc(sizeof(char) * (end - begin + 1))))
	{
		return (NULL);
	}
	while (begin < end + 1)
	{
		ptr[i] = (char)s1[begin];
		++i;
		++begin;
	}
	ptr[i] = '\0';
	return (ptr);
}
