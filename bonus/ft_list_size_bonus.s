section .note.GNU-stack

section .text
	global ft_list_size

; int ft_list_size(t_list *begin_list);
; rdi = *begin_list

ft_list_size:
	push rbp				; align stack
	mov rbp, rsp			; ^^
	mov rax, -1				; set rax as -1
	mov rsi, rdi			; copy rdi into rsi

loop:
	inc rax					; ++rax
	cmp rsi, 0				; compare rsi to 0
	jz return				; if zero return
	mov rsi, [rsi + 8]		; move [rsi + 8] into rsi, lst = lst->next
	jmp loop				; loop

return:
	mov rsp, rbp			; restore stack
	pop rbp					; ^^
	ret						; return