; file		[ft_strdup.s]
; Author	[Jesse v.d. Wolf]

; function	[char	*ft_strdup(const char *s)]

			section	.text
			global	_ft_strdup

			extern	_ft_strlen
			extern	_ft_strcpy
			extern	_malloc
			extern	___error

_ft_strdup:	xor		rax, rax			; clear return register
			xor		rcx, rcx

_duplicate:
			push	rdi					; save pointer {*s}
			call	_ft_strlen			; get length of {const char *s}; registers already set
			inc		rax					; increment return value with 1 for NULL byte
			push	rax					; save strlen return value
			mov		rdi, rax			; set first argument for malloc
			call	_malloc				; call malloc with ptr returned in rax
			pop		rcx					; pop strlen return value from stack
			pop		rsi					; get back pointer {*s} for strcpy {*src}
			cmp		rax, 0				; check if malloc has failed
			je		_error				; if _error go to _error label
			cmp		rcx, 1				; check if lenght of {*s} was 0
			je		_end_empty			; if {*s} was empty string go to _end_empty
			mov		rdi, rax			; set malloced ptr as first argument {*dest} for strcpy
			call	_ft_strcpy			; copy bytes from {*dest} to {*src}
			ret

_error:
			push	rax					; store return value of malloc (0)
			push	rbp					; save the stack frame pointer
			mov		rbp, rsp			; set rbp to the current stack pointer to later reset it back
			and		rsp, - 16			; aligning the stack with the nearest multiple of 16
			call	___error			; call [int	* ___error(void)]
			mov		rsp, rbp			; reset rsp to current rbp to reset it
			pop		rbp					; set rbp to old rbp
			mov		rdi, rax			; set the return value of ___error (int* to errno) to rdi
			mov		byte [rdi], 12		; set errno to 12 ENOMEM. Use [] because pointer
			pop		rax					; pop original return value of malloc and set to strdup return
			ret

_end_empty:
			mov		byte [rax], 0		; set single value of returned malloc ptr to 0
			ret