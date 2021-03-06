/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:22:02 by sfournie          #+#    #+#             */
/*   Updated: 2022/01/25 15:34:15 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// start the threads nested in the philosophers objects
void	start_philo_threads(t_philo **philos)
{
	int	error;
	int	i;

	if (!philos)
		return ;
	error = 0;
	i = 0;
	while (philos && philos[i])
	{
		pthread_create(&philos[i]->thread, NULL, &philo_dinertime, philos[i]);
		i++;
		if (error++ == INT_MAX)
			return ;
	}
}

void	kill_philo_threads(t_philo **philos)
{
	int	i;

	if (!philos)
		return ;
	i = 0;
	while (philos && philos[i])
	{
		pthread_kill(philos[i]->thread, 0);
		i++;
	}
}

// start the thread nested in the diner object
void	start_diner_thread(t_diner *diner)
{
	if (!diner)
		return ;
	pthread_create(&diner->thread, NULL, &waiter_dinertime, diner);
}

void	thread_cooldown(void)
{
	usleep(50);
}
