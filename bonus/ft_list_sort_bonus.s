section .note.GNU-stack

section .text
	global ft_list_sort

; void ft_list_sort(t_list **begin_list, int (*cmp)());
; rdi = **begin, rsi = *cmp

; (*cmp)(list_ptr->data, list_other_ptr->data);
; rdi = list->data, rsi = other_list->data

ft_list_sort:
	push rbp
	mov rbp, rsp
	push rbx
	push r12
	xor r12, r12				; bubble sort flag
	cmp rdi, 0
	cmp rsi, 0
	jz exit
	mov r8, [rdi]				; head
	jmp main_loop

sort_flag:
	mov r12, 1					; set flag to 1 when compare happens

main_loop:
	cmp [rdi], 0
	jz return
	mov rcx, [rdi]
	mov rbx, [rdi + 8]
	cmp 

return:
	mov [rdi], r8

exit:
	pop r12
	pop rbx
	mov rsp, rbp
	pop rbp
	ret