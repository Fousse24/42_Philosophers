/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:25:09 by sfournie          #+#    #+#             */
/*   Updated: 2021/11/25 18:46:24 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

// Return the address of the first occurence of (c) in (s);
char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s || (!*s && c))
		return (0);
	i = 0;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
