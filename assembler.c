#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "assembler.h"

int convertMachine(Instruction input)
{
    int output = 0b00000000000000000000000000000000;

    int opCodeBin;
    int rm;
    int shamt;
    int rn;
    int rd;
    int immed;

    int opCode = input.opcode;

    if(opCode == 0)
    {
        printf("YOUR COMMAND WAS NOT RECOGNIZED!\n");
    }
    else if(opCode == 1)
    {
        opCodeBin = 0b10001011000;

        output = opCodeBin + output;
        output = output << 5;

        rm = input.Rm;

        //Add this to the output and then shift left 6
        output = output + rm;
        output = output << 6;

        //Now we need to add the shamt
        int shamt = 0b000000;
        output = output + shamt;
        output = output << 5;

        //Now we need to add the RN
        rn = input.Rn;

        output = output + rn;
        output = output << 5;

        //Adding RD
        rd = input.Rd;

        output = output + rd;

        return output;
    }
    else if(opCode == 2) //ADDI 10 I
    {
        opCodeBin = 0b1001000100;

        output = output + opCodeBin;
        output = output << 12;

        //Adding the ALU immediate into output
        immed = input.immediate;

        output = output + immed;
        output = output << 5;

        rn = input.Rn;

        output = output + rn;
        output = output << 5;

        rd = input.Rd;
        output = output + rd;

        return output;

    }
    else if(opCode == 3) //SUB
    {
        opCodeBin = 0b11001011000;

        output = opCodeBin + output;
        output = output << 5;

        rm = input.Rm;

        //Add this to the output and then shift left 6
        output = output + rm;
        output = output << 6;

        //Now we need to add the shamt
        shamt = 0b000000;
        output = output + shamt;
        output = output << 5;

        //Now we need to add the RN
        rn = input.Rn;

        output = output + rn;
        output = output << 5;

        //Adding RD
        rd = input.Rd;

        output = output + rd;

        return output;
    }
    else if(opCode == 4) //SUBI
    {
        opCodeBin = 0b1101000100;

        output = output + opCodeBin;
        output = output << 12;

        //Adding the ALU immediate into output
        immed = input.immediate;

        output = output + immed;
        output = output << 5;

        rn = input.Rn;

        output = output + rn;
        output = output << 5;

        rd = input.Rd;
        output = output + rd;

        return output;
    }
    else if(opCode == 5) //LDUR
    {
        opCodeBin = 0b11111000010;

        output = output + opCodeBin;
        output = output << 9;

        immed = input.immediate;

        output = output + immed;
        output = output << 2;

        output = output + 0b00;
        output = output << 5;

        rn = input.Rn;

        output = output + rn;
        output = output << 5;

        rd = input.Rd;

        output = output + rd;

        return output;
    }
    else if(opCode == 6) //STUR
    {
        opCodeBin = 0b11111000000;

        output = output + opCodeBin;
        output = output << 9;


        immed = input.immediate;
        //printf("RD = %s", rd);

        output = output + immed;
        output = output << 2;

        output = output + 0b00;
        output = output << 5;

        rn = input.Rn;
        //printf("RN = %s", rn);

        output = output + rn;
        output = output << 5;

        rd = input.Rd;
        //printf("immed/rt = %s", immed);

        output = output + rd;

        return output;
    }

    return 0;
}
