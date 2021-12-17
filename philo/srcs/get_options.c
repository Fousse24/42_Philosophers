/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:51:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/16 19:42:44 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

long long	get_t_die(void)
{
	t_diner	*diner;

	diner = get_diner();
	return (diner->t_die);
}

long long	get_t_sleep(void)
{
	t_diner	*diner;

	diner = get_diner();
	return (diner->t_sleep);
}

long long	get_t_eat(void)
{
	t_diner	*diner;

	diner = get_diner();
	return (diner->t_eat);
}

int	get_n_eat(void)
{
	t_diner	*diner;

	diner = get_diner();
	return (diner->philo_n_eat);
}

int	get_n_philo(void)
{
	t_diner	*diner;

	diner = get_diner();
	return (diner->philo_n);
}
