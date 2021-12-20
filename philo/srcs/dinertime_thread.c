/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinertime_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/19 19:47:14 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	*philo_dinertime(void *philo_ptr)
{
	t_philo	*philo;
	t_diner	*diner;

	philo = (t_philo *)philo_ptr;
	diner = get_diner();
	philo->next_death = diner->start_time_usec + get_t_die();
	if (diner->philo_n == 1)
		philo->next_meal = diner->start_time_usec + get_t_die();
	philo_set_next_act(philo, philo->next_meal);
	philo_change_state(philo, THINKING, diner->start_time_usec);
	while (!diner->diner_done && philo->state != DEAD)
	{	
		philo_state_manager(philo);
		if (!diner->diner_done)
			usleep(get_philo_cd(philo));
	}
	return (0);
}

void	*waiter_dinertime(void *diner_ptr)
{
	t_diner	*diner;

	diner = (t_diner *)diner_ptr;
	diner->start_time = get_start_time();
	diner->start_time_usec = time_to_long(diner->start_time);
	diner->cur_meal = diner->start_time_usec;
	diner_first_service(diner);
	if (diner->time_eaten == diner->philo_n_eat)
		diner->diner_done = 1;
	else
		start_philo_threads(diner->philos);
	while (!diner->diner_done)
		usleep(THREAD_CD);
	destroy_mutexes();
	free_diner(get_diner());
	return (0);
}
