/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:26:55 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/21 20:32:33 by anolivei         ###   ########.fr       */
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
			usleep(10);
			routine_execute(main, i);
		}
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

	now = main->philo[main->n_thread].time_to_die;
	printf("%s%-10lld %-3d %-30s%s\n", color, now, id, status, RESET);
}
