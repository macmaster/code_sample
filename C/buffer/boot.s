# boot.s
#
# kernel entry point for ronny_linux
# lot of reference to wiki.osdev.org/Bare_Bones
# and www.gnu.org/software/grub/manual/multiboot/multiboot.html
#
# Author: Ronny Macmaster
# Date: 07/08/2016

# multiboot header constants
.set ALIGN,		1<<0					# alignment modules within page boundaries
.set MEMINFO,	1<<1					# request memory map
.set FLAGS,		ALIGN | MEMINFO	# multiboot flag vector
.set MAGIC,		0x1BADB002			# magic id number to find header
.set CHECKSUM, -(MAGIC + FLAGS)	# unsigned checksum verify sums to 0

# multiboot header to mark program as a kernel.
# bootloader searches for this signature in the first 8KiB of the kernel file
# aligned to a 32-bit boundary. putting it in it's own section forces it to be
# within the first 8KiB of the kernel file.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# kernel needs to provide a 16KiB stack. 
# this stack grows downward and has a special symbol at the bottom
# marked nobits means the stack is uninitialized w. no data
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384
stack_top:

# _start headers
# kernel entry point begins at _start as specfied by the linker script.
# bootloader jumps into start once the kernel has been loaded.
.section .text
.global _start
.type _start, @function

# _start
# once it enters start, we are in 32bit protected mode on an x86 machine.
# interrupts and paging are disabled, and kernel has full control over CPU.
# kernel provides all the code and implementation.
# at this point, kernel has absolute power over the machine.
_start:

	# init the stack pointer for the C kernel
	mov $stack_top, %esp

	# (optional) initialize the processor state here before kernel

	# call the kernel
	call kernel_main

# if sys finishes / exits the kernel, 
# disable the interrupts with cli and sleep it with halt.
# repeat the process.
halt_lp:	
	cli
	hlt
	jmp halt_lp
