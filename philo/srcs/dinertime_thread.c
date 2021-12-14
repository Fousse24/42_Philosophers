/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinertime_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/14 00:06:57 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int		philo_can_act(t_philo *philo)
{
	t_diner *diner;
	t_philo	**philos;

	diner = get_diner();
	if (!diner || !philo || !diner->philos)
		return (0);
	philos = diner->philos;
	while (*philos)
	{
		if ((*philos)->next_action < philo->next_action)
			return (0);
		philos++;
	}
	return (1);
}

void	*philo_dinertime(void *philo_ptr)
{
	t_philo	*philo;
	t_diner *diner;

	philo = (t_philo *)philo_ptr;
	diner = get_diner();
	philo->next_death = diner->start_time_usec + get_t_die();
	philo_set_next_act(philo, philo->next_meal);
	while (philo->state != DEAD)
	{	
		// if (philo_can_act(philo))
			philo_state_manager(philo);
		// else
			usleep(THREAD_CD);
	}
	return (0);
}

void	*waiter_dinertime(void *diner_ptr)
{
	t_diner	*diner;
	int		wait;

	diner = (t_diner *)diner_ptr;
	diner->start_time = get_start_time();
	diner->start_time_usec = time_to_long(diner->start_time);
	diner->cur_meal = diner->start_time_usec;
	diner_first_service(diner);
	start_philo_threads(diner->philos);
	while (!diner->diner_done)
	{
		if (is_diner_done(diner))
		{
			diner->diner_done = 1;
		}
		usleep(THREAD_CD);
	}
	printf("\nwe're done !");
	return (0);
}
