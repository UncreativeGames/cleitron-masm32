.data
quantos_players BYTE "Quantos jogadores?<1..2>",0
selecione_a_cor BYTE "Qual a cor do seu CleiTron?",10,13,"[W]hite",10,13,"[C]yan"
;question BYTE "Qual a cor do Jogador 1?<0..9>",10,13
answer   DWORD ?

.code
Menu PROC
init:
	mov edx, offset quantos_players
	call WriteString
	call ReadKey
	cmp dx, '1'
	je Single
	cmp dx, '2'
	je Multi
	jmp init
color:
	mov edx, offset selecione_a_cor
	call WriteString
	call ReadKey
	cmp dx, 'W'
	je Single
	cmp dx, 'C'
	je Multi
	jmp color
Menu ENDP
