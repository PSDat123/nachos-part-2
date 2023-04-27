/* sort.c 
 *  Sort user-input array with bubble sort algorithm
 */

#include "syscall.h"

int main() {
	int N, i, j, tmp;
	int a[100];
	PrintString("=====SORTING=====\n");
	PrintString("Input N (<100) = ");
	N = ReadInt();
	if (N < 1 || N > 100) {
		PrintString("Invalid Input\n");
		Halt();
	}
	for (i = 0; i < N; ++i) {
        	PrintString("a[");
        	PrintInt(i);
        	PrintString("] = ");
       		a[i] = 0;
        	a[i] = ReadInt();
	}
    	for (i = 0; i < N - 1; ++i) {
        	for (j = 0; j < (N - 1 - i); ++j) {
			if (a[j] > a[j + 1]) {
	      			tmp = a[j];
	     			a[j] = a[j + 1];
     			 	a[j + 1] = tmp;
    	   		}
		}
	}
	
	PrintString("Array after sorting: ");
	PrintChar('[');
	PrintChar(' ');
	for (i = 0; i < N; ++i) {
        	PrintInt(a[i]);
		PrintChar(' ');
	}
	PrintChar(']');
}
