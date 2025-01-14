/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:48:41 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:27:02 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*

int	main(void)
{
	const	char	*s = "Hello wolrd";
	void	*result = ft_memchr(s, 'o', sizeof(s));

	if (result != NULL)
		printf("Found at position: %ld\n", (char *)result - s);
	else
		printf("Not found");
	return (0);
}*/
