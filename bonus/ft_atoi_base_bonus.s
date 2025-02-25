section .note.GNU-stack

section .text
	global ft_atoi_base

; int	ft_atoi_base(char *str, char *base)
; rdi = *str, rsi = *base

ft_atoi_base:
	push rbp
	mov rbp, rsp
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
	cmp rcx, 1						; check base of len
	jbe exit_err					; if 1 or less exit

prepare_base:
	push rsi						; save rsi (our base)
	push rcx						; save rcx (our length of base)
	call ft_atoi					; call atoi on rdi
	cmp rax, 0						; compare atoi return to 0
	jz exit_err						; if zero exit
	pop rcx							; restore rcx
	pop rsi							; restore base
	push rbx						; push rbx
	mov rbx, rcx					; rbx == rcx
	xor r9b, r9b					; reset r9b to 0
	xor rcx, rcx					; set rcx to 0

check_negative:
	cmp rax, 0
	mov r8, 1
	jb set_negative
	jmp convert_base

set_negative:
	neg r8
	neg rax

convert_base:
	xor rdx, rdx					; set rdx to 0
	div rbx							; divide rax by rbx
	jc rebuild_base					; jump if overflow, return what we have so far
	movzx r9, byte [rsi + rdx]		; mov into r9b *(rsi + rdx)
	push r9							; push r9
	inc rcx							; ++rcx(counting how many times we push)
	cmp rax, 0						; cmp rax to 0
	jnz convert_base				; if not zero loop
	mov rbx, 10						; else set rbx = 10

rebuild_base:
	pop r9							; restore r9
	dec rcx							; --rcx
	mul rbx							; multiply rax by rbx
	add rax, r9						; add r9 to rax
	cmp rcx, 0						; compare rcx to 0
	jnz rebuild_base				; if not zero loop

exit:
	pop rbx							; restore rbx
	mul r8							; multiply by sign

return:
	mov rsp, rbp
	pop rbp
	ret								; return

exit_err:
	xor rax, rax					; set return value to 0
	jmp return

; ================================================================================= ;

; int	ft_atoi(char *str)
; rdi = *str

ft_atoi:
	push rbp
	mov rbp, rsp
	push rbx						; rbx must be pushed whenever used and restored after
	mov rbx, 10						; set rbx to 10, this is our multiplier
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
	mov r9b, byte [rdi + rcx]		; set r9b (8bit register of r9) to current byte in str
	inc rcx							; ++rcx, ready for next call
	cmp byte r9b, 0					; compare to null
	jz done							; if null exit
	cmp byte r9b, 0x30				; compare to ascii 0
	jb done							; if less than, exit
	cmp byte r9b, 0x39				; compare to ascii 9, [1 to 8 is encased in here]
	ja done							; if greater than, exit

save_num:
	mul rbx							; mul dest is hardcoded at rax, so rax *= rbx
	jc done							; if carry (overflow) exit with what we have
	sub r9b, 0x30					; subtract r9b with ascii 0, giving us an int
	add rax, r9						; rax + r9, [10 + 1 == 11]
	jmp count						; loop

done:
	pop rbx							; restore rbx
	mul r8							; multiply rax by our sign
	mov rsp, rbp
	pop rbp
	ret								; return