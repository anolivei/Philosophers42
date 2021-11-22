/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:00:12 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/21 23:25:01 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_main *main)
{
	int	i;

	i = 0;
	main->philo_dead = FALSE;
	while (i < main->input.num_philo)
	{
		main->n_thread = i;
		if (pthread_create(&main->philo[i].thread,
				NULL, &routine, (void *) main) != 0)
			return (FALSE);
		i++;
		usleep(1000);
	}
	i = 0;
	while (i < main->input.num_philo)
	{
		if (pthread_join(main->philo[i].thread, NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	destroy_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		if (pthread_mutex_destroy(&main->forks[i]) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
