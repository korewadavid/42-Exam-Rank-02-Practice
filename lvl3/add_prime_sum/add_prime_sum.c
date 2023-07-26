#include <unistd.h>

void ft_put_nbr (int nbr)
{
	if (nbr > 9)
		ft_put_nbr(nbr/10);
	char *str = "0123456789";
	write(1, &str[nbr%10], 1);
}

int ft_atoi(char *str)
{
	int result = 0;
	//int sign = 1;
	int i = 0;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	//if (str[i] == '-')
	//	sign = -1;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		result %= 10;
		i++;
	}
	return (result);
}

int main (int argc, char **argv)
{
	if (argc != 2 || ft_atoi(argv[1]) < 0)
	{
		int num = ft_atoi(argv[1]);
		int i = 0;
		int result = 0;
		while (i < num)
		{
			if (i % i == 0 && i % 1 == 0)
				result += i;
			i++;
		}
		result += num;
		ft_put_nbr(result);
	}
	write(1 , "\n", 1);
	return (0);
}
