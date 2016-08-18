# print.s
# shell code to print a string
# string is placed on the stack
# 
# Author: Ronny Macmaster
# Date: 08/05/16

.section .text
.global _start

_start:
	xor %rax, %rax
	xor %rbx, %rbx
	xor %rcx, %rcx
	xor %rdx, %rdx

