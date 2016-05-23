	.file	"hw3.c"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$16, %esp
	movl	$-559038737, -16(%ebp)
	movl	$0, -12(%ebp)
	movl	$1, -8(%ebp)
	jmp	.L2
.L3:
	movl	-8(%ebp), %eax
	andl	-16(%ebp), %eax
	testl	%eax, %eax
	setne	%al
	movzbl	%al, %eax
	addl	%eax, -12(%ebp)
	sall	-8(%ebp)
.L2:
	cmpl	$0, -8(%ebp)
	jne	.L3
	addl	$16, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-55)"
	.section	.note.GNU-stack,"",@progbits
