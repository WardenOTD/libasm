section .note.GNU-stack

extern __errno_location
extern malloc

section .text
	global ft_strdup

; char *ft_strdup(const char *s)
; rdi = s

ft_strdup:
	mov rcx, -1							; rcx = -1

src_len:
	inc rcx								; ++rcx
	cmp byte [rdi + rcx], 0				; loop *s until null
	jnz src_len							; if not null loop

alloc:
	push rdi							; save *s to stack
	inc rcx								; rcx += 1 for null terminator
	mov rdi, rcx						; move rcx to rdi to pass into malloc
	call malloc wrt ..plt				; call malloc
	test rax, rax						; compare rax to 0
	jz error							; if 0 jump error

prepare_copy:
	mov rdi, rax						; move rax to rdi (our allocated pointer)
	mov rcx, -1							; rcx = -1
	pop rsi								; restore *s into rsi

copy:
	inc rcx								; ++rcx
	mov byte al, [rsi + rcx]			; move *s into al
	mov byte [rdi + rcx], al			; move al into rdi
	test al, al							; check if al is null
	jz success							; if zero jump success
	jmp copy							; else loop

success:
	mov rax, rdi						; move rdi to rax to return
	ret									; return

error:
	pop rdi								; empty the stack in case malloc failed
	mov r8, rax							; move rax into r8
	call __errno_location wrt ..plt		; get address of errno
	mov [rax], r8						; put r8 into errno
	mov rax, 0							; return 0 because strdup returns null on error
	ret									; return