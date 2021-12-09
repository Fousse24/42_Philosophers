/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:56:57 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/09 15:52:42 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

/*
* Mutex id are :
*
*/
p_mutex	*get_mutex(e_mutex type)
{
	static p_mutex	mutex_print;
	static p_mutex	mutex_fork;

	if (type == M_PRINT)	
		return (&mutex_print);
	if (type == M_FORK)	
		return (&mutex_fork);
	else
		return (0);
}

void	init_mutexes(void)
{
	p_mutex	*mutex;

	mutex = get_mutex(M_PRINT);
	pthread_mutex_init(mutex, NULL);
	mutex = get_mutex(M_FORK);
	pthread_mutex_init(mutex, NULL);
}

void	destroy_mutexes(void)
{
	p_mutex	*mutex;

	mutex = get_mutex(M_PRINT);
	pthread_mutex_destroy(mutex);
	mutex = get_mutex(M_FORK);
	pthread_mutex_destroy(mutex);
}
