#include "cub.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;
	char	*ret_dup;

	len = 0;
	while (s[len] != '\0')
		len++;
	ret_dup = malloc((len + 1) * sizeof(char));
	if (!ret_dup)
		return (0);
	dup = ret_dup;
	while (*s)
		*dup++ = *s++;
	*dup = '\0';
	return (ret_dup);
}

void	free_env(char ***env)
{
	int	i;

	i = 0;
	if (!*env)
		return ;
	while ((*env)[i])
	{
		free((*env)[i]);
		i++;
	}
	free(*env);
	*env = NULL;
}

char	**add_to_array(char **arr, char *str)
{
	char	**temp;
	int		size;

	size = 0;
	if (!str)
		return (arr);
	while (arr[size])
		size++;
	temp = malloc((size + 2) * sizeof(char *));
	if (!temp)
		return (free_env(&arr), NULL);
	size = 0;
	while (arr[size])
	{
		temp[size] = ft_strdup(arr[size]);
		if (!temp[size])
			return (free_env(&arr), free_env(&temp), NULL);
		size++;
	}
	temp[size] = ft_strdup(str);
	if (!temp[size])
		return (free_env(&arr), free_env(&temp), NULL);
	temp[size + 1] = NULL;
	free_env(&arr);
	return (temp);
}
