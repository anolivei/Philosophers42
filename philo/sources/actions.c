/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:13:35 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/26 23:58:01 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.left]))
		return (FALSE);
	if (routine_print(main, main->philo[i].id, B_BLUE, FORK) == FALSE)
		return (FALSE);
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.right]))
		return (FALSE);
	if (routine_print(main, main->philo[i].id, B_BLUE, FORK) == FALSE)
		return (FALSE);
	if (routine_print(main, main->philo[i].id, G_CYAN, EAT) == FALSE)
		return (FALSE);
	main->philo->time_to_die = get_time();
	exec_action(main->input.time_to_eat);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]))
		return (FALSE);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]))
		return (FALSE);
	main->philo[i].num_of_times_ate++;
	return (TRUE);
}

int	philo_sleep(t_main *main, int i)
{
	if (routine_print(main, main->philo[i].id, BLUE, SLEEP) == FALSE)
		return (FALSE);
	exec_action(main->input.time_to_sleep);
	return (TRUE);
}

int	philo_think(t_main *main, int i)
{
	if (routine_print(main, main->philo[i].id, G_BLUE, THINK) == FALSE)
		return (FALSE);
	return (TRUE);
}

void	exec_action(long long time)
{
	usleep(time * 1000);
}
