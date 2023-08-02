#include <stdio.h>
#include <stdlib.h>

// 1. special case int (-2147483648)
// 2. if number is negative or zero add len
// 3. get length of num
// 4. reserve space for string, fill last space with '\0'
// 5. if num is zero case
// 6. if num is negative case
// 7. fill string
// 8. return string

char	*ft_itoa(int nbr)
{
    int num = nbr;
    int len = 0;

    if (nbr = -2147483648)
        return ("-2147483648");
    if (nbr <= 0)
        len++;
    while (num)
    {
        num /= 10;
        len++;
    }
    char *str = (char *)malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    str[len] = '\0';
    if (nbr == 0)
    {
        str[0] = '0';
        return (str);
    }
    if (nbr < 0)
    {
        str[0] = '-';
        nbr = -nbr;
    }
    while (nbr)
    {
        str[--len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (str);
}