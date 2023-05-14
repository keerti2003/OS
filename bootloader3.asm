[BITS 16]
[ORG 0x7C00]
MOV SI,string
CALL printstring
JMP $

printcharacter:
MOV AH, 0x0E
MOV BH, 0x00
MOV BL, 0x04
INT 0x10
RET 

printstring:
nextcharacter:
MOV AL,[SI]
INC SI
OR AL,AL
JZ exitfn
CALL printcharacter
JMP nextcharacter
exitfn:
RET

string db 'ABCD' 
TIMES 510-($-$$) db 0
dw 0xAA55
