/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:40:51 by sfournie          #+#    #+#             */
/*   Updated: 2021/11/25 18:32:58 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i] != NULL)
		free(split[i++]);
	free(split);
	return (NULL);
}
