/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:26:04 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:25:49 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			ptr = (char *)(s + i);
		i++;
	}
	if (s[i] == c)
		ptr = (char *)(s + i);
	return (ptr);
}
/*
int	main(void)
{
	const char	*s = "Hello world";
	char	*result = ft_strrchr(s, 'q');

	if (result != NULL)
		printf("Last occurence found at: %ld", result - s);
	else
		printf("Not found");
	return (0);
}*/
