/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivar <ivar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:44:57 by ivar              #+#    #+#             */
/*   Updated: 2024/11/11 19:47:15 by ivar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (s && *s)
		if (*(s++) == (char)c)
			return ((char *)(--s));
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dst;

	if (!s)
		return (NULL);
	dst = (char *)malloc(ft_strlen(s) + 1);
	if (dst == NULL)
		return (NULL);
	while (*s)
		*(dst++) = *(s++);
	*dst = '\0';
	return (dst - ft_strlen(s));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (s1)
		while (*s1)
			*(str++) = *(s1++);
	if (s2)
		while (*s2)
			*(str++) = *(s2++);
	*str = '\0';
	return (str - len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	i = 0;
	while (i < len && s[i + start] != '\0')
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i--)
		str[i] = s[start + i];
	return (str);
}
