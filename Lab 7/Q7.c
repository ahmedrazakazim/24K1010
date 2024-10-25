
int main()
{
    char equation[50];
    printf("Enter Your Equation: ");
    scanf("%s", equation);

    int i = 0;
    int sum = 0;
    int temp = 0;
    char last_opp = '+';

    while (equation[i] != '\0')
    {
        if ((equation[i] >= '0') && (equation[i] <= '9'))
        {
            temp = (temp * 10) + (equation[i] - '0');
        }
        else if (equation[i] == '+')
        {
            if (last_opp == '+')
            {
                sum += temp;
            }
            else if (last_opp == '-')
            {
                sum -= temp;
            }
            last_opp = '+';
            temp = 0;
        }
        else if (equation[i] == '-')
        {
            if (last_opp == '+')
            {
                sum += temp;
            }
            else if (last_opp == '-')
            {
                sum -= temp;
            }
            last_opp = '-';
            temp = 0;
        }
        else
        {
            printf("Invalid operator '%c'\n", equation[i]);
            return 1;
        }

        i++;
    }

    if (last_opp == '+')
    {
        sum += temp;
    }
    else if (last_opp == '-')
    {
        sum -= temp;
    }

    printf("RESULT: %d\n", sum);
    return 0;
}
