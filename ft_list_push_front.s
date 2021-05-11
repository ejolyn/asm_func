global _ft_list_push_front
extern _malloc

section .text
_ft_list_push_front:
	xor rax, rax
	cmp rdi, 0
		je .head
	push rdi
	push rsi
	mov rdi, 16
	call _malloc
	pop rsi
	pop rdi
	mov [rax], rsi
	mov rcx, [rdi]
	mov [rax + 8], rcx
	mov [rdi], rax
	

.return:
		ret

.head:
	push rdi
	push rsi
	mov rdi, 16
	call _malloc
	pop rsi
	pop rdi
	mov [rax], rsi
	mov [rdi], rax

