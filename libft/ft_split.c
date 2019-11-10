

#include "libft.h"

int		word_count(const char *str, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	if (str[i] != '\0' && str[i] != c)
		count++;
	if (str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i - 1] != c)
			count++;
		i++;
	}
	if (str[i - 1] == c && count)
		count--;
	return (count);
}

/*
** Tests whether str[i] is the beginning of a word
** Calculates its length if so and puts it in a tab
*/

int		*calc_word_length(const char *str, char c)
{
	int i;
	int index;
	int nb_words;
	int *word_length;

	i = -1;
	nb_words = word_count(str, c);
	if (nb_words == 0)
		return (0);
	if(!(word_length = malloc(nb_words * sizeof(int))))
		return(NULL); // FREE MEMORY
	while (++i < nb_words)
		word_length[i] = 0;
	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			word_length[index]++;
		else if (i > 0 && str[i - 1] != c)
			index++;
		i++;
	}
	return (word_length);
}

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	int		i;
	int		no_char;
	int		*word_length;
	char	**return_str;

	if (!s)
		return (NULL);
	nb_words = word_count(s, c);
	return_str = NULL;
	word_length = calc_word_length(s, c);
	if (!(return_str = (char**)malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL); // FREE MEMORY of return_str and word_length
	i = -1;
	no_char = 0;
	while (++i < nb_words)
	{
		while (s[no_char] != '\0' && s[no_char] == c)
			no_char++;
		if (!(return_str[i] = (char*)malloc(sizeof(char) * (word_length[i] + 1))))
			return (NULL); // FREE MEMORY of return_str and word_length
		ft_strncpy(return_str[i], &s[no_char], word_length[i]);
		return_str[i][word_length[i]] = '\0';
		no_char = no_char + word_length[i];
	}
	return_str[nb_words] = NULL;
	// FREE MEMORY of word_length
	return (return_str);
}
