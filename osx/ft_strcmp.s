; file		[ft_strcmp.s]
; Author	[Jesse v.d. Wolf]

; function	[int	ft_strcmp(const char *s1, const char *s2)]

			section	.text
			global	_ft_strcmp

_ft_strcmp:
			mov		rax, -1					    ; set default value to -1	
			xor		rcx, rcx					; make sure register rcx is cleared
			xor		rdx, rdx					; make sure register rdx is cleared

_loopcheck:
			inc		rax							; increment each loop
			mov		cl, byte [rdi + rax]		; move compare byte from first argument to al
			mov		dl, byte [rsi + rax]		; move compare byte from second argument to cl
			cmp		cl, dl						; compare two bytes
			je		_endcheck					; go to _endcheck
			jl		_end						; _end with lesser then
			jg		_end						; _end with greater then

_endcheck:
			cmp		cl, 0						; check if both strings are at _end
			jne		_loopcheck					; if not NULL byte then continue _loopcheck
			xor		rax, rax					; clear rax so it returns 0
			ret

_end:
			sub		rcx, rdx					; subtract rcx from rdx for difference in char
			mov		rax, rcx					; set rax to return value
			ret
