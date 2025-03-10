section .note.GNU-stack

section .text
	global ft_list_sort

; void ft_list_sort(t_list **begin_list, int (*cmp)());
; rdi = **begin, rsi = *cmp

; (*cmp)(list_ptr->data, list_other_ptr->data);
; rdi = list->data, rsi = other_list->data

ft_list_sort:
	push rbp					; align stack
	mov rbp, rsp				; ^^
	push rbx					; save rbx ( rbx, r12 - r15 need to be saved and restored after use)
	push r12					; save r12
	xor r12, r12				; bubble sort flag
	cmp rdi, 0					; compare with 0 ( begin == NULL )
	cmp rsi, 0					; compare with 0 ( cmp == NULL )
	jz exit						; if zero exit
	mov r8, [rdi]				; save linked list head
	mov r12, 0					; set flag to 0 ( keep track of comparisons )
	jmp main_loop				; start loop

sort_flag:
	mov r12, 1					; set flag to 1 when compare happens

increment:
	mov rcx, [rcx + 8]			; cur = cur->next
	mov [rdi], rcx				; set rdi to next

main_loop:
	cmp qword [rdi], 0			; compare with 0
	jz return					; if 0 exit
	mov rcx, [rdi]				; rcx = *rdi, ( rcx = *current )
	mov rbx, [rcx + 8]			; rbx = *(rcx + 8), ( rbx = next )
	cmp rbx, 0					; check if last node
	jz check_sort				; if zero jump

compare:
	push rdi					; save rdi
	push rsi					; save rsi
	pop r9						; r9 = rsi
	mov rdi, [rcx]				; move cur->data to rdi
	mov rsi, [rbx]				; move next->data to rsi
	push rcx					; save rcx
	push rbx					; save rbx
	call r9						; call function pointer
	mov rsi, r9					; rsi = r9
	pop rbx						; restore rbx
	pop rcx						; restore rcx
	pop rdi						; restore rdi
; debug:
	cmp eax, 0					; compare rax to 0
	jle increment				; if lesser than or equal, loop

swap:
	mov r9, [rcx]				; r9 = cur->data
	mov r10, [rbx]				; r10 = next->data
	mov [rbx], r9				; cur->data = r9
	mov [rcx], r10				; next->data = r10
	jmp sort_flag				; jump to sort_flag

check_sort:
	cmp r12, 0					; compare flag to 0
	mov [rdi], r8				; set rdi back to start
	mov r12, 0					; set flag to 0
	ja main_loop				; if not 0 when compared (l:87), loop
	jmp exit					; exit

return:
	mov [rdi], r8				; set rdi back to start

exit:
	pop r12						; restore r12
	pop rbx						; restore rbx
	mov rsp, rbp				; restore stack
	pop rbp						; ^^
	ret							; return