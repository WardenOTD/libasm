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
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	cmp qword [rdi], 0
	cmp rsi, 0
	cmp rdx, 0
	cmp rcx, 0
	jz exit
	
init_loop:
	push rbx
	push r12
	mov rbx, [rdi]
	xor r12, r12

main_loop:
	cmp qword [rbx], 0
	jz return

compare:
	push rdi
	push rsi
	push rdx
	push rcx
	push rbx
	push r12

	push r14
	push r15
	mov r14, rbx
	mov r15, [rbx]
debug:
	pop r15
	pop r14

	mov rdi, [rbx]
	call rdx
	pop r12
	pop rbx
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	xor r8, r8
	cmp rax, 0
	jnz increment
	cmp r12, 0
	jz first_node

not_first_node:
	mov r8, [rbx + 8]
	mov [rdi], r8
	jmp delete_node

first_node:
	mov r8, [rbx + 8]
	mov [r12 + 8], r8
	jmp delete_node

delete_node:
	push rdi
	push rsi
	push rdx
	push rcx
	push rbx
	push r12
	mov rdi, [rbx]
	call rcx
	mov rdi, rbx
	call free wrt ..plt
	pop r12
	pop rbx
	pop rcx
	pop rdx
	pop rsi
	pop rdi

reset_current_node:
	cmp r12, 0
	jz no_previous_node
	mov rbx, [r12 + 8]
	jmp main_loop

no_previous_node:
	mov rbx, [rdi]
	jmp main_loop

increment:
	mov r12, rbx
	mov rbx, [rbx + 8]
	jmp main_loop

return:
	pop r12
	pop rbx

exit:
	mov rsp, rbp
	pop rbp
	ret