section .data

divisor dd 255.0

section .text
bits 64
default rel

global ASMimgCvtGrayInttoFloat

ASMimgCvtGrayInttoFloat:
	; RCX height
	; RDX width
	; R8 input values
	; R9 output values

	xor R10, R10						; counter for i
	movss xmm1, [divisor]

outer_loop:
	cmp R10, RCX						; check if i is reached
	je done_outer_loop

	mov RAX, [R8 + R10*8]				; pointer to row i
    mov RBX, [R9 + R10*8]
	xor R11, R11						; counter for j

inner_loop:
	cmp R11, RDX						; check if j is reached
	je done_inner_loop

	movzx R12, byte [RAX + R11]

	cvtsi2ss xmm0, R12
	divss xmm0, xmm1

	movss dword [RBX + R11*4], xmm0
	inc R11
	jmp inner_loop


done_inner_loop:
	inc R10
	jmp outer_loop

done_outer_loop:

ret
