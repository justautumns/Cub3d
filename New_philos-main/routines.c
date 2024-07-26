/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:24:55 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/07/26 16:18:12 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	am_i_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	if ((int)(get_time() - philo->last_meal) >= philo->data->time_to_die)
		return (pthread_mutex_unlock(&philo->data->dead_mutex), 1);
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (0);
}

static int	eating2(t_philo *philo)
{
	// if (!philo->data->dead_flag && !philo->data->eat_enough)
	printings(philo, "is eating");
	pthread_mutex_lock(&philo->data->print_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->print_mutex);
	my_usleep(philo->data->time_to_eat, philo);
	//pthread_mutex_lock(&philo->data->print_mutex);
	philo->how_many_times_eated++;
	//pthread_mutex_unlock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->dead_mutex); // moved down
	if (philo->data->number_of_eatings == philo->how_many_times_eated)
	{
		philo->is_full = true;
		philo->data->all_full++;
	}
	pthread_mutex_unlock(&philo->data->dead_mutex); // moved down
	pthread_mutex_unlock(&philo->data->forks[philo->forks[1]]);
	pthread_mutex_unlock(&philo->data->forks[philo->forks[0]]);
	return (0);
}

static int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->is_full == true || philo->data->dead_flag == true)
		return (pthread_mutex_unlock(&philo->data->dead_mutex), -16);
	pthread_mutex_unlock(&philo->data->dead_mutex);
	pthread_mutex_lock(&philo->data->forks[philo->forks[0]]);
	if (am_i_dead(philo) == 1)
		return (pthread_mutex_unlock(&philo->data->forks[philo->forks[0]]),
			-16);
	printings(philo, "has taken left a fork");
	if (philo->data->number_of_philos == 1)
	{
		my_usleep(philo->data->time_to_die, philo);
		pthread_mutex_unlock(&philo->data->forks[philo->forks[0]]);
		return (printings(philo, "died"), -16);
	}
	pthread_mutex_lock(&philo->data->forks[philo->forks[1]]);
	if (am_i_dead(philo) == 1)
		return (pthread_mutex_unlock(&philo->data->forks[philo->forks[1]]),
			pthread_mutex_unlock(&philo->data->forks[philo->forks[0]]), -16);
	printings(philo, "has taken right a fork");
	eating2(philo);
	return (0);
}

static int	sleeping_thinking(t_philo *philo)
{
	time_t	think;

	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->is_full == true || philo->data->dead_flag == true)
		return (pthread_mutex_unlock(&philo->data->dead_mutex), -15);
	pthread_mutex_unlock(&philo->data->dead_mutex);
	think = ((philo->data->time_to_die - (philo->data->time_to_sleep
					+ philo->data->time_to_eat)) / 2);
	if (think <= 0)
		think = 1;
	if (am_i_dead(philo) == 1)
		return (-15);
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (!philo->data->dead_flag && !philo->is_full)
		printings(philo, "is sleeping");
	pthread_mutex_unlock(&philo->data->dead_mutex);
	my_usleep(philo->data->time_to_sleep, philo);
	if (am_i_dead(philo) == 1)
		return (-15);
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (!philo->data->dead_flag && !philo->is_full)
		printings(philo, "is thinking");
	pthread_mutex_unlock(&philo->data->dead_mutex);
	my_usleep(think, philo);
	return (0);
}

void	*philo_routines(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	// pthread_mutex_lock(&philo->data->print_mutex); // changed from dead_mutex (begin_time always used with prin_mutex)
	// philo->last_meal = philo->data->begin_time;
	// pthread_mutex_unlock(&philo->data->print_mutex);
	//even_f_times(philo->data->begin_time);
	if (philo->philo_id % 2)
		my_usleep(1, NULL); // ./philo 3 50 20 10 (was a problem with sleep 100)
	while (1)
	{
		if (eating(philo) == -16)
			break ;
		if (sleeping_thinking(philo) == -15)
			break ;
	}
	return (NULL);
}
