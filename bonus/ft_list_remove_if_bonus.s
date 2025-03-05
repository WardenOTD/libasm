section .note.GNU-stack

extern free

section .text
	global ft_list_remove_if

; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
; rdi = **begin_list, rsi = *data_ref, rdx = *cmp, rcx = *free_fct

; (*cmp)(list_ptr->data, data_ref);
; rdi = list_ptr->data, rsi = data_ref

;(*free_fct)(list_ptr->data);
; rdi = list_ptr->data

ft_list_remove_if:
	push rbp					; align stack
	mov rbp, rsp				; ^^
	cmp rdi, 0					; compare with 0 ( begin_list == NULL )
	cmp qword [rdi], 0			; compare with 0 ( *begin_list == NULL )
	cmp rsi, 0					; compare with 0 ( data_ref == NULL )
	cmp rdx, 0					; compare with 0 ( cmp == NULL )
	cmp rcx, 0					; compare with 0 ( free_fct == NULL )
	jz exit						; if zero exit
	
init_loop:
	push rbx					; save rbx
	push r12					; save r12
	mov rbx, [rdi]				; cur = *begin_list
	xor r12, r12				; prev = NULL

main_loop:
	cmp qword rbx, 0			; compare with 0
	jz return					; if 0 exit

compare:
	push rdi					; save rdi
	push rsi					; save rsi
	push rdx					; save rdx
	push rcx					; save rcx
	push rbx					; save rbx
	push r12					; save r12

	push r14
	push r15
	mov r14, rbx				; debug purposes [address of rbx]
	mov r15, [rbx]				; debug purposes [data of rbx]
debug:
	pop r15
	pop r14

	mov rdi, [rbx]				; move cur->data to rdi
	call rdx					; call cmp
	pop r12						; restore r12
	pop rbx						; restore rbx
	pop rcx						; restore rcx
	pop rdx						; restore rdx
	pop rsi						; restore rsi
	pop rdi						; restore rdi
	xor r8, r8					; set r8 to 0
	cmp rax, 0					; compare cmp return value with 0
	jnz increment				; if not zero jump increment
	cmp r12, 0					; compare prev with 0
	jz first_node				; if zero jump first_node

not_first_node:
	mov r8, [rbx + 8]			; tmp = cur->next
	mov [r12 + 8], r8			; prev->next = tmp
	jmp delete_node				; jump delete_node

first_node:
	mov r8, [rbx + 8]			; tmp = cur->next
	mov [rdi], r8				; *begin_list = tmp
	jmp delete_node				; jump delete_node

delete_node:
	push rdi					; save rdi
	push rsi					; save rsi
	push rdx					; save rdx
	push rcx					; save rcx
	push rbx					; save rbx
	push r12					; save r12
	mov rdi, [rbx]				; move cur->data to rdi
	call rcx					; call free_fct
	mov rdi, rbx				; move cur to rdi
	call free wrt ..plt			; call free
	pop r12						; restore r12
	pop rbx						; restore rbx
	pop rcx						; restore rcx
	pop rdx						; restore rdx
	pop rsi						; restore rsi
	pop rdi						; restore rdi

reset_current_node:
	cmp r12, 0					; compare prev with 0
	jz no_previous_node			; if zero jump no_previous_node
	mov rbx, [r12 + 8]			; cur = prev->next
	jmp main_loop				; jump main_loop

no_previous_node:
	mov rbx, [rdi]				; cur = *begin_list
	jmp main_loop				; jump main_loop

increment:
	mov r12, rbx				; prev = cur
	mov rbx, [rbx + 8]			; cur = cur->next
	jmp main_loop				; jump main_loop

return:
	pop r12						; restore r12
	pop rbx						; restore rbx

exit:
	mov rsp, rbp				; restore stack frame
	pop rbp						; ^^
	ret							; return