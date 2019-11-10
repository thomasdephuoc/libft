#include "libft.h"
int ft_strlennn(char const *str)
{
	int i;
	i = 0;
	while (str[i])
		++i;
	return (i);
}
int check_charset(char *set, char c)
{
	int i;
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}
int start_trim(char const *s1, char const *set)
{
	int i;
	i = 0;
	while (s1[i] && check_charset((char *)set, (char)s1[i]) == 1)
		++i;
	if (s1[i] == '\0')
		return (-1);
	return (i);
}
int end_trim(char const *s1, char const *set)
{
	int i;
	int j;
	i = 0;
	j = 0;
	while (s1[i])
		++i;
	--i;
	while (i > 0 && (check_charset((char *)set, (char)s1[i]) == 1))
	{
		--i;
		++j;
	}
	return (j);
}
char *ft_strtrim(char const *s1, char const *set)
{
	int start;
	int end;
	int i;
	char *str;
	i = 0;
	start = start_trim(s1, set);
	end = ft_strlennn(s1) - end_trim(s1, set);
	if (start == -1)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (!(str = malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	while (start < end)
	{
		str[i] = (char)s1[start];
		++i;
		++start;
	}
	str[i] = '\0';
	return (str);
}
