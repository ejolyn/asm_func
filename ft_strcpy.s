global _ft_strcpy

section .text
_ft_strcpy:
	mov rcx, 0

.loop:
	mov dl, byte [rsi + rcx]
	mov byte [rdi + rcx], dl
	cmp dl, 0
	je .return
	inc rcx
	jmp .loop

.return:
	mov rax, rdi
	ret