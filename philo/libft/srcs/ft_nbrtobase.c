/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtobase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:06:24 by sfournie          #+#    #+#             */
/*   Updated: 2021/11/25 18:44:17 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* invalid : size below or equal to 1, base has duplicates   */
static int	ft_validbase(char *base)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = ft_strlen(base);
	if (size <= 1)
		return (0);
	while (i < size)
	{
		while (j < size)
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	ft_convert(char *dst, unsigned long nbr, char *base, int size)
{
	int	i;

	i = 0;
	if (nbr / size != 0)
		i = ft_convert(dst, nbr / size, base, size);
	dst[i] = base[(nbr % size)];
	return (i + 1);
}

// Convert $nbr into a malloced string to the specified $base 
char	*ft_nbrtobase(unsigned long nbr, char *base)
{
	int		b_size;
	int		size;
	char	*ptr;

	if (base == NULL)
		return (NULL);
	b_size = ft_strlen(base);
	size = (ft_countdigits(nbr) * 10 / b_size) + 1;
	if (10 % b_size == 0)
		size--;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, '\0', size + 1);
	if (!ft_validbase(base))
		return (NULL);
	ft_convert(ptr, nbr, base, b_size);
	return (ptr);
}
