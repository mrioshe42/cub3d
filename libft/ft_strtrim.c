/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:27:26 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:52:55 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (is_in_set(s1[start], set) == 1)
		start++;
	if (start == ft_strlen(s1))
	{
		result = ft_strdup("");
		if (!result)
			return (NULL);
		else
			return (result);
	}
	while (is_in_set(s1[end - 1], set) == 1)
		end--;
	result = ft_substr(s1, start, end - start);
	return (result);
}
/*
int	main(void)
{
	char	*s = "  Hello,  world  !";
	char	*result = ft_strtrim(s, " ,");
	printf("String trimmed: %s", result);
	free(result);
	return(0);
}*/
