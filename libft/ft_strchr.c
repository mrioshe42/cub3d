/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:00:59 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:25:12 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
/*
int	main(void)
{
	const char	*s = "Hello world";
	char	*result = ft_strchr(s, 'o');

	if (result != NULL)
		printf("Found at position: %ld\n", result - s);
	else
		printf("Not found");
	return (0);
}*/
