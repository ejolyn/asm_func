global _ft_atoi_base

section .text
_ft_atoi_base:
	mov rcx, -1 ; counter for converted string
	mov al, -1 ; sign 
.checkspaces:				; cycle for check spaces
	inc rcx
	cmp byte[rdi + rcx], 9
		je .checkspaces
	cmp byte[rdi + rcx], 10
		je .checkspaces
	cmp byte[rdi + rcx], 11
		je .checkspaces
	cmp byte[rdi + rcx], 12
		je .checkspaces
	cmp byte[rdi + rcx], 13
		je .checkspaces
	cmp byte[rdi + rcx], 32
		je .checkspaces
	dec rcx
.checksign:
	inc rcx
	cmp byte[rdi + rcx], 45
	
	mov rax, 1
	ret