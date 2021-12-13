/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_limits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:51:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/13 12:18:12 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

long long	get_t_die(void)
{
	t_diner *diner;

	diner = get_diner();
	return (diner->t_die);
}

long long	get_t_sleep(void)
{
	t_diner *diner;

	diner = get_diner();
	return (diner->t_sleep);
}

long long	get_t_eat(void)
{
	t_diner *diner;

	diner = get_diner();
	return (diner->t_eat);
}
