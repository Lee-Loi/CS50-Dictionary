#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE* fp = fopen("dictionaries/small", "r");
    if (fp == NULL) {printf("ouch!\n");return 1;}
    char buffer[50];
    while (fgets(buffer, 50, fp))
    {
        buffer[strlen(buffer)-1] = 0;
        printf("buffer: %s\n", buffer);
    }
}