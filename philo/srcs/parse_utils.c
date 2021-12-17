/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:16:13 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/16 19:42:08 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	ft_isnumber(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

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
