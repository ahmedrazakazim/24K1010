#include <stdio.h>

int main()
{
    char input[100];
    char reversed_str[100];
    int str_len = 0, i, palindrome_check = 1;

    printf("Enter a string: ");
    gets(input);

    while (input[str_len] != '\0')
    {
        str_len++;
    }

    for (i = 0; i < str_len; i++)
    {
        reversed_str[i] = input[str_len - 1 - i];
    }
    reversed_str[str_len] = '\0';

    for (i = 0; i < str_len; i++)
    {
        if (input[i] != reversed_str[i])
        {
            palindrome_check = 0;
            break;
        }
    }

    if (palindrome_check)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not palindrome.\n");
    }

    return 0;
}
