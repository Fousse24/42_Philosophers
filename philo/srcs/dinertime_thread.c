/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinertime_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/13 17:51:29 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	*philo_dinertime(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	gettimeofday(&philo->time_death, NULL);
	gettimeofday(&philo->time_eat, NULL);
	while (philo->state != DEAD)
	{	
		copy_time(get_diner_time(), &philo->start);
		philo_state_manager(philo);
		// while (get_time_since(philo->start) < 1000)
		//  	continue;
	}
	return (0);
}

void	adjust_diner_time(t_diner *diner)
{
	long long	n_current;
	long long	n_start;
	long long	diff;

	n_start = time_to_long(get_start_time());
	n_current = time_to_long(diner->cur_time);
	diff = n_current - n_start;
	if (diff > DINER_WAIT * diner->iter)
		diner->time_delay = (diff)  - (DINER_WAIT * diner->iter);
	// printf("| %lld - %lld - %lld |", diff, diner->iter, n_current - diner->time_delay);
	diner->cur_time = long_to_time(n_current - diner->time_delay);
	diner->iter++;

}

void	*waiter_dinertime(void *diner_ptr)
{
	t_diner	*diner;
	int		wait;

	diner = (t_diner *)diner_ptr;
	while (!diner->diner_done)
	{
		gettimeofday(&diner->cur_time, NULL);
		adjust_diner_time(diner);
		fork_check(diner);
		if (is_diner_done(diner))
		{
			diner->diner_done = 1;
		}
		usleep(DINER_WAIT);
	}
	printf("\nwe're done !");
	return (0);
}
