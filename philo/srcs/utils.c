/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:43:48 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/16 19:08:44 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	*ft_free_array(void **ptr, void (f)(void *))
{
	int	i;

	i = 0;
	if (ptr == NULL)
		return (NULL);
	if (ptr != NULL && ptr[i] != NULL && f != NULL)
	{
		f(ptr[i]);
	}
	free(ptr);
	return (NULL);
}

/* 
* Count the amount of element in a NULL-terminated array.
*
* if count reaches INT_MAX, it will return -1;
* this is to prevent an endless loop if the array is not terminated
*/
int	ft_array_size(void **arr)
{
	int	count;

	count = 0;
	while (arr && *arr)
	{
		arr++;
		count++;
		if (count == INT_MAX)
			return (-1);
	}
	return (count);
}

// Allocate memory (malloc) and set its content to '/0'
void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	ptr = (void *)malloc(size * num);
	if (ptr == NULL)
		return (NULL);
	memset(ptr, '\0', size);
	return (ptr);
}
