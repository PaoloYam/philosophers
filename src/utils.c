/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:47:01 by pyammoun          #+#    #+#             */
/*   Updated: 2022/09/22 10:47:17 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	r;

	i = 0;
	m = 1;
	r = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			m = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (m * r);
}

long long	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + (time.tv_usec / 1000));
}

void	ft_print_action(t_philo *philo, int c)
{
	pthread_mutex_lock(&philo->info->writing);
	if (c == 1)
		printf("%s%lld %d %s\n", "\033[0;33m",
			ft_gettime() - philo->info->start_time,
			philo->id + 1, "has taken a fork");
	if (c == 2)
		printf("%s%lld %d %s\n", "\033[0;32m",
			ft_gettime() - philo->info->start_time,
			philo->id + 1, "is eating");
	if (c == 3)
		printf("%s%lld %d %s\n", "\033[0;35m",
			ft_gettime() - philo->info->start_time,
			philo->id + 1, "is sleeping");
	if (c == 4)
		printf("%s%lld %d %s\n", "\033[0;34m",
			ft_gettime() - philo->info->start_time,
			philo->id + 1, "is thinking");
	if (c == 5)
		printf("%s%lld %d %s\n", "\033[0;31m",
			ft_gettime() - philo->info->start_time,
			philo->id + 1, "is dead");
	pthread_mutex_unlock(&philo->info->writing);
}
