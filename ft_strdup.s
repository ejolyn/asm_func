global _ft_strdup
extern ___error
extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:

section .text
	push rdi
	call _ft_strlen
	mov rdi, rax
	inc rdi
	call _malloc
	pop rdi
	mov rsi, rdi
	mov rdi, rax
	call _ft_strcpy
	ret