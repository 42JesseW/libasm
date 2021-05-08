; file		[ft_strdup.s]
; Author	[Jesse v.d. Wolf]

; function	[char	*ft_strdup(const char *s)]

			section	.text
			global	ft_strdup

			extern	ft_strlen
			extern	ft_strcpy
			extern	malloc
			extern	__errno_location

ft_strdup:	xor		rax, rax			; clear return register
			xor		rcx, rcx

duplicate:
			push	rdi					; save pointer {*s}
			call	ft_strlen			; get length of {const char *s}; registers already set
			inc		rax					; increment return value with 1 for NULL byte
			push	rax					; save strlen return value
			mov		rdi, rax			; set first argument for malloc
			call	malloc				; call malloc with ptr returned in rax
			pop		rcx					; pop strlen return value from stack
			pop		rsi					; get back pointer {*s} for strcpy {*src}
			cmp		rax, 0				; check if malloc has failed
			je		error				; if error go to error label
			cmp		rcx, 1				; check if lenght of {*s} was 0
			je		end_empty			; if {*s} was empty string go to end_empty
			mov		rdi, rax			; set malloced ptr as first argument {*dest} for strcpy
			call	ft_strcpy			; copy bytes from {*dest} to {*src}
			ret

error:
			push	rax					; store return value of malloc (0)
			push	rbp					; save the stack frame pointer
			mov		rbp, rsp			; set rbp to the current stack pointer to later reset it back
			and		rsp, - 16			; aligning the stack with the nearest multiple of 16
			call	__errno_location	; call [int	* __errno_location(void)]
			mov		rsp, rbp			; reset rsp to current rbp to reset it
			pop		rbp					; set rbp to old rbp
			mov		rdi, rax			; set the return value of __errno_location (int* to errno) to rdi
			mov		byte [rdi], 12		; set errno to 12 ENOMEM. Use [] because pointer
			pop		rax					; pop original return value of malloc and set to strdup return
			ret

end_empty:
			mov		byte [rax], 0		; set single value of returned malloc ptr to 0
			ret