#include <stdio.h>

void main() {
	unsigned int numero = 0x00300001 ;
	int numzeri;
	int numuni;

	__asm {
		XOR EAX, EAX
		XOR ECX, ECX
		XOR EDX, EDX
		XOR EBX, EBX
		XOR ECX, ECX

		CMP numero[ECX], 0
		JE start1
		JNE start0

		start1:MOV EBX, 1
		MOV EDX, 1
		XCHG EDX, numuni
	

		start0: MOV EBX, 0
		MOV EDX, 1
		XCHG EDX, numzeri
		

		XOR EDX, EDX

		uno:CMP EDX, 31
		JE fine
		INC EDX
		CMP numero[ECX], 0
		JE zeri
		JNE uni

		zeri:CMP EBX, 0
		JNE change1
		INC ECX
		INC numzeri
		JMP uno
		change1: MOV numzeri, 1
		XOR EBX, EBX
		INC ECX
		JMP uno

		uni:CMP EBX, 1
		JNE change2
		INC ECX
		INC numuni
		JMP uno
		change2: MOV numuni, 1
		MOV EBX, 1
		INC ECX
		JMP uno

		fine:


	}
	printf("la sequenza più lunga di bit contigui a 1 è pari a:%d\n", numuni);
	printf("la sequenza più lunga di bit contigui a 0 è pari a:%d\n", numzeri);
}
