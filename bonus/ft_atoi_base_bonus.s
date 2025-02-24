section .note.GNU-stack

section .text
	global ft_atoi_base

; int	ft_atoi_base(char *str, char *base)
; rdi = *str, rsi = *base

ft_atoi_base:
	xor rax, rax
	mov rcx, -1

check_base:
	inc rcx
	cmp byte [rsi + rcx], 0
	jz interrupt

check_invalid_low:
	cmp byte [rsi + rcx], 0x09
	jae check_invalid_high
	jmp reset_counter_base_dup

check_invalid_high:
	cmp byte [rsi + rcx], 0x0D
	jbe exit_err
	cmp byte [rsi + rcx], 0x20
	je exit_err
	cmp byte [rsi + rcx], 0x2B
	je exit_err
	cmp byte [rsi + rcx], 0x2D
	je exit_err

reset_counter_base_dup:
	mov r8, rcx

check_base_dup:
	inc r8
	cmp byte [rsi + r8], 0
	jz check_base
	mov r9b, [rsi + r8]
	cmp byte [rsi + rcx], r9b
	je exit_err
	jmp check_base_dup

interrupt:
	cmp rcx, 1
	jbe exit_err

prepare_base:
	push rsi
	push rcx
	call ft_atoi
	cmp rax, 0
	jz exit_err
	pop rcx
	pop rsi
	push rbx
	mov rbx, rcx
	xor r9b, r9b
	xor rdx, rdx
	xor rcx, rcx

convert_base:
	div rbx
	mov r9b, [rsi + rdx]
	push r9
	inc rcx
	cmp rax, 0
	jnz convert_base
	mov rbx, 10

rebuild_base:
	pop r9
	dec rcx
	mul rax
	add rax, r9
	cmp rcx, 0
	jnz rebuild_base

exit:
	pop rbx
	ret

exit_err:
	xor rax, rax
	ret


; ================================================================================= ;

; int	ft_atoi(char *str)
; rdi = *str

ft_atoi:
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
	ret								; return