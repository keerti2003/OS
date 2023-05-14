[BITS 16]
[ORG 7C00h]
jmp main
main:
xor ax, ax 
mov ds, ax
cld 
mov ax, 0012h 
mode
int 10h
mov si, string
mov bl,4 
call printstr
jmp $
printstr:
mov bh,0 
print:
lodsb
cmp al, 0
je done
mov ah,0Eh 
int 10h
jmp print
done:
ret
string db "KEERTI",13,10,0
times 510 - ($-$$) db 0
dw 0AA55h
