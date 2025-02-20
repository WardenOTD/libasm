section .note.GNU-stack			; versions binutils 2.39+ will raise a warning without this section

; size_t ft_strlen(const char *str)
; *str is placed into rdi by default
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
