/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:23:51 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:28:29 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	leng;
	char	*hay;

	i = 0;
	hay = (char *)haystack;
	leng = ft_strlen(needle);
	if (leng == 0 || haystack == needle)
		return (hay);
	while (hay[i] != '\0' && i < len)
	{
		c = 0;
		while (hay[i + c] != '\0' && needle[c] != '\0'
			&& hay[i + c] == needle[c] && i + c < len)
			c++;
		if (c == leng)
			return (hay + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*s1 = "Hello world!";
	const char	*s2 = "world";

	char	*result = ft_strnstr(s1, s2, 13);
	if (result != NULL)
		printf("Substring '%s' found at: %ld", s2, result -s1);
	else
		printf("Substring not found");
	return (0);
}*/
