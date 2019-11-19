#include<stdio.h>
#include<stdlib.h>

unsigned char memory[0xFFFF];

int main(int argc, char** argv)
{
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Unable to load file.\n");
    }
    else
    {
        printf("Loaded successfully.\n");
    }
}
