/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/16 19:08:18 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(int argn, char **argv)
{
	int		philo_n;
	t_philo	**philos;
	t_diner	*diner;

	diner = get_diner();
	if (parse_argv(argn - 1, &argv[1]))
	{
		philo_n = get_n_philo();
		philos = (t_philo **)ft_calloc(philo_n + 1, sizeof(t_philo *));
		init_philo_array(philos, philo_n);
		diner->philos = philos;
		diner->all_forks = create_fork_array(philo_n);
		assign_forks(diner->all_forks, diner->philos);
		init_mutexes();
		start_diner_thread(diner);
		pthread_join(diner->thread, NULL);
	}
	return (0);
}
