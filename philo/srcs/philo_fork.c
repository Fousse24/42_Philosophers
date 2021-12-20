/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:15:33 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/19 20:06:00 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	init_fork(t_fork *fork, int id)
{
	fork->owner = NULL;
	fork->id = id;
}

t_fork	*create_fork(void *owner, int id)
{
	t_fork	*fork;

	fork = (t_fork *)ft_calloc(1, sizeof(t_fork));
	if (fork)
	{
		init_fork(fork, id);
		fork->owner = owner;
		pthread_mutex_init(&fork->mutex, NULL);
	}
	return (fork);
}

void	change_fork_owner(t_fork *fork, t_philo *philo)
{
	pthread_mutex_lock(&fork->mutex);
	if (!fork->owner)
		fork->owner = philo;
	pthread_mutex_unlock(&fork->mutex);
}

t_fork	**create_fork_array(int n)
{
	int		i;
	t_fork	**forks;

	forks = (t_fork **)ft_calloc(n + 1, sizeof(t_fork *));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < n)
	{
		forks[i] = create_fork(NULL, i + 1);
		i++;
	}
	forks[i] = NULL;
	return (forks);
}

void	fork_clear(void *ptr)
{
	pthread_mutex_destroy(&((t_fork *)ptr)->mutex);
	free(ptr);
}
