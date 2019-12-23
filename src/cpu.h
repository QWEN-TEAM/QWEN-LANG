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
                printf("Clears the display.");
                break;
            case 0x0001:
                printf("Returns from a subroutine. Sets the PC to address at the top of the stack, then subtracts 1 from the stack pointer (SP).\n");
                break;
            case 0x0002:
                printf("Jumps to address NNNN(High byte from R0 register and low byte from R1 register). Sets the PC to NNNN.\n");
                break;
            case 0x0003:
                printf("Calls subroutine at NNNN(High byte from R0 register and low byte from R1 register). Increments the stack pointer, then puts 
the current PC on the top of the stack. The PC is then set to NNNN.\n");
                break;
            case 0x1XNN:
                printf("Sets RX to NN.\n");
                break;
            case 0x2XY0:
                printf("Sets RX to the value of RY.\n");
                break;
            case 0x2NN1:
                printf("Set (R0<<8) | R1 memory location to NN.\n");
                break;
            case 0x31XY:
                printf("Sets RX to RX or RY (Bitwise OR Operation).\n");
                break;
            case 0x32XY:
                printf("Sets RX to RX and RY (Bitwise AND Operation)\n").
                       
        }
        printf("PC: %x > 0x%.4x\n",PC, opcode);
    }
}
