#include<stdio.h>

void fetch(unsigned char *memory, int *_PC)
{
    int PC;
    printf("Fetching instructions...\n");
    for(PC = *_PC; PC < 0xFFFF; PC = PC + 1)
    {
        unsigned char byte = memory[PC];
        printf("PC: %x > %.2x\n",PC, byte);
    }
}