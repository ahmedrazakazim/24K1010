#include <stdio.h>

int main()
{
    char input[100];
    char reversed_str[100];
    int str_len = 0, index, palindrome_check = 1;

    printf("Enter a string: ");
    gets(input);

    while (input[str_len] != '\0')
    {
        str_len++;
    }

    for (index = 0; index < str_len; index++)
    {
        reversed_str[index] = input[str_len - 1 - index];
    }
    reversed_str[str_len] = '\0';

    for (index = 0; index < str_len; index++)
    {
        if (input[index] != reversed_str[index])
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
