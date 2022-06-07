#include <stdio.h>

void main() {

	unsigned int numero = 1261260;
	unsigned int divisori[100];
	int numdiv;

	__asm {
		MOV EAX, numero
		MOV numero, 0
		MOV ECX, 2
		MOV numdiv, 0
		MOV EDX, 0
		XOR EBX, EBX

		uno : CMP EAX, ECX
		JNGE fine
		CMP EAX, ECX
		JE last
		DIV ECX
		CMP EDX, 0
		JE primo
		IMUL EAX, ECX
		ADD EAX, EDX
		INC ECX
		XOR EDX, EDX
		JMP uno

		primo:MOV divisori[EBX*4], ECX
		INC numdiv
		INC EBX
		JMP uno

		last:MOV divisori[EBX*4], ECX

		fine:
	}
	printf("numero di divisori=%d\n", numdiv+1);
	for (int i = 0; i <= numdiv; i++) {
		printf("%d\n", divisori[i]);
	}
}
