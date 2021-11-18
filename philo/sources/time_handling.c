/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:11:32 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/17 22:04:45 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** tv_sec is in seconds, 1 second = 1000 milliseconds
** tv_usec is in microseconds, 1 microsecond = 0.001 milliseconds
*/

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

int	delta_time(long long time1)
{
	if (time1 > 0)
		return (get_time() - time1);
	return (FALSE);
}
