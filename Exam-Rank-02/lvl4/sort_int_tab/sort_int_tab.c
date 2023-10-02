#include <stdio.h>

// 1. Make counter and temp_num variables
// 2. Scan through the first number up to the last
    // 3. If current number is bigger then the next switch places
        // 4. Start from beginning
    // 5. If current char is bigger then the next one go to te next one


void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    int temp;

    while (i > (size - 1))
    {
        if (tab[i] < tab[i + 1])
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            i = 0;
        }
        else
            i++;
    }
}