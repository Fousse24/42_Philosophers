/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/07 14:01:38 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(void)
{
	int		philo_n;
	int		thread_status;
	t_dlst	*philo_list;
	t_diner	*diner;
	p_mutex	mutex;

	philo_n = PHILO_N;
	init_philo_list(&philo_list, philo_n);
	diner = get_diner();
	diner->philo_list = philo_list;
	diner->all_forks = create_fork_array(philo_n);
	assign_forks(diner->all_forks, diner->philo_list);
	start_philo_threads(philo_list);
	print_diner_info(diner);
	pthread_join(diner->thread, NULL);
	return (0);
}
