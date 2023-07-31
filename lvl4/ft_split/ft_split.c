#include <stdlib.h>
 
// 1. Count the number of substrings/words
// 2. Alocate memory for the array of substrings
// 3. Split the string into substrings based on the delimiter
// 4. Copy each substring into the allocated memory
// 5. Return the array of substrings

char *ft_strncpy(char *s1, char *s2, int size);

int		word_counter(char *str)
{
	int wc = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '	' || str[i] == '\n'))
			i++;
		if (str[i] != '\0')
			wc++;
		while (str[i] != '\0' && (str[i] != ' ' && str[i] != '	' && str[i] != '\n'))
			i++;
	}
	return (wc);
}

char    **ft_split(char *str)
{
	int wc = word_counter(str);

	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
}
