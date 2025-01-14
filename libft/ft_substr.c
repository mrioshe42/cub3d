/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:54:56 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:33:30 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	length;

	length = ft_strlen(str);
	if (!str)
		return (NULL);
	if (start > length)
		return (ft_strdup(""));
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	substr = ft_calloc(len + 1, sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = str[i + start];
		i++;
	}
	return (substr);
}
/*
int	main(void)
{
	const char	*s = "Hello world";
	char	*result = ft_substr(s, 6, 5);
	printf("Substring: %s", result);
	return (0);
}*/
