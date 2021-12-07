/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:22:45 by sfournie          #+#    #+#             */
/*   Updated: 2021/11/25 18:49:47 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

// Compare (n) characters in both strings. Return 0 if equal.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n <= 0)
		return (0);
	if (!s1 && !s2)
		return (0);
	else if (!s1 && s2)
		return (-1);
	else if (s1 && !s2)
		return (1);
	while (n-- > 0 && *s1 == *s2)
	{
		if (*s1 == '\0' || *s2 == '\0' || n == 0)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
