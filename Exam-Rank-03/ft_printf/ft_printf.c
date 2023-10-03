#include <stdio.h>
#include <stdarg.h>

void    put_str(char *str, int *length)
{
    // PROTECT !
    if (!str)
        str = "(null)";
    while (*str)
        *length += write(1, str, 1);
}

void    put_digit(long long int num, int base, int *length)
{
    char *hexa = "0123456789abcdef";

    if (num < 0)
    {
        num *= -1;
        *length += write(1, "-", 1);
    }
    if (num >= base)
        put_digit((num / base), base, length);
    *length += write(1, &hexa[num % base], 1);
}

int ft_printf(const char *format, ...)
{
    // 1. initalize len to return, va_list
    // 2. iterate through format
    // 3. if current char is % and valid format char following it...
    // 4. go to next char and depending on the value put_string or put_digit
    // 5 . ... else

    int length = 0;

    va_list pointer;
    va_start(pointer, format);

    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 's' || *(format + 1) == 'd' || *(format + 1) == 'x'))
        {
            format++;
            if (*format == 's')
                put_str(va_arg(pointer, char*), &length);
            if (*format == 'd')
                put_digit((long long int)va_arg(pointer, int), &length);
            if (*format == 'x')
                put_digit((long long int)va_arg(pointer, unsigned int), &length);
        }
        else
            length += write(1, format, 1);
        format++;
    }
    va_end(pointer);
    return (length);
}