/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinertime_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/09 18:39:21 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int		diner_ask_for_forks(t_philo *philo, t_diner *diner)
{
	if (!philo->left_fork->owner && !philo->right_fork->owner)
		return (1);
	return (0);
}

void	*philo_dinertime(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	gettimeofday(&philo->last_run, NULL);
	gettimeofday(&philo->time_death, NULL);
	while (philo->state != DEAD)
	{
		philo_manager(philo);
		while (get_ms_time_since(philo->last_run) < 100)
			thread_cooldown();
		gettimeofday(&philo->last_run, NULL);
	}
	return (0);
}

void	*waiter_dinertime(void *diner_ptr)
{
	t_diner	*diner;

	diner = (t_diner *)diner_ptr;
	while (!diner->diner_done)
	{
		
	}
	return (0);
}
