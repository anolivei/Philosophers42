/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:10:58 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/08 22:43:59 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo_struct(int argc, char **argv, t_philo *philo)
{
	if (argc == 5 || argc == 6)
	{
		philo->num_of_philo = philo_atoi(argv[1]);
		printf("%i\n", philo->num_of_philo);
		philo->time_to_die = philo_atoi(argv[2]);
		philo->time_to_eat = philo_atoi(argv[3]);
		philo->time_to_sleep = philo_atoi(argv[4]);
		if (argc == 6)
			philo->num_of_times_each_philo_must_eat = philo_atoi(argv[5]);
		return (TRUE);
	}
	return (FALSE);
}

void	error_handling(int argc, char **argv, t_philo *philo)
{
	if (init_philo_struct(argc, argv, philo) == FALSE)
		printf("%sERROR: The number of argments must be 4 or 5%s\n",
			RED, RESET);
	else
	{
		if (!philo->num_of_philo)
			printf("%sERROR: There is a mistake in number of philosophers%s\n",
				RED, RESET);
		if (!philo->time_to_die)
			printf("%sERROR: There is a mistake in time to die%s\n",
				RED, RESET);
		if (!philo->time_to_eat)
			printf("%sERROR: There is a mistake in time to eat%s\n",
				RED, RESET);
		if (!philo->time_to_sleep)
			printf("%sERROR: There is a mistake in time to sleep%s\n",
				RED, RESET);
		if (argc == 6 && !philo->num_of_times_each_philo_must_eat)
			printf("%sERROR: There is a mistake in number \
of times each philosopher must eat%s\n", RED, RESET);
	}
}
