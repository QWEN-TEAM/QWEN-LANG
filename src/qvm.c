#include<stdio.h>
#include<stdlib.h>

unsigned char memory[0xFFFF];
char stack[0x3F];

int PC;
unsigned char R[0xF];
char RI;
char SP;

int file_size;

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
        fseek(file, 0L, SEEK_END);
        file_size = ftell(file);
        fseek(file, 0L, SEEK_SET);
        printf("File Size: %d bytes\n", file_size);
    }
}
