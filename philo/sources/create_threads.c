/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:00:12 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/18 21:06:22 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		if (pthread_create(&main->philo[i].thread, NULL, &routine, NULL) != 0)
			return (FALSE);
		i++;
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
