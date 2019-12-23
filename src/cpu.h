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
            case 0x0000:
                printf("0x0000: Clear screen.\n");
                break;
            case 0x0001:
                printf("0x0001: Returns from a subroutine.\n");
                break;
            case 0x0002:
                printf("0x0002: goto NNNN;.\n");
                break;
            case 0x0003:
                printf("0x0003: *(0xNNNN)();.\n");
                break;
            case 0x1XNN:
                printf("0x1XNN: RX = NN;.\n"):
                break;
             
                       
        }
        printf("PC: %x > 0x%.4x\n",PC, opcode);
    }
}
