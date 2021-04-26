#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "assembler.h"

int main()
{

    //Get Instruction from the user (using standard input)
    printf("Enter an ARM instruction:\n");
    char str[MAX_LIMIT];

    while(fgets(str, MAX_LIMIT, stdin))
    {
    // Create an instruction structure from instruction string
    Instruction instruction = parseInstructionString(str);

    //Print the contents of the instruction
    //printInstruction(instruction);

    int machineLang = convertMachine(instruction);

    printf("Machine Code for %s: %x\n", str, machineLang);
  }

    return (EXIT_SUCCESS);
}
