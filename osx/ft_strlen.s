; file		[ft_strlen.s]
; Author	[Jesse v.d. Wolf]

; function	[size_t	ft_strlen(const char *s)]

			section		.text
			global		_ft_strlen

_ft_strlen	xor			rax, rax				; sets rax to 0

_loopcheck:
			cmp			byte [rdi + rax], 0		; checks if value is NULL byte
			je			_end					; jump to __end if equal
			inc			rax						; increment rax with one
			jmp			_loopcheck				; go back to start of loop
			ret									; return rax

_end:
			ret