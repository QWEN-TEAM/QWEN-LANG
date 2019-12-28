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
                printf("Sets RX to RX and RY (Bitwise AND Operation)\n");
                break;
            case 0x33XY:
                printf("Sets RX to RX xor RY (Bitwise XOR Operation).\n");
                break;
            case 0x34X1:
                printf("Stores the least significant bit of RX in RF and then shifts RX to the right by 1.\n");
                break;
            case 0x34X2:
                printf("Stores the most significant bit of RX in RY and then shifts RX to the left by 1.\n");
                break;
            case 0x4XNN:
                printf("Adds NN to RX (Carry flag is not changed).\n");
                break;
            case 0x51XY:
                printf("Adds RY to RX. RF is set to 1 when there's carry, and to 0 when there isn't.\n");
                break;
            case 0x52XY:
                printf("RY is subtracted from RX. RF is set to 0 when there's a borrow, and 1 when there isn't.\n");
                break;
            case 0x6XNN:
                printf("Skip the next instruction if RX equals NN.\n");
                break;
            case 0x7XNN:
                printf("Skip the next instruction if RX doesn't equal NN.\n");
                break;
            case 0x8XY0:
                printf("Skip the next instruction if RX qeuals RY.\n");
                break;
            case 0x9X01:
                printf("Skip the next instruction if the key stored in RX is pressed .\n");
                break;
            case 0xA000:
                printf("Adds NNNN(High byte from R0 register and low byte from R1 register) to RI.\n");
                break;
            case 0xBX00:
                printf("Sets RI to the location of the sprite for the character code in RX. Characters A-Z (Non-case-sensitive), 0-9, +, -, *, /.\n");
                break;
            case 0xC00X:
                printf("Sets RX to a random number(0-255).\n");
                break;
            case 0xDXY0:
                printf("Draw a sprite at coordinate(RX, RY) that has a 8x8 pixels. Each row of 8 pixels is read as 4-bit-coded starting from
memory location RI.\n");
                break;
            case 0xEX00:
                printf("A key press is awaited, and then stored in RX.\n");
                break;
            case 0xFNN0:
                printf("Delay NN milliseconds.\n");
                break;
            case 0xF0N1:
                printf("Play sound N(see sound chart) for 0.5 milliseconds.\n");
                break;
        }
        printf("PC: %x > 0x%.4x\n",PC, opcode);
    }
}
