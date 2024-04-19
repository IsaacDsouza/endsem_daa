#include <stdio.h>
#include <string.h>
#define MAX 500

int table[MAX];

void shifttable(char pattern[])
{
    int m = strlen(pattern);
    for (int i = 0; i < MAX; i++)
    {
        table[i] = m;
    }
    for (int i = 0; i < m - 1; i++)
    {
        table[pattern[i]] = m - 1 - i;
    }
}

int horsepool(char text[], char pattern[])
{

    int m = strlen(pattern);
    int n = strlen(text);
    int i = m - 1;
    while (i < n)
    {
        int k = 0;
        while ((k < m) && (pattern[m - 1 - k] == text[i - k]))
        {
            k++;
        }
        if (k == m)
            return (i - m + 1);
        else
            i += table[text[i]];
    }
}

int main()
{
    char text[100], pattern[100];
    printf("Enter the text:\n");
    gets(text);
    printf("Enter the substring:\n");
    gets(pattern);
    shifttable(pattern);
    int pos = horsepool(text, pattern);
    if (pos >= 0)
        printf("The desired pattern was found starting from position %d \n", pos + 1);

    else
        printf("The pattern was not found in the given text \n");
    return 0;
}
