#include <unistd.h>

// 1. Go through the second string
// 2. If the current str2 char is = current str1 char
    // Go to the next str1 char
// 3. If current str1 char is null char that means we return 1
// 4. If current str2 char is null char and str1 no return 0

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i = 0;
        int j = 0;

        while (argv[2][j] != '\0')
        {
            if (argv[2][j] == argv[1][i])
                i++;
            if (argv[1][i] == '\0')
                return ("1\n");
            j++;
        }
        if (argv[1][i] != '\0')
            return ("0\n");
    }
    write(1, "\n", 1);
    return (0);
}