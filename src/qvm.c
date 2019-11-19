#include<stdio.h>
#include<stdlib.h>

unsigned char memory[0xFFFF];
char stack[64];

int PC;
unsigned char R[F];
char RI;
char SP;


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
