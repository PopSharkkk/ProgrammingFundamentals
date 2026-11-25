#include <stdio.h>

int main()
{
    char a, op, b;
    scanf("%c %c %c", &a, &op, &b);
    int valueA, valueB, valueres;

    if (a >= 'a' && a <= 'z')
    {
        valueA = a - 'a' + 1;
    }
    else if (a >= 'A' && a <= 'Z')
    {
        valueA = a - 'A' + 27;
    }

    if (b >= 'a' && b <= 'z')
    {
        valueB = b - 'a' + 1;
    }
    else if (b >= 'A' && b <= 'Z')
    {
        valueB = b - 'A' + 27;
    }

    if (op == '+')
    {
        valueres = valueA + valueB;
    }
    else if (op == '-')
    {
        valueres = valueA - valueB;
    }
    else if (op == '*')
    {
        valueres = valueA * valueB;
    }
    else if (op == '/')
    {
        valueres = valueA / valueB;
    }
    else if (op == '%')
    {
        valueres = valueA % valueB;
    }

    valueres = valueres - 1;
    valueres = valueres % 52;
    if (valueres < 0)
    {
        valueres += 52;
    }

    char output;
    if (valueres >= 0 && valueres <= 25)
    {
        output = 'a' + valueres;
    }
    else if (valueres >= 26 && valueres <= 51)
    {
        output = 'A' + (valueres - 26);
    }

    printf("%c\n", output);

    return 0;
}