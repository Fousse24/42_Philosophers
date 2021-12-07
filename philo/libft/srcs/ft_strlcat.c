/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:58:42 by sfournie          #+#    #+#             */
/*   Updated: 2021/09/17 19:42:24 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

// Concatenate (size) characters from (src) to (dst).
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	size_t	dstsize;

	i = 0;
	j = 0;
	if (dst == NULL)
		return (0);
	dstsize = ft_strlen(dst);
	while (dst[i] && i < (int)size)
		i++;
	if (dst[i])
		return (ft_strlen(src) + size);
	while (src != NULL && src[j] && (i + j) < ((int)size - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dstsize + ft_strlen(src));
}
