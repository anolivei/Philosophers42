/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:26:55 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/21 15:33:42 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_main	*main;

	main = (t_main *)args;
	routine_execute(main);
	return (0);
}

int	routine_execute(t_main *main)
{
	if (pthread_mutex_lock(&main->forks[main->philo->fork.left]))
		return (FALSE);
	if (pthread_mutex_unlock(&main->forks[main->philo->fork.left]))
		return (FALSE);
	routine_print(main, main->philo[main->n_thread].id, B_BLUE, L_FORK);
	if (pthread_mutex_lock(&main->forks[main->philo->fork.left]))
		return (FALSE);
	if (pthread_mutex_unlock(&main->forks[main->philo->fork.right]))
		return (FALSE);
	routine_print(main, main->philo[main->n_thread].id, B_BLUE, R_FORK);
	routine_print(main, main->philo[main->n_thread].id, G_CYAN, EAT);
	main->philo->time_to_die = get_time();
	main->num_of_times_ate++;
	routine_print(main, main->philo[main->n_thread].id, BLUE, SLEEP);
	routine_print(main, main->philo[main->n_thread].id, G_BLUE, THINK);
	return (TRUE);
}

void	routine_print(t_main *main, int id, char *color, char *status)
{
	long long	now;

	now = main->philo[main->n_thread].time_to_die;
	printf("%s%-10lld %-3d %-30s%s\n", color, now, id, status, RESET);
}
