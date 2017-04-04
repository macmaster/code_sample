	.file	"hello.c"
	.section	.rodata
.LC0:
	.string	"Enter a number: "
.LC1:
	.string	"Multiply by: "
.LC2:
	.string	"The product is: %d\n"
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
	subq	$32, %rsp
	movl	$.LC0, %edi
	call	readInteger
	movl	%eax, -12(%rbp)
	movl	$.LC1, %edi
	call	readInteger
	movl	%eax, -16(%rbp)
	movl	$0, -4(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -20(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L2
.L3:
	movl	-20(%rbp), %eax
	addl	%eax, -4(%rbp)
	subl	$1, -8(%rbp)
.L2:
	cmpl	$0, -8(%rbp)
	jne	.L3
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC3:
	.string	"%s"
	.align 8
.LC4:
	.string	"Error, could not read input number!"
.LC5:
	.string	"%d"
	.text
	.globl	readInteger
	.type	readInteger, @function
readInteger:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	jmp	.L5
.L7:
	movl	$.LC4, %edi
	call	puts
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	nop
.L6:
	call	getchar
	cmpl	$10, %eax
	jne	.L6
.L5:
	leaq	-4(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	cmpl	$1, %eax
	jne	.L7
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	readInteger, .-readInteger
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
