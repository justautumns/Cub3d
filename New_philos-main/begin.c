/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:24:12 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/07/26 15:45:20 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*test_routine(void *pointer)
{
	t_data	*data;

	data = (t_data *)pointer;
	pthread_mutex_lock(&data->dead_mutex);
	printf("deneme \n");
	my_usleep(1000, NULL);
	pthread_mutex_unlock(&data->dead_mutex);
	return (NULL);
}

int	thread_create(t_data *data)
{
	int		m;

	m = 0;
	data->begin_time = get_time(); // + (data->number_of_philos * 10);
	while (m < data->number_of_philos)
	{
		data->philos[m].last_meal = get_time(); // added here insted of in routine, cause sometimes last meal was equal 0 and philo was dying immediately (./philo 3 800 200 200 2)
		if (pthread_create(&data->philos[m].thread, NULL,
				&philo_routines, &data->philos[m]) != 0)
		{
			data->f_something_happens = true;
			return (-1);
		}
		m++;
	}
	if (data->number_of_philos > 1)
	{
		if (pthread_create(&data->monitor, NULL, &doch_sauron, data) != 0)
			return (-1);
	}
	return (0);
}

void	threads_join(t_data *data)
{
	int	m;

	m = 0;
	while (m < data->number_of_philos)
	{
		pthread_join(data->philos[m].thread, NULL);
		if (data->f_something_happens == true)
			break ;
		m++;
	}
	if (data->number_of_philos > 1)
		pthread_join(data->monitor, NULL);
}
