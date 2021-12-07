/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:08:52 by sfournie          #+#    #+#             */
/*   Updated: 2021/11/25 18:34:01 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
*	String to Integer. Return 0 if above/below integer limits,
*	or if $nptr is NULL
*/
int	ft_atoi(const char *nptr)
{
	int		neg;
	long	number;

	neg = 1;
	number = 0;
	if (nptr == NULL)
		return (0);
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			neg *= -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr) == 1)
	{
		number = number * 10 + (*nptr - 48);
		nptr++;
		if ((number * neg) > INT_MAX)
			return (0);
		if ((number * neg) < INT_MIN)
			return (0);
	}
	return (number * neg);
}
