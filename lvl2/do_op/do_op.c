#include "do_op.h"

//Check number of arguments
    //Negative numbers, in input or output, will have one and only one leading '-'
//Change numbers to ints
//Apply opperation to numbers depending on operator
    // + - * / %

int ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * sign);
}

int do_op(int firstNum, int secNum, char *op)
{
    if (op == "+")
        return (firstNum + secNum);
    else if (op == "-")
        return (firstNum - secNum);
    else if (op == "*")
        return (firstNum * secNum);
    else if (op == "/")
        return (firstNum / secNum);
    else if (op == "%")
        return (firstNum % secNum);

}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        int firstNum = ft_atoi(argv[1]);
        int secNum = ft_atoi(argv[3]);

        printf("%d", do_op(firstNum, secNum, argv[2]));
    }
    write(1, "\n", 1);
    return (0);
}
