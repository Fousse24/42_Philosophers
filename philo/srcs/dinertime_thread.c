/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinertime_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/10 19:11:29 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_manager(t_philo *philo)
{
	if (philo->state == SLEEPING)
	{
		if (get_time_between(philo->time_sleep, philo->start) >= get_t_sleep())
			philo_think(philo);
	}
	else if (philo->state == THINKING)
	{
		if (!pthread_mutex_lock(get_mutex(M_FORK)))
		{	
			if (diner_ask_for_forks(get_diner(), philo))
				philo_eat(philo);
			pthread_mutex_unlock(get_mutex(M_FORK));
		}
	}
	else if (philo->state == EATING)
	{
		if (get_time_between(philo->time_eat, philo->start) >= get_t_eat())
			philo_sleep(philo);
	}
	else if (get_time_between(philo->time_death, philo->start) >= get_t_die())
		philo_die(philo);
}

void	*philo_dinertime(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	gettimeofday(&philo->time_death, NULL);
	while (philo->state != DEAD)
	{	
		gettimeofday(&philo->start, NULL);
		philo_manager(philo);
		// while (get_time_since(philo->start) < 10000)
		//  	continue;
		// usleep(50);
	}
	return (0);
}

void	*waiter_dinertime(void *diner_ptr)
{
	t_diner	*diner;

	diner = (t_diner *)diner_ptr;
	while (!diner->diner_done)
	{
		if (is_diner_done(diner))
		{
			diner->diner_done = 1;
		}
	}
	printf("\nwe're done !");
	return (0);
}
