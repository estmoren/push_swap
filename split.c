#include "push_swap.h"

static int	ft_count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_word_dup(char *str, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char *str, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split = malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	if (split == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			split[j] = ft_word_dup(&str[i], c);
			j++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	split[j] = NULL;
	return (split);
}
