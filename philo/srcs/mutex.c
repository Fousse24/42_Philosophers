/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:56:57 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/16 14:11:22 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

t_mutex	*get_mutex(int type)
{
	static t_mutex	mutex_print;
	static t_mutex	mutex_fork;
	static t_mutex	mutex_meal;
	static t_mutex	mutex_philo;

	if (type == M_PRINT)
		return (&mutex_print);
	if (type == M_FORK)
		return (&mutex_fork);
	if (type == M_MEAL)
		return (&mutex_meal);
	if (type == M_PHILO)
		return (&mutex_philo);
	else
		return (0);
}

void	init_mutexes(void)
{
	t_mutex	*mutex;

	mutex = get_mutex(M_PRINT);
	pthread_mutex_init(mutex, NULL);
	mutex = get_mutex(M_FORK);
	pthread_mutex_init(mutex, NULL);
	mutex = get_mutex(M_MEAL);
	pthread_mutex_init(mutex, NULL);
	mutex = get_mutex(M_PHILO);
	pthread_mutex_init(mutex, NULL);
}

void	destroy_mutexes(void)
{
	t_mutex	*mutex;

	mutex = get_mutex(M_PRINT);
	pthread_mutex_destroy(mutex);
	mutex = get_mutex(M_FORK);
	pthread_mutex_destroy(mutex);
	mutex = get_mutex(M_MEAL);
	pthread_mutex_destroy(mutex);
	mutex = get_mutex(M_PHILO);
	pthread_mutex_destroy(mutex);
}
