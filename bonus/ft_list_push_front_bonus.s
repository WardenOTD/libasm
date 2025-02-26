section .note.GNU-stack

extern malloc

section .text
	global ft_list_push_front

; void ft_list_push_front(t_list **begin_list, void *data);
; rdi = **begin_list, rsi = *data

ft_list_push_front:
	push rbp				; align stack
	mov rbp, rsp			; ^^
	xor rax, rax			; set rax to 0

get_new_list:
	push rdi				; store rdi
	push rsi				; store rsi
	mov rdi, 16				; set rdi as 16, struck has 2 pointers, on x64 sizeof(pointer) = 8
	call malloc wrt ..plt	; call malloc
	pop rsi					; restore rsi
	pop rdi					; restore rdi
	cmp rax, 0				; compare rax to 0, malloc fail
	jz done					; jump exit
	mov [rax], rsi			; move rsi (*data) into rax, lst->data = rsi

add_to_front:
	mov rcx, [rdi]			; move of rdi to rcx
	mov [rax + 8], rcx		; move rcx into [rax + 8], lst->next = rcx
	mov [rdi], rax			; move rax into rdi

done:
	mov rsp, rbp			; restore stack
	pop rbp					; ^^
	ret						; return