/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:30:37 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/28 18:25:36 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ------------------------------- ft_strlen ------------------------------- */
int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* ------------------------------- ft_strdup ------------------------------- */
char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/* ------------------------------- ft_strchr ------------------------------- */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/* ------------------------------- ft_strjoin ------------------------------- */
/* Special version for get_next_line: handles NULL s1 or s2 safely */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[i - ft_strlen(s1)])
	{
		result[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* ------------------------------- ft_substr ------------------------------- */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
