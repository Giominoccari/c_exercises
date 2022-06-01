#include <stdio.h>

void main() {
	unsigned int numero = ;
	int numzeri;
	int numuni;

	__asm {
		MOV EAX, numero
		XOR EBX, EBX
		XOR EDX, EDX
		XOR ECX, ECX


		uno:
		CMP EAX, 32
		JE fine
		SAR numero, 1
		JNC zeri
		JC uni

		zeri: 
		CMP EBX, 0
		JNE nonprimo
		MOV EDX, 1
		MOV EBX, 2
		nonprimo: CMP EBX, 1
		JNE nuovaseq1
		INC EDX
		JMP uno
		nuovaseq1: CMP numuni, EDX
		JG minore
		MOV numzeri, EDX
		minore:MOV EDX, 1
		JMP uno

		uni:
		CMP EBX, 0
		JNE nonprimo
		MOV ECX, 1
		MOV EBX, 2
		nonprimo: CMP EBX,2
		JNE nuovaseq2
		INC ECX
		JMP uno
		nuovaseq2: CMP numzeri, ECX
		JG minore2
		MOV numzeri, ECX
		minore2: MOV ECX, 1
		JMP uno

		fine:

	}
	printf("la sequenza piu lunga di bit contigui a 0 e pari a:%d\n", numzeri);
	printf("la sequenza piu lunga di bit contigui a 1 e pari a:%d\n", numuni);
}
