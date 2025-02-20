section .note.GNU-stack

extern __errno_location

section .text
	global ft_write

; int ft_write(int fd, char *buf, int count)
; rdi = fd, rsi = buf, rdx = count

ft_write:
	mov rax, 1							; syscall number for sys_write is 1
										; sys_write : rdi = fd, rsi = buf, rdx = count
										; it's already correct so we don't mov anything
	syscall								; call the kernel
	test rax, rax						; test reg, reg == cmp reg, 0
										; test does a bitwise AND(&) operation
										; i.e. 9 & 9 == 9 || 9 - 0 == 9
	js error							; jump if signed, will jump if result is negtive
	ret

error:
	mov r8, rax							; save sys_write error to general purpose register
	neg r8								; negate subtracts the value by 0, aka 2s complement
										; i.e. 0 - -9 == 9
	call __errno_location wrt ..plt		; __errno_location returns address of errno in c
										; wrt ..plt to fix errors regarding position independant code (PIC)
	mov [rax], r8						; move sys_write error into errno
	mov rax, -1							; -1 as return value
	ret									; return