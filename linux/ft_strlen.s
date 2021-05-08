; file		[ft_strlen.s]
; Author	[Jesse v.d. Wolf]

; function	[size_t	ft_strlen(const char *s)]

			section		.text
			global		ft_strlen

ft_strlen	xor			rax, rax				; sets rax to 0

loopcheck:
			cmp			byte [rdi + rax], 0		; checks if value is NULL byte
			je			end						; jump to _end if equal
			inc			rax						; increment rax with one
			jmp			loopcheck				; go back to start of loop
			ret									; return rax

end:
			ret