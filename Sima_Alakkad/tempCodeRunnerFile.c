#include <stdio.h>
#include <stdlib.h>

// NULL is a pointer nothing (address 0)

// WRITE A FILE

int main()
{
    FILE *pFile = fopen("C:\\Users\\Sima\\Desktop\\output.txt", "w");

    char text[] = "THIS IS FOR TESTING\nWRITE A FILE!";

    if(pFile == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(pFile, "%s", text);

    printf("File was written successfully!\n");

    fclose(pFile);

    return 0;
}