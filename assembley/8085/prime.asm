;Prime nos from an array
	jmp start
;data
array:	db 03, 24, 37, 24
stck:	ds 30
start:	LXI H, array
;50h
	LXI SP, stck
;5000H
	MOV E,M

LOOP1:	MVI A,00H
	CMP E
	JZ HALT
	JMP PRIME
;
YES:	DCR E
	JMP LOOP1
;
PRIME:	NOP

	INX H
	MOV A,M
	CPI 01H
	JC NO
	JZ NO
	XRA A
	MOV A,M
	RAR
	MOV B,A

LOOPTWO:	MOV A,B
	CPI 01H
	JZ YES
	MOV A,M

LOOP3:	SUB B
	CPI 00H
	JZ NO
	CPI 128
	JC LOOP3
	DCR B
	JMP LOOPTWO

NO:	MVI M,00
	JMP LOOP1
HALT:	HLT 
	