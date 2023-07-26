#include <unistd.h>
#include <stdio.h>

char	*ft_strrev(char *str)
{
	int i = 0;
	int len = 0;
	char temp;

	while (str[len] != '\0')
		len++;
	while (i <= len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = len;
		i++;
		len--;
	}
	return (str);
}

int main()
{
	printf("%s\n", ft_strrev("abc"));
	return(0);
}
