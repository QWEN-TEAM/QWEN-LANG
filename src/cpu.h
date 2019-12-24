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
            case 0x0002:
                printf("0x0002: Jumps to address NNNN(High byte from R0 register and low byte from R1 register). Sets the PC to NNNN.\n");
                break;
            case 0x0003:
                printf("0x0003: Calls subroutine at NNNN(High byte from R0 register and low byte from R1 register). Increments the stack pointer, then puts 
the current PC on the top of the stack. The PC is then set to NNNN.\n");
                break;
            case 0x1XNN:
                printf("0x1XNN: Sets RX to NN.\n");
                break;
            case 0x2XY0:
                printf("0x2XY0: Sets RX to the value of RY.\n");
                break;
            case 0x2NN1:
                printf("0x2NN1: Set (R0<<8) | R1 memory location to NN.\n");
                break;
            case 0x31XY:
                printf("0x31XY: Sets RX to RX or RY (Bitwise OR Operation).\n");
                break;
            case 0x32XY:
                printf("0x32XY: Sets RX to RX and RY (Bitwise AND Operation)\n");
                break;
            case 0x33XY:
                printf("0x33Y: Sets RX to RX xor RY (Bitwise XOR Operation). \n");
            case 0x34X1:
                printf("0x34X1: Stores the least significant bit of RX in RF and then shifts RX to the right by 1. \n");
            case():
                printf()
            case():
                printf()
            case():
                printf()
        }
        printf("PC: %x > 0x%.4x\n",PC, opcode);
    }
}
