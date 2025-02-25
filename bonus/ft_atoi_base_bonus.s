section .note.GNU-stack

section .text
	global ft_atoi_base

; int	ft_atoi_base(char *str, char *base)
; rdi = *str, rsi = *base

ft_atoi_base:
	push rbp						; align stack frame
	mov rbp, rsp					; ^^
	push rbx						; rbx must be pushed whenever used and restored after
	xor rax, rax					; set rax to 0
	mov rcx, -1						; set rcx to -1

check_base:
	inc rcx							; ++rcx
	cmp byte [rsi + rcx], 0			; cmp *base+rcx to null
	jz interrupt					; if zero jump

check_invalid_low:
	cmp byte [rsi + rcx], 0x09		; compare \t
	jae check_invalid_high			; if above or equal, jump
	jmp reset_counter_base_dup		; else jmp to duplicate check

check_invalid_high:
	cmp byte [rsi + rcx], 0x0D		; compare \r
	jbe exit_err					; if between \t and \r jump exit
	cmp byte [rsi + rcx], 0x20		; compare space
	je exit_err						; if equal jump exit
	cmp byte [rsi + rcx], 0x2B		; compare plus
	je exit_err						; if equal jump exit
	cmp byte [rsi + rcx], 0x2D		; compare minus
	je exit_err						; if equal jump exit

reset_counter_base_dup:
	mov r8, rcx						; r8 = rcx

check_base_dup:
	inc r8							; ++r8
	cmp byte [rsi + r8], 0			; compare null
	jz check_base					; if zero jump back to check_base
	mov r9b, [rsi + r8]				; mov next to r9b
	cmp byte [rsi + rcx], r9b		; compore current with next
	je exit_err						; if equal exit
	jmp check_base_dup				; else loop

interrupt:
	cmp rcx, 1						; check len of base
	jbe exit_err					; if 1 or less exit
	mov rbx, rcx					; store len of *base in rbx

; ================================================================================= ;
; int	ft_atoi(char *str)
; rdi = *str
; ================================================================================= ;

ft_atoi:
	xor rax, rax					; set rax to 0
	mov rcx, -1						; set rcx to -1
	mov r8, 1						; set r8 to 1, this will be our sign
	xor r9, r9						; set r9 to 0, this will hold our current number

loop_ws:
	inc rcx							; ++rcx
	cmp byte [rdi + rcx], 0x09		; 0x09 is \t, [\n, \v, \f] is [0x0A, 0x0B, 0x0C]
	jb done							; if lesser than, jump to done
	je loop_ws						; if equal, loop
	cmp byte [rdi + rcx], 0x0D		; 0x0D is \r, the previous 3 whitespace is encased in here
	ja check_space					; if greater than, jump to space check
	je loop_ws						; if equal, loop

check_space:
	cmp byte [rdi + rcx], 0x20		; 0x20 is space
	je loop_ws						; if equal, loop

check_sign:
	cmp byte [rdi + rcx], 0x2B		; 0x2B is +
	je pos_equal					; if equal, jump to pos_equal
	cmp byte [rdi +rcx], 0x2D		; 0x2D is -
	je neg_equal					; if equal, jump to neg_equal
	jne count						; if not equal, jump to count

pos_equal:
	inc rcx							; ++rcx
	jmp check_sign					; loop

neg_equal:
	neg r8							; invert the value of r8 [ r8 = 0 - r8 == -r8]
	inc rcx							; ++rcx
	jmp check_sign					; loop

count:
	xor r11, r11					; set r11 to 0, this count our digit len

loop_actual_int_len:
	cmp byte [rdi + rcx], 0			; compare to 0
	jz prepare_copy					; if zero jump
	cmp byte [rdi + rcx], 0x20		; compare to space
	je prepare_copy					; if equal jump
	cmp byte [rdi + rcx], 0x09		; compare to \t
	je prepare_copy					; if equal jump
	cmp byte [rdi + rcx], 0x0A		; compare to \n
	je prepare_copy					; if equal jump
	cmp byte [rdi + rcx], 0x0B		; compare to \v
	je prepare_copy					; if equal jump
	cmp byte [rdi + rcx], 0x0C		; compare to \f
	je prepare_copy					; if equal jump
	cmp byte [rdi + rcx], 0x0D		; compare to \r
	je prepare_copy					; if equal jump
	inc rcx							; ++rcx
	inc r11							; ++r11
	jmp loop_actual_int_len			; loop

prepare_copy:
	sub rcx, r11					; subtract rcx by r11 (return to start of digit)
	dec r11							; --r11 (base conversion starts with 0 index)

copy_actual_int:
	cmp r11, 0						; compare len of digit to 0
	jb done							; if less than jump
	mov r9b, byte [rdi + rcx]		; set r9b (8bit register of r9) to current byte in str
	jmp init_find_index				; jump

init_find_index:
	push rcx						; store rcx
	mov rcx, -1						; set rcx as -1

find_index:
	inc rcx							; ++rcx
	cmp byte [rsi + rcx], 0			; compare to 0
	jz done							; if zero jump
	cmp r9b, [rsi + rcx]			; compare current with *base
	jne find_index					; if not equal loop
	mov r9, rcx						; set r9 as rcx
	pop rcx							; restore rcx

save_num:
	push rax						; store rax
	mov rax, rbx					; set rax as rbx
	push r11						; store r11
	cmp r11, 0						; compare r11 to 0
	jz last_digit					; if zero jump
	dec r11							; --r11

mul_loop:
	cmp r11, 0						; compare with 0
	je mul_loop_end					; if equal break
	mul rbx							; multiply rax by rbx
	dec r11							; --r11
	jmp mul_loop					; loop

last_digit:
	mov rax, 1						; set rax as 1

mul_loop_end:
	pop r11							; restore r11
	push rax						; store rax
	push r9							; store r9
	pop rax							; restore rax (now rax is r9 because of FILO)
	pop r9							; restore r9 (now r9 is rax)
	mul r9							; multiply rax by r9
	push rax						; store rax
	pop r9							; restore r9 (now r9 is rax)
	pop rax							; restore rax (c:139)
	jc done							; if carry (overflow) exit with what we have
	add rax, r9						; rax + r9
	inc rcx							; ++rcx, ready for next call
	dec r11							; --r11
	jmp copy_actual_int				; loop

done:
	pop rbx							; restore rbx
	mul r8							; multiply rax by our sign
	mov rsp, rbp					; restore stack frame
	pop rbp							; ^^
	ret								; return

exit_err:
	mov rsp, rbp					; restore stack frame
	pop rbp							; ^^
	xor rax, rax					; set return value to 0
	ret								; return