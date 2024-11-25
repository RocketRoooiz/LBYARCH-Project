section .text
bits 64
default rel

global grayscale

grayscale:
	inc ecx
	mov [rdx], ecx
ret
