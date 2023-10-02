#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strrev(char *str)
{
	int i = 0;
	int len = 0;
	char temp;

	while (str[len] != '\0')
		len++;
	while (i < --len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
	}
	return (str);
}

int main()
{
	char *str = "abc";
	char cpydStr[3];
	strcpy(cpydStr, str);
	printf("%s\n", ft_strrev(cpydStr));
	return(0);
}
