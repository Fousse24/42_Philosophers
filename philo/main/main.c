/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/09 18:43:36 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(void)
{
	int		philo_n;
	int		thread_status;
	t_philo	**philos;
	t_diner	*diner;

	philo_n = PHILO_N;
	philos = (t_philo **)ft_calloc(philo_n + 1, sizeof(t_philo *));
	init_philo_array(philos, philo_n);
	diner = get_diner();
	diner->philos = philos;
	diner->all_forks = create_fork_array(philo_n);
	assign_forks(diner->all_forks, diner->philos);
	init_mutexes();
	start_philo_threads(diner->philos);
	start_diner_thread(diner);
	// print_diner_info(diner);
	pthread_join(diner->thread, NULL);
	// destroy_mutex(get_mutex());
	return (0);
}
