	.file	"dpate85-hw2-p1.c"
	.section	.rodata
.LC0:
	.string	"Welcome to CS 261"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L2:
	cmpl	$24, -4(%rbp)
	jle	.L3
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
