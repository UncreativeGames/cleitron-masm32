INCLUDE ../Irvine32.inc
INCLUDE ../Macros.inc
INCLUDE ./Player.inc
;INCLUDE ./Menu.inc

.data
	pos_x_2 byte 24
	pos_y_2 byte 12
	back DWORD 0
	fore byte 0
.code

main PROC 
	call Crlf
LookForKey:
	mov eax,1 ; Sleep to allow OS to slice
	call Delay
	INVOKE Player_1
	jmp change
	jmp LookForKey

change:
	mov  eax,back
	inc back
	call SetTextColor
	jmp LookForKey
main ENDP
END main
