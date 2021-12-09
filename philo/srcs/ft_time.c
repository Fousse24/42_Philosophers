/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:51:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/09 16:27:21 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

t_time	get_start_time(void)
{
	static t_time	start;
	static int		init;

	if (!init)
	{
		gettimeofday(&start, NULL);
		init = 1;
	}
	return (start);
}

long long	get_ms_time_since(t_time since)
{
	t_time		now;
	long long	time_since;
	long long	time_now;

	gettimeofday(&now, NULL);
	time_since = ((since.tv_sec * 1000000) + since.tv_usec) / 1000;
	time_now = ((now.tv_sec * 1000000) + now.tv_usec) / 1000;
	return (time_now - time_since);
}