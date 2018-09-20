.data
	direita byte ">",0
	esquerda byte "<",0
	cima byte "^",0
	baixo byte "v",0
	pos_x byte 12
	pos_y byte 12
	max_x byte 12
	max_y byte 12
.code
Player_1 PROC
	call ReadKey
	cmp dx, VK_RIGHT
	je dir 
	cmp dx, VK_UP
	je cim
	cmp dx, VK_LEFT
	je esq
	cmp dx, VK_DOWN
	je bai
	ret
dir:
	mov edx, offset direita	
	call WriteString
	inc pos_y
	jmp print
esq:
	mov edx, offset esquerda	
	call WriteString
	dec pos_y
	cmp pos_y,0
	jmp print

cim:
	mov edx, offset cima	
	call WriteString
	dec pos_x
	jmp print
bai:
	mov edx, offset baixo
	call WriteString
	inc pos_x
	jmp print
print:
	mov  dl,pos_y  ;column
    mov  dh,pos_x  ;row
	Call Gotoxy
	ret
Player_1 ENDP
