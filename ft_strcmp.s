section .note.GNU-stack

section .text
	global ft_strcmp

; int ft_strcmp(char *s1, char *s2)
; rdi = s1, rsi = s2

ft_strcmp:
	mov rcx, -1						; counter initialize to 0

loop:
	inc rcx							; increment counter
	movzx rax, byte[rdi + rcx]		; move byte value of s1 into rax, and pad with 0(s)
	movzx r8, byte[rsi + rcx]		; move byte value of s2 into r8, and pad with 0(s)
	cmp rax, 0						; cmp to null
	cmp r8, 0						; cmp to null
	jz exit							; if zero flag is true, exit
									; je (jump if equal) and jz (jump if zero) do the same thing
									; this just makes it easier for the the reader to understand
	sub rax, r8						; subtract rax with r8 [ rax = rax - r8 ]
	je loop							; if equal, loop

exit:
	ret								; return