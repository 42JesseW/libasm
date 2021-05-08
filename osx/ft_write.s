; file		[ft_write.s]
; Author	[Jesse v.d. Wolf]

; function	[ssize_t	ft_write(int fd, const void *buf, size_t count)]

			section .text
			global	_ft_write

			extern	___error

_ft_write:	mov		rax, 0x02000004		; set rax to syscall ID for write


_write:
			syscall						; rdi and rsi have alreddy been set so call write
			jc		_error				; if error go to error label
			ret							; else return

_error:
			push	rax					; save error number so its not lost when calling ___error
			push	rbp					; save the stack frame pointer
			mov		rbp, rsp			; set rbp to the current stack pointer to later reset it back
			and		rsp, - 16			; aligning the stack with the nearest multiple of 16
			call	___error			; call [int	* ___error(void)]
			mov		rsp, rbp			; set rsp to current rbp to reset it
			pop		rbp					; set rbp to old rbp
			mov		rdi, rax			; set the return value of ___error (int* to errno) to rdi
			pop		rax					; set rax to its original value (return value from write syscall)
			mov		[rdi], rax			; set errno to this original value (which is the error value). Use [] because pointer
			mov		rax, -1				; set return value of ft_write to -1
			ret
