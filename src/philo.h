/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <pyammoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:39:32 by pyammoun          #+#    #+#             */
/*   Updated: 2022/08/31 15:47:12 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/types.h>

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_pthread;

typedef struct s_philo	t_philo;
struct s_philo {
	int			id;
	int 		eat_nb;
	long long 	last_meal;
	int 		r_fork;
	int 		l_fork;
	t_pthread	th;
};

typedef struct s_info	t_info;
struct s_info {
	int			nbphilo;
	long long	ttd;
	long long 	tte;
	long long 	tts;
	int 		musteat;
	t_philo		*philo;
	t_mutex		*fork;
	t_mutex		writing;
};

int		ft_atoi(const char *str);
int 	ft_creationphilo(t_info *info);
int		ft_mallocstruct(t_info *info);
void	*routine(void *arg);
int 	ft_starter(t_info *info);
int 	ft_creationmutex(t_info *info);

#endif