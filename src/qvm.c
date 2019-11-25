#include<stdio.h>
#include<stdlib.h>
#include"cpu.h"

unsigned char memory[0xFFFF];
char stack[0x3F];

int PC = 0x8800;
unsigned char R[0xF];
char RI;
char SP;

int file_size;

int main(int argc, char** argv)
{
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Unable to load file. Please try again.\n");
    }
    else
    {
        printf("Loaded successfully.\n");
        fseek(file, 0L, SEEK_END);
        file_size = ftell(file);
        fseek(file, 0L, SEEK_SET);
        printf("File Size: %d bytes\n", file_size);
        for(int i=0; i<file_size; i++)
        {
            memory[0x8800+i] = fgetc(file);
        }
        for(int i=0; i<0xFFFF; i++)
        {
            printf("location 0x%04x: 0x%04x\n", i, memory[i]);
        }
        fetch();
        printf("Terminated.\n");
    }
}
