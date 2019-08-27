#include "shell.h"
/**
 * printf_int - prints integer
 * @args: argument to print
 * Return: number of characters printed
 */
char *_itoa(int n)
{
        int num, last = n % 10, digit, exp = 1;
        int  i = 1, l = 0;
        char *buffer = NULL;

        n = n / 10;
        num = n;
        buffer = _calloc(12, sizeof(int));
        if (num > 0)
        {
                while (num / 10 != 0)
                {
                        exp = exp * 10;
                        num = num / 10;
                }
                num = n;
                while (exp > 0)
                {
                        digit = num / exp;
                        buffer[l] = (digit + '0');
                        l++;
                        num = num - (digit * exp);
                        exp = exp / 10;
                        i++;
                }
        }
        buffer[l] = (last + '0');
        l++;
        buffer[l] = '\0';

        return (buffer);
}
