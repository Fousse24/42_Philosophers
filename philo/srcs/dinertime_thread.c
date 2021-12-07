/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinertime_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/07 14:05:22 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	*philo_dinertime(void *philo_ptr)
{
	t_philo	*philo;

	if (philo->time_left <= 0)
		philo->state = DEAD;
	else
	{
		
	}
	return (0);
}

void	*waiter_dinertime(void *diner_ptr)
{
	// t_philo *philo;

	// philo = (t_philo *)philo_ptr;
	
	// while (philo->time_left-- > 0)
	// {
	// 	printf("%lld : Philo %d is gonna die %d cause this program kinda sucks\n", (long long)get_ms_time_since(get_start_time()), philo->id, philo->time_left);
	// 	usleep(100);
	// }
	// printf("dead\n");
	return (0);
}
