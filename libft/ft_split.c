/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:57:30 by mg                #+#    #+#             */
/*   Updated: 2024/08/18 14:47:06 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	compteur(const char *str, char sep)
{
	int	i;
	int	nb_mots;
	int	flag;

	i = 0;
	nb_mots = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] != sep && flag == 0)
		{
			flag = 1;
			nb_mots++;
		}
		else if (str[i] == sep)
			flag = 0;
		i++;
	}
	return (nb_mots);
}

static char	*separate(const char *str, int start, int end)
{
	char	*word;
	int		i;
	int		count_start;

	word = malloc((start - end + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	count_start = start;
	while (count_start < end)
	{
		word[i] = str[count_start];
		i++;
		count_start++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	int			debut;
	char		**split;

	if (!s || !(split = malloc((compteur(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (i <= ft_strlen(s));
	{
		if (s[i] != c && debut < 0)
			debut = i;
		else if ((s[i] == c || i == ft_strlen(s)) && debut >= 0)
		{
			split[j++] = separate(s, debut, i);
			debut = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
