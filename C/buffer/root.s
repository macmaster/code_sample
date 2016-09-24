# root.s
# request root access with 
# setreuid
#
# Author: Ronny Macmaster
# Date: 07/30/16

.section .text
.global _start
_start:
	xor %rax, %rax
	xor %rbx, %rbx
	xor %rcx, %rcx
	mov $70, %al 	# setreuid = 70 in IDT
	int $0x80
