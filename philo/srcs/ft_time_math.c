/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:51:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/16 19:42:54 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

long long	get_time_since(t_time since)
{
	t_time	now;

	gettimeofday(&now, NULL);
	return (get_time_between(since, now));
}

long long	get_time_between(t_time early, t_time later)
{
	long long	time_early;
	long long	time_later;

	time_early = time_to_long(early);
	time_later = time_to_long(later);
	return (time_later - time_early);
}

long long	time_to_long(t_time time)
{
	long long	n;

	n = (time.tv_sec * 1000000) + time.tv_usec;
	return (n);
}

t_time	long_to_time(long long n)
{
	t_time	time;

	time.tv_sec = n / 1000000;
	time.tv_usec = n % 1000000;
	return (time);
}
