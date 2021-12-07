/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:53:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/17 19:00:02 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

// Int to Str. Use its own countdigits to handle negatives.
char	*ft_itoa(int n)
{
	char	*num;
	int		count;
	long	nl;

	nl = n;
	count = ft_countminus(nl);
	num = (char *)malloc(sizeof(char) * (count + 1));
	if (num == NULL)
		return (NULL);
	if (nl < 0)
	{
		nl *= -1;
		num[0] = '-';
		count++;
	}
	num[count] = '\0';
	if (n == 0)
		num[0] = '0';
	while ((nl / 10) != 0 || (nl % 10) != 0)
	{
		num[--count] = (nl % 10) + '0';
		nl = nl / 10;
	}
	return (num);
}
