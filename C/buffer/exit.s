# exit.s
# exit routine written in gasm
#
# Author: Ronny Macmaster
# Date: 07/30/16

.section .text
.global _start
_start:
	mov $20, %bl
	mov $1, %al
	int $0x80
