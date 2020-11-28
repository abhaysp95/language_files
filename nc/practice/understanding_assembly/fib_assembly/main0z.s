	.text
	.file	"main.c"
	.globl	main                    # -- Begin function main
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	pushq	%rax
	.cfi_def_cfa_offset 48
	.cfi_offset %rbx, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	pushq	$1
	.cfi_adjust_cfa_offset 8
	popq	%r14
	.cfi_adjust_cfa_offset -8
	leaq	.L.str(%rip), %r15
.LBB0_1:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_2 Depth 2
	movl	%r14d, %eax
	xorl	%ebp, %ebp
.LBB0_2:                                #   Parent Loop BB0_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	%eax, %ebx
	movq	%r15, %rdi
	movl	%ebp, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	addl	%ebx, %ebp
	movl	%ebp, %eax
	movl	%ebx, %ebp
	cmpl	$255, %ebx
	jl	.LBB0_2
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
