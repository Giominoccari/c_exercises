#include <stdio.h>

void main() {

	#define MAX_LEN 100

	char s1[] = "ciao ciao ciak";
	unsigned int luns1 = sizeof(s1) - 1;
	char s2[] = "ciao";
	unsigned int luns2 = sizeof(s2) - 1;

	unsigned int posizioni[MAX_LEN];
	unsigned int posizionilen;

	__asm {
		XOR ECX, ECX
		XOR EAX, EAX
		MOV EBX, luns1
		CMP EBX, 0
		JZ fine
		MOV posizionilen, 0
		XOR EBX, EBX
		XOR EDX, EDX
uno:    CMP ECX, luns1
		JG fine
		CMP EAX, luns2
		JNG restart
		XOR EAX, EAX
restart:MOV BH, s1[ECX]
		CMP BH, s2[EAX]
		XOR EBX, EBX
		JE due
		JNE tre
due:    CMP EAX, 0
		JNE duedue
		MOV posizioni[EDX], ECX
        INC ECX
		INC EAX
		JMP uno
duedue:	CMP EAX, luns2
		JNE duetre
		INC ECX
		INC EAX
		JMP uno
duetre: XOR EAX, EAX
		INC ECX
		INC EDX
		INC posizionilen
		JMP uno
tre:    XOR EAX, EAX
		INC ECX
        JMP uno
fine:   MOV posizionilen, EBX
	}
	printf("{");
	for (unsigned int i = 0; i < posizionilen; i++) {
		printf("%d, ", posizioni[i]);
	}
	printf("}");
}
