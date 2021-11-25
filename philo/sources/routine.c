/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:26:55 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/25 00:00:51 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	i = main->n_thread;
	if (main->input.num_of_times_eat > 0)
	{
		while (main->input.num_of_times_eat > main->philo[i].num_of_times_ate)
		{
			if (routine_execute(main, i) == FALSE)
				return (0);
		}
	}
	else
	{
		while (main->philo_dead == FALSE)
		{
			if (routine_execute(main, i) == FALSE)
				return (0);
		}
	}
	return (0);
}

int	routine_execute(t_main *main, int i)
{
	if (philo_sleep(main, i) == FALSE)
		return (FALSE);
	if (philo_think(main, i) == FALSE)
		return (FALSE);
	if (philo_eat(main, i) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	routine_print(t_main *main, int id, char *color, char *status)
{
	long long	now;

	now = get_time();
	if (main->philo_dead == TRUE)
		return (FALSE);
	pthread_mutex_lock(&main->write);
	printf("%s%-10lld %-3d %-30s%s\n", color, now, id, status, RESET);
	pthread_mutex_unlock(&main->write);
	return (TRUE);
}

int	routine_usleep(t_main *main, long long time1)
{
	long long	time2;

	time2 = get_time();
	while (main->philo_dead == FALSE)
	{
		if (delta_time(time2) >= time1)
			return (FALSE);
		usleep(1000);
	}
	return (TRUE);
}
