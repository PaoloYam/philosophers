/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:54:01 by pyammoun          #+#    #+#             */
/*   Updated: 2022/09/29 16:43:43 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	long long	actual_time;

	actual_time = ft_gettime();
	while (philo->info->tts > (ft_gettime() - actual_time))
		usleep(100);
	if (philo->info->dead == 0 && philo->info->all_eat == 0)
		ft_print_action(philo, 3);
}

void	ft_eat_time(t_philo *philo)
{
	long long	actual_time;

	actual_time = ft_gettime();
	while (philo->info->tte > (ft_gettime() - actual_time))
		usleep(100);
	if (philo->info->dead == 0 && philo->info->all_eat == 0)
		ft_print_action(philo, 2);
}

void	ft_death_time(t_philo *philo)
{
	long long	actual_time;

	actual_time = ft_gettime();
	while (philo->info->ttd > (ft_gettime() - actual_time))
		usleep(100);
	ft_print_action(philo, 5);
}

int	ft_eating(t_philo *philo)
{
	int	i;

	i = 0;
	if (pthread_mutex_lock(&(philo->info->fork[philo->r_fork])) != 0)
		printf("error\n");
	if (philo->info->dead == 0 && philo->info->all_eat == 0)
		ft_print_action(philo, 1);
	if (philo->l_fork != -1000)
		pthread_mutex_lock(&(philo->info->fork[philo->l_fork]));
	else
		return (2);
	if (philo->info->dead == 0 && philo->info->all_eat == 0)
		ft_print_action(philo, 1);
	philo->last_meal = ft_gettime();
	ft_eat_time(philo);
	philo->eat_nb += 1;
	pthread_mutex_unlock(&(philo->info->fork[philo->r_fork]));
	pthread_mutex_unlock(&(philo->info->fork[philo->l_fork]));
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*philou;

	philou = (t_philo *)philo;
	philou->last_meal = ft_gettime();
	if (philou->id % 2 != 0)
		usleep(100);
	while (philou->info->all_eat != 1 && philou->info->dead != 1)
	{
		if (philou->info->dead == 0 && ft_eating(philou) == 2)
		{
			ft_death_time(philou);
			philou->info->dead = 1;
		}
		if (philou->info->dead != 0 && philou->info->all_eat == 0)
			return (0);
		if (ft_eatchecker(philou->info))
			return (0);
		if (philou->info->dead == 0 && philou->info->all_eat == 0)
			ft_sleep(philou);
		if (philou->info->dead == 0 && philou->info->all_eat == 0)
			ft_print_action(philou, 4);
	}
	return (0);
}
