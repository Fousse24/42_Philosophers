/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:52:22 by sfournie          #+#    #+#             */
/*   Updated: 2021/11/25 18:48:11 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
*	Create a new string by joining $s1 and $s2.
*	if free1/free2 are set to anything other than 0,
*	str1 or/and str2 will be freed.
*/
char	*ft_strjoin(char const *s1, char const *s2, int f1, int f2)
{
	int		i;
	size_t	size;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	while (s1 && *s1)
		str[i++] = *(s1++);
	while (s2 && *s2)
		str[i++] = *(s2++);
	if (f1)
		ft_free((void *)s1);
	if (f2)
		ft_free((void *)s2);
	str[i] = '\0';
	return (str);
}
