; asm is read top to bottom
; int ft_strlen(char *str)
; char *str is placed into rdi by default
; rax is return value
; parameters are passed into registers in this order:
;   %rdi, %rsi, %rdx, %rcx, %r8, %r9
;   remaining parameters are pushed into the stack in reverse order
;   so when popped it will be in order

section .text					; defines actual source code section
	global ft_strlen			; exposes the starting point of the program

ft_strlen:
	XOR rcx, rcx				; set rcx to 0, === i = 0 (in this case its i = i ^ i)

loop:
	cmp byte [rdi + rcx], 0		; compare value of rdi + rcx to NULL, === *(str + i) == 0
	je exit						; if equal jump to exit
	inc rcx						; increment rcx, === i++
	jmp loop					; jmp to loop

exit:
	mov rax, rcx				; rax is return value, move rcx into rax
	ret							; return