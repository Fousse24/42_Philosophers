/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:53:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/17 18:58:47 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	<stdio.h>

static void	ft_fixminus(long long int *n, char *num, int count)
{
	if (*n == LONG_MIN)
	{
		num[count - 1] = *n % 10;
		*n = *n / 10;
	}
	*n *= -1;
	num[0] = '-';
}

char	*ft_llitoa(long long int n)
{
	char			*num;
	int				count;
	long long int	nl;

	nl = n;
	count = ft_countminus(nl);
	num = (char *)malloc(sizeof(char) * (count + 1));
	if (num == NULL)
		return (NULL);
	if (nl < 0)
		ft_fixminus(&nl, num, count);
	num[count] = '\0';
	if (n == 0)
		num[0] = '0';
	if (n == LONG_MIN)
		num[--count] = '8';
	while ((nl / 10) != 0 || (nl % 10) != 0)
	{
		num[--count] = (nl % 10) + '0';
		nl = nl / 10;
	}
	return (num);
}
