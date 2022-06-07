#include <stdio.h>

void main() {
	unsigned int numero = 0x00001000;
	int numzeri;
	int numuni;

	__asm {
		MOV EAX, 32
		XOR EBX, EBX
		XOR EDX, EDX
		XOR ECX, ECX
		MOV numuni, 0
		MOV numzeri, 0

		uno :
		    	CMP EAX, 0
			JE fine
			SAR numero, 1
			DEC EAX
			JNC zeri
			JC uni

		zeri :
		    	CMP EBX, 0
			JNE nonprimo
			MOV EDX, 1
			MOV EBX, 2
			JMP uno
			nonprimo : CMP EBX, 2
			JNE nuovaseq1
			INC EDX
			JMP uno
			nuovaseq1 : CMP numzeri, EDX
			JG minore
			MOV EBX, 2
			MOV numzeri, EDX
			MOV EDX, 1
			JMP uno
			minore : MOV EDX, 1
			MOV EBX, 1
			JMP uno

		uni :
			MOV numuni, 1
		    	CMP EBX, 0
			JNE nonprimo2
			MOV ECX, 1
			MOV EBX, 1
			JMP uno
			nonprimo2 : CMP EBX, 1
			JNE nuovaseq2
			INC ECX
			JMP uno
			nuovaseq2 : CMP numuni, ECX
			JG minore2
			MOV EBX, 1
			MOV numuni, ECX
			MOV ECX, 1
			JMP uno
			minore2 : MOV ECX, 1
			MOV EBX, 1
			JMP uno

		fine :
			CMP numuni, ECX
			JG stop
			MOV numuni, ECX
			stop:CMP numzeri, EDX
			JG stop1
			MOV numzeri, EDX
			stop1:


	}
	printf("la sequenza piu lunga di bit contigui a 0 e pari a:%d\n", numzeri);
	printf("la sequenza piu lunga di bit contigui a 1 e pari a:%d\n", numuni);
}
