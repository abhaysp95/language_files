	.text
	.file	"main.c"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
.LBB0_1:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_2 Depth 2
	movl	$0, -20(%rbp)
	movl	$1, -24(%rbp)
.LBB0_2:                                #   Parent Loop BB0_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	-20(%rbp), %esi
	leaq	.L.str(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	movl	-20(%rbp), %ecx
	addl	-24(%rbp), %ecx
	movl	%ecx, -28(%rbp)
	movl	-24(%rbp), %ecx
	movl	%ecx, -20(%rbp)
	movl	-28(%rbp), %ecx
	movl	%ecx, -24(%rbp)
# %bb.3:                                #   in Loop: Header=BB0_2 Depth=2
	cmpl	$255, -20(%rbp)
	jl	.LBB0_2
# %bb.4:                                #   in Loop: Header=BB0_1 Depth=1
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
	.addrsig_sym printf
