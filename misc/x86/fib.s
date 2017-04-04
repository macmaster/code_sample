# fibonacci x86 subroutine.
# calculates the nth fibonacci number
# int fib(int n);
# returns the value in EAX

.globl fib
fib:
	pushq %rbp
	movq %rsp, %rbp
	push %rcx

	# base case, n < 2
	cmp $2, %rdi
	jae calc
	mov $1, %rax
	jmp done


calc: # fib(n) = fib(n - 1) + fib(n - 2)
	mov %rdi, %rcx
	subq $2, %rdi
	call fib
	movq %rcx, %rdi
	subq $1, %rdi
	movq %rax, %rcx
	call fib
	addq %rcx, %rax

done:
	popq %rcx
	popq %rbp
	ret
