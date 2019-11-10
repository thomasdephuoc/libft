#include "libft.h"


int		nb_length(int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	unsigned int	number;
	char			*result;
	int				length;
	char			*base;

	if (nb < 0)
	{
		number = - nb;
		length = 1;
	}
	else
	{
		number = nb;
		length = 0;
	}
	length = length + nb_length(number);
	if (number == 0)
	{
		length = 1;
	}
	base = "0123456789";
	if (!(result = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	result[length] = '\0';
	length--;
	while (number > 0)
	{
		result[length] = base[number % 10];
		length--;
		number = number / 10;
	}
	if (nb < 0)
	{
		result[length] = '-';
	}
	if (nb == 0)
		result[0] = '0';
	return (result);
}
