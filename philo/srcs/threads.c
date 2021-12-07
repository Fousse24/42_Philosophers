/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:22:02 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/07 13:55:42 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// start the threads nested in the philosophers objects
void	start_philo_threads(t_dlst *philo_list)
{
	t_philo	*philo;
	int		last_id;

	if (!philo_list)
		return ;
	philo = (t_philo *)philo_list->content;
	while (philo_list)
	{
		if (philo)
			pthread_create(&philo->thread, NULL, &philo_dinertime, philo);
		else
			break;
		philo_list = philo_list->next;
		if (!philo_list || !philo_list->next || !philo_list->next->content)
			break;
		last_id = philo->id;
		philo = (t_philo *)philo_list->content;
		if (!philo || philo->id < last_id)
			break;
	}
}

// start the thread nested in the diner object
void	start_diner_thread(t_diner *diner)
{
	if (!diner)
		return ;
	pthread_create(&diner->thread, NULL, &waiter_dinertime, diner);
}
