#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(const char *str)
{
	//Skip inital spaces and tabs
	//Check for negative sign
	//Save each number in result int, make space after one has been added

	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ' || str[i] == '	')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9'){
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int main()
{
	const char *str = "    -042   97";

	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
	return (0);
}