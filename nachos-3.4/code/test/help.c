/* help.c
 *	A simple program to output name of each members
 */

#include "syscall.h"

int main()
{
    	PrintString("==================================================\n");
	PrintString("     OS - NachOS Project     \n");
	PrintString("\n");
	PrintString("1/ Members\n");
	PrintString("	21127243 - Phung Sieu Dat	\n");
	PrintString("	21127296 - Dang Ha Huy		\n");
	PrintString("	21127300 - Nguyen Cat Huy	\n");
        PrintString("2/ Available programs\n");
	PrintString("	help: Print out this message and leave.\n");
	PrintString("	ascii: Print out the ascii table.\n");
	PrintString("	sort: The user input an array of integer\n");
	PrintString(" 	      Use bubble sort to sort the array.\n");
	PrintString("==================================================\n");
}
