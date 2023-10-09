#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void    put_str(char *str, int *length)
{
    if (!str)
        str = "(null)";
    while (*str)
        *length += write(1, str, 1);
}

void    put_num(long long int num, int base, int *length)
{
    char *hexa = "0123456789abcdef";

    if (num < 0)
    {
        num *= -1;
        *length += write(1, "-", 1);
    }
    if (num > base)
        put_num((num / base), base, length);
    *length += write(1, &hexa[num % base], 1);
}

int ft_printf(const char *format, ...)
{
    int length = 0;

    va_list(pointer);
    va_start(pointer, format);

    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 's' || *(format + 1) == 'd' || *(format + 1) == 'x'))
        {
            format++;
            if (*format == 's')
                put_str(va_arg(pointer, char*), &length);
            if (*format == 'd')
                put_num((long long int)va_arg(pointer, int), 10, &length);
            if (*format == 'x')
                put_num((long long int)va_arg(pointer, int), 16, &length);
        }
        else
            length += write(1, format, 1);
        format++;
    }
    va_end(pointer);
    return (length);
}

int main ()
{
    ft_printf("%d is the magic &s", 42, "number!");
    return (0);
}