	.file	"hexmsg.c"
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "enter your msg: \0"
.LC1:
	.ascii "%s\0"
.LC2:
	.ascii "your message: %s\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	movl	$0, -4(%rbp)
	movl	$200, %ecx
	call	malloc
	movq	%rax, -16(%rbp)
	cmpl	$1, 16(%rbp)
	jg	.L2
	leaq	.LC0(%rip), %rcx
	call	printf
	movq	-16(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	jmp	.L3
.L2:
	movq	24(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	strcpy
.L3:
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	movl	%eax, -4(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rcx
	call	printf
	movl	-4(%rbp), %edx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	get_hexmsg
	movq	%rax, -24(%rbp)
	movl	-4(%rbp), %eax
	leal	2(%rax), %edx
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	print_hexmsg
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	get_hexmsg
	.def	get_hexmsg;	.scl	2;	.type	32;	.endef
	.seh_proc	get_hexmsg
get_hexmsg:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	24(%rbp), %eax
	cltq
	addq	$1, %rax
	addq	%rax, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movw	$3, (%rax)
	movl	$1, -4(%rbp)
	jmp	.L6
.L7:
	movl	-4(%rbp), %eax
	cltq
	leaq	(%rax,%rax), %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	leaq	-1(%rax), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	cbtw
	movw	%ax, (%rdx)
	addl	$1, -4(%rbp)
.L6:
	movl	24(%rbp), %eax
	addl	$1, %eax
	cmpl	-4(%rbp), %eax
	jg	.L7
	movl	-4(%rbp), %eax
	cltq
	leaq	(%rax,%rax), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movw	$2, (%rax)
	movq	-16(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC3:
	.ascii "%02X\0"
	.text
	.globl	print_hexmsg
	.def	print_hexmsg;	.scl	2;	.type	32;	.endef
	.seh_proc	print_hexmsg
print_hexmsg:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L10
.L12:
	movl	-4(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L11
	call	__getreent
	movq	16(%rax), %rax
	movq	%rax, %rdx
	movl	$10, %ecx
	call	putc
	call	__getreent
	movq	16(%rax), %rax
	movq	%rax, %rdx
	movl	$120, %ecx
	call	putc
.L11:
	movl	-4(%rbp), %eax
	cltq
	leaq	(%rax,%rax), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzwl	(%rax), %eax
	cwtl
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	addl	$1, -4(%rbp)
.L10:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L12
	movl	-4(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L13
	call	__getreent
	movq	16(%rax), %rax
	movq	%rax, %rdx
	movl	$48, %ecx
	call	putc
	call	__getreent
	movq	16(%rax), %rax
	movq	%rax, %rdx
	movl	$48, %ecx
	call	putc
.L13:
	call	__getreent
	movq	16(%rax), %rax
	movq	%rax, %rdx
	movl	$10, %ecx
	call	putc
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 5.3.0"
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	strcpy;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	__getreent;	.scl	2;	.type	32;	.endef
	.def	putc;	.scl	2;	.type	32;	.endef
