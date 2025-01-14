/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:05:58 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 12:05:33 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*result;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
char	to_uppercase(unsigned int index, char c)
{
	unsigned int	i;

	i = index;
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	i++;
	return (c);
}

int	main(void)
{
	const char *str = "hello world";
	printf("Original string: %s\n", str);
	char* result = ft_strmapi(str, to_uppercase);
	printf("Transformed string: %s\n", result);
	free(result);
	return (0);
}*/
