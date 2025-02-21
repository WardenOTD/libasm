section .note.GNU-stack

extern __errno_location
extern malloc

section .text
	global ft_strdup

; char *ft_strdup(const char *s)
; rdi = s

ft_strdup:
	mov rcx, -1

src_len:
	inc rcx
	cmp byte [rdi + rcx], 0
	jnz src_len

alloc:
	push rdi
	inc rcx
	mov rdi, rcx
	call malloc wrt ..plt
	test rax, rax
	jz error

prepare_copy:
	mov rdi, rax
	mov rcx, -1
	pop rsi

copy:
	inc rcx
	mov byte al, [rsi + rcx]
	mov byte [rdi + rcx], al
	test al, al
	jz success
	jmp copy

success:
	mov rax, rdi
	ret

error:
	pop rdi
	mov r8, rax
	call __errno_location wrt ..plt
	mov [rax], r8
	mov rax, 0
	ret