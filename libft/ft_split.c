/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:27:45 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/07 17:59:25 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_copy_words(char const *str, char c)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	ft_strlcpy(result, (char *)str, i + 1);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		num_words;
	int		i;

	num_words = ft_count_words(s, c);
	result = malloc(sizeof(char *) * (num_words + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < num_words)
	{
		while (s[0] == c)
			s++;
		result[i] = ft_copy_words(s, c);
		if (result[i] == NULL)
		{
			free(result);
			return (NULL);
		}
		s += ft_strlen(result[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
/*
int	main(void)
{
	const char *s = "one,two,three,four";
	char	**split = ft_split(s, ',');
	int	i = 0;
	while (split[i] != NULL)
	{
		printf("%s\n", split[i]);
		i++;
	}
	return (0);
}*/
