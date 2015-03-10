#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{

    char word[20];
    scanf("%c", word);
    int result = 0;
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        result = result + word[i];
    }
    int y = result % 100;
    printf("%d", y);
}
