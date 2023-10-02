#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//Prime factors: Numbers that only factor is 1 and itself

// Get positive int from user = num
// In the case that num = 1 we can print 1
// While the number is at least equal or greater then the first prime factor (if not it wont have any prime factors)
	// If pFactor is a prime factor of num,
		// Print the current prime factor
		// Equal num to the number that we are now searching for its prime factor
		// If num is equal or greater than the first prime factor write '*' (on the last prime factor num will equal 1 because num = fPrime)
		// Subtract fPrime by 1
	// If not, increment fPrime by 1 (this works for using the same prime factor in the if statment, and for going to the next possible prime factor)

void	fprime(int num)
{
	if (num == 1)
		printf("1");
	else
	{
		int pFactor = 2;
		while (num >= 2)
		{
			if (num % pFactor == 0)
			{
				printf("%d", pFactor);
				num /= pFactor;
				if (num >= 2)
					printf("*");
				pFactor--;
			}
			pFactor++;
		}
	}
}

int		main (int argc, char **argv)
{
	if (argc == 2)
	{
		fprime(atoi(argv[1]));
	}
	printf("\n");
	return (0);
}
