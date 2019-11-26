#include<stdio.h>

void fetch(unsigned char *memory, int *_PC)
{
    int PC;
    printf("Fetching instructions...\n");
    for(PC = *_PC; PC < 0xFFFF; PC = PC + 2)
    {
        unsigned char Hbyte = memory[PC];
        unsigned char Lbyte = memory[PC+1];
        unsigned opcode = (Hbyte << 8) | Lbyte;
        switch(opcode)
        {
            case 0x00:
                printf("Clear screen.\n");
                break;
        }
        printf("PC: %x > 0x%.4x\n",PC, opcode);
    }
}