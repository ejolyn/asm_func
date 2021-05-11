global _ft_strcmp

section .text
_ft_strcmp:
	xor rax, rax
	xor rcx, rcx
	xor rdx, rdx

.loop:
	mov dl, byte [rsi + rax]
	mov cl, byte [rdi + rax]
	cmp dl, 0
		je .return
	cmp cl, dl
		jne .return
	inc rax
	jmp .loop


.return:
	sub rcx, rdx
	mov rax, rcx
	ret