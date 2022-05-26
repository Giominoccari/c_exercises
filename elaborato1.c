#include <stdio.h>

void main() {

#define MAX_LEN 100

	char s1[] = "";
	unsigned int luns1 = sizeof(s1) - 1;
	char s2[] = "";
	unsigned int luns2 = sizeof(s2) - 1;
	unsigned int posizioni[MAX_LEN];
	unsigned int posizionilen;

	__asm {
		MOV ECX, 0
		MOV EAX, 0
		DEC luns1
		DEC luns2
		MOV EBX, luns1
		CMP EBX, 0
		JZ fine
		MOV posizionilen, 0
		XOR EBX, EBX
		XOR EDX, EDX


		uno : CMP ECX, luns1
		JG fine
		CMP EAX, luns2
		JNG restart
		XOR EAX, EAX

		restart : MOV BH, s1[ECX]
		CMP BH, s2[EAX]
		JE due
		JNE tre

		due : XOR EBX, EBX
		CMP EAX, 0
		JNE duedue
		MOV posizioni[EDX*4], ECX
		INC ECX
		INC EAX
		JMP uno

		duedue : CMP EAX, luns2
		JNE duetre
		INC ECX
		INC EDX
		INC posizionilen
		XOR EAX, EAX
		JMP uno

		duetre : INC EAX
		INC ECX
		JMP uno

		tre : XOR EBX, EBX
		XOR EAX, EAX
		INC ECX
		JMP uno


		fine :
	}
	printf("posizionilen=%d", posizionilen);
	printf("{");
	for (unsigned int i = 0; i < posizionilen; i++) {
		printf("%d, ", posizioni[i]);
	}
	printf("}");
}
