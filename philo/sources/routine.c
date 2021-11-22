/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:26:55 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/21 23:25:06 by anolivei         ###   ########.fr       */
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
			routine_execute(main, i);
	}
	else
	{
		while (main->philo_dead == FALSE)
			routine_execute(main, i);
	}
	return (0);
}

int	routine_execute(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->forks[main->philo->fork.left]))
		return (FALSE);
	if (pthread_mutex_unlock(&main->forks[main->philo->fork.left]))
		return (FALSE);
	routine_print(main, main->philo[i].id, B_BLUE, L_FORK);
	if (pthread_mutex_lock(&main->forks[main->philo->fork.right]))
		return (FALSE);
	if (pthread_mutex_unlock(&main->forks[main->philo->fork.right]))
		return (FALSE);
	routine_print(main, main->philo[i].id, B_BLUE, R_FORK);
	routine_print(main, main->philo[i].id, G_CYAN, EAT);
	main->philo->time_to_die = get_time();
	main->philo[i].num_of_times_ate++;
	routine_print(main, main->philo[i].id, BLUE, SLEEP);
	routine_print(main, main->philo[i].id, G_BLUE, THINK);
	return (TRUE);
}

void	routine_print(t_main *main, int id, char *color, char *status)
{
	long long	now;

	now = get_time();
	(void)main;
	printf("%s%-10lld %-3d %-30s%s\n", color, now, id, status, RESET);
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
