; file		[ft_strcpy.s]
; Author	[Jesse v.d. Wolf]

; function	[char	*ft_strcpy(char *dest, const char *src)]

			section	.text
			global	_ft_strcpy

_ft_strcpy:	mov		rax, rdi				; return first argument to function
			xor		rdx, rdx				; set rdx to 0 so it can be used as index

_loopcheck:
			cmp		byte [rsi + rdx], 0		; check if _end of {src}
			je		_end
			mov		cl, byte [rsi + rdx]	; get one byte from {src} at index rdx
			mov		[rdi + rdx], cl			; write to rdi
			inc		rdx						; increment index rdx
			jmp		_loopcheck				; redo the loop

_end:
			ret
