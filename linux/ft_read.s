; file		[ft_read.s]
; Author	[Jesse v.d. Wolf]

; function	[ssize_t	ft_read(int fd, const void *buf, size_t count)]

			section .text
			global	ft_read
			
			extern	__errno_location

ft_read:	mov		rax, 0				; set rax to syscall ID for write


read:
			syscall						; rdi and rsi have alreddy been set so call write
			cmp		rax, 0				; check if return value of syscall is smaller then 0
			jl		error				; if error go to error label
			ret							; else return

error:
			neg		rax					; negate return value to get abosule error number
			push	rax					; save error number so its not lost when calling __errno_location
			push	rbp					; save the stack frame pointer
			mov		rbp, rsp			; set rbp to the current stack pointer to later reset it back
			and		rsp, - 16			; aligning the stack with the nearest multiple of 16
			call	__errno_location	; call [int	* __errno_location(void)]
			mov		rsp, rbp			; set rsp to current rbp to reset it
			pop		rbp					; set rbp to old rbp
			mov		rdi, rax			; set the return value of __errno_location (int* to errno) to rdi
			pop		rax					; set rax to its original value (return value from write syscall)
			mov		[rdi], rax			; set errno to this original value (which is the error value). Use [] because pointer
			mov		rax, -1				; set return value of ft_read to -1
			ret