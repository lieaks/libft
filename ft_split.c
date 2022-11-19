/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:09:55 by dly               #+#    #+#             */
/*   Updated: 2022/11/19 14:16:15 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcount(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_addword(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (ft_wordlen(s, c) + 1));
	if (!word)
		return (NULL);
	while (i < ft_wordlen(s, c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static char	**ft_free_malloc(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**final;

	i = 0;
	j = 0;
	final = (char **)malloc(sizeof(char *) * (ft_strcount(s, c) + 1));
	if (!final)
		return (0);
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j])
		{	
			final[i] = ft_addword(s + j, c);
			if (!final[i])
				return (ft_free_malloc(final));
			i++;
		}
		while (s[j] && s[j] != c)
			j++;
	}
	final[i] = 0;
	return (final);
}
