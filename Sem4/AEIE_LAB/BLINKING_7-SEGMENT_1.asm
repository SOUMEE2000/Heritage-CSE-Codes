	ORG 2000H
L1:	LXI H, 2500H
	MOV A, M
	OUT 80H
	INX H
	MOV A, M
	OUT 81H
	INX H
	MOV A, M
	OUT 82H
	;CALL 2600H
	MVI A, 00H
	OUT 80H
	OUT 81H
	OUT 82H
	CALL 2600H
	JMP L1
	ORG 2600H
	MVI C, 20H
L2:	DCR C
	JNZ L2
	RET
	ORG 2500H
	DB 39H, 6DH, 79H

	END