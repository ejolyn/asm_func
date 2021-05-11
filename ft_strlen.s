global _ft_strlen

section .text
_ft_strlen:
	xor rcx, rcx

.loop:
	cmp byte [rdi], 0
	je .return
	inc rcx
	inc rdi
	jmp .loop

.return:
	mov rax, rcx
	ret