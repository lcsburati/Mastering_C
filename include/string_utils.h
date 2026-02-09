#include <stdio.h>
#include <stdlib.h>

const int distance = 'a' - 'A'; 
int my_strlen(const char *str)
{
    int lenght = 0;

    while (*str)
    {
        lenght++;
        str++;
    }
    return lenght;
}

char *my_tolower(const char *str)
{
    int lenght = my_strlen(str);
    char *result = malloc(sizeof(char) * (lenght + 1));
    if (result == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    char *current = result;


    while (*str)
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *current = *str + distance;
            str++;
            current++;
        } 
        else
        {
            *current = *str;
            str++;
            current++;
        }
    }
    *current = '\0';
    return result;
}

char *my_toupper(const char *str)
{
    int lenght = my_strlen(str);
    char *result = malloc(sizeof(char) * (lenght + 1));
    if (result == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    char *current = result;

    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *current = *str - distance;
            str++;
            current++;
        }
        else
        {
            *current = *str;
            str++;
            current++;
        }
    }
    *current = '\0';
    return result;
}

int my_strcmp(const char *str1, const char *str2)
{

    int str1_length = my_strlen(str1);
    int str2_length = my_strlen(str2);

    if (str1_length > str2_length)
    {
        while (*str1)
        {
            if (*str1 != *str2)
            {
                return 1;
            }
            str1++; str2++;
        }
    }
    else
    {
        while (*str2)
        {
            if (*str2 != *str1)
            {
                return -1;
            }
            str1++; str2++;
        }
    }
    
    return 0;


}

double my_strcmp_percent(const char *str1, const char *str2)
{
    double percentage = 0;
    int str1_length = my_strlen(str1);
    int str2_length = my_strlen(str2);

    if (str1_length >= str2_length)
    {
        while (*str2)
        {
            percentage += ((((*str1 + *str2) / *str1) - 1) * 100.0) / str1_length;
            str2++;
            str1++;
        }

        return percentage;
    }
    else if (str1_length < str2_length)
    {
        while (*str1)
        {
            percentage += ((((*str1 + *str2) / *str1) - 1) * 100.0) / str2_length;
            str2++;
            str1++;
        }

        return percentage;
    }
    return 1.0;


}