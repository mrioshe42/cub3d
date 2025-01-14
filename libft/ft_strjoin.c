/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:13:31 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:38:42 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	tot_len;
	char	*result;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tot_len = s1_len + s2_len + 1;
	result = malloc(sizeof(char) * tot_len);
	if (!result)
		return (NULL);
	ft_memmove(result, s1, s1_len);
	ft_memmove(result + s1_len, s2, s2_len);
	result[tot_len - 1] = '\0';
	return (result);
}
/*

int	main(void)
{
	char	*s1 = "Hello ";
	char	*s2 = "world";

	char	*result = ft_strjoin(s1, s2);
	printf("Joined string: %s", result);
	return (0);
}*/
