/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:26:55 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/18 22:03:25 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	(void)args;
	printf("%s%s%s\n", BLUE, SLEEP, RESET);
	printf("%s%s%s\n", G_BLUE, THINK, RESET);
	printf("%s%s%s\n", G_CYAN, EAT, RESET);
	printf("%s%s%s\n", B_BLUE, L_FORK, RESET);
	printf("%s%s%s\n", B_BLUE, R_FORK, RESET);
	printf("%s%s%s\n", GREEN, OK, RESET);
	printf("%s%s%s\n", PINK, DIED, RESET);
	return (0);
}
