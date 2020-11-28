	.text
	.file	"main.c"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset %rbx, -16
	leaq	.L.str(%rip), %rbx
	.p2align	4, 0x90
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movq	%rbx, %rdi
	xorl	%esi, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$1, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$1, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$2, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$3, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$5, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$8, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$13, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$21, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$34, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$55, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$89, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$144, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	movl	$233, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	jmp	.LBB0_1
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%d\n"
	.size	.L.str, 4

	.ident	"clang version 10.0.1 "
	.section	".note.GNU-stack","",@progbits
	.addrsig
