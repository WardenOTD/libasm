section .text
	global ft_strcpy

; char *ft_strcpy(char *dst, char *src)
; rdi = dst, rsi = src
ft_strcpy:
	XOR rcx, rcx					; set rcx to 0

loop:
	mov byte al, [rsi + rcx]		; move value of rsi + rcx into al
	mov byte [rdi + rcx], al		; move al into rdi + rcx
	cmp al, 0						; check if al is null
	je exit							; exit if equal null
	inc rcx							; increment rcx
	jmp loop						; jump to loop

exit:
	mov rax, rdi					; move rdi into rax
	ret								; return