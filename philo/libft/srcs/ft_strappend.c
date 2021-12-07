/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:58:42 by sfournie          #+#    #+#             */
/*   Updated: 2021/11/25 18:45:45 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* 
*	Return a string with the content of $dst and $len characters from $src.
*	Free $dst if $f is not 0.
*/
char	*ft_strappend(char *dst, const char *src, int len, int f)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (len > (int)ft_strlen(src))
		len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (ft_strlen(dst) + len + 1));
	while (dst && dst[i])
	{
		str[i] = dst[i];
		i++;
	}
	while (src && src[j] && j < len)
	{
		str[i++] = src[j++];
	}
	str[i] = '\0';
	if (f)
		ft_free(dst);
	return (str);
}
