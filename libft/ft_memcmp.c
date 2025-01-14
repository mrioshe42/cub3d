/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:09:01 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:27:40 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ts1;
	const unsigned char	*ts2;
	size_t				i;

	i = 0;
	ts1 = (const unsigned char *)s1;
	ts2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (ts1[i] != ts2[i])
			return (ts1[i] - ts2[i]);
		i++;
	}
	return (0);
}
/*
#include <unistd.h>

int	main(void)
{
	const char	*s1 = "Hello world";
	const char	*s2 = "Hello planet";
	int	result;

	result = ft_memcmp(s1, s2, 6);

	if (result == 0)
		write(1, "Equals", 6);
	else if (result > 0)
		write(1, "First is bigger", 15);
	else
		write(1, "Second is bigger", 16);
	return (0);
}*/
