; file		[ft_strcpy.s]
; Author	[Jesse v.d. Wolf]

; function	[char	*ft_strcpy(char *dest, const char *src)]

			section	.text
			global	ft_strcpy

ft_strcpy:	mov		rax, rdi				; return first argument to function
			xor		rdx, rdx				; set rdx to 0 so it can be used as index

loopcheck:
			cmp		byte [rsi + rdx], 0		; check if end of {src}
			je		end
			mov		cl, byte [rsi + rdx]	; get one byte from {src} at index rdx
			mov		[rdi + rdx], cl			; write to rdi
			inc		rdx						; increment index rdx
			jmp		loopcheck				; redo the loop

end:
			ret
