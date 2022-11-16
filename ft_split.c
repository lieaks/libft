/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:09:55 by dly               #+#    #+#             */
/*   Updated: 2022/11/15 20:48:47 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcount(char const *s, char c)
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

int	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_addword(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (ft_wordlen(s, c) + 1));
	if (!word)
	{
		ft_putstr_fd("ERROR MALLOC WORD", 2);
		return (NULL);
	}
	while (i < ft_wordlen(s, c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
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
	{
		write(2, "Error malloc str", 16);
		return (0);
	}
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j])
			final[i++] = ft_addword(s, c);
		while (s[j] && s[j] != c)
			j++;
	}
	final[i] = 0;
	return (final);
}
