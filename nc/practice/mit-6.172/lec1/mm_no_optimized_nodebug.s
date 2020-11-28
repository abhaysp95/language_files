	.text
	.file	"mat_multiplication.c"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function tdiff
.LCPI0_0:
	.quad	4517329193108106637     # double 9.9999999999999995E-7
	.text
	.globl	tdiff
	.p2align	4, 0x90
	.type	tdiff,@function
tdiff:                                  # @tdiff
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	subq	(%rcx), %rax
	cvtsi2sd	%rax, %xmm1
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	-8(%rbp), %rcx
	subq	8(%rcx), %rax
	cvtsi2sd	%rax, %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	cvtsd2ss	%xmm1, %xmm0
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	tdiff, .Lfunc_end0-tdiff
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function main
.LCPI1_0:
	.quad	4746794007244308480     # double 2147483647
	.text
	.globl	main
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
	subq	$96, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%fs:40, %rdx
	movq	%rdx, -8(%rbp)
	movl	$0, -44(%rbp)
	movl	%edi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	%rcx, %rdi
	callq	time@PLT
                                        # kill: def $eax killed $eax killed $rax
	movl	%eax, %edi
	callq	srand@PLT
	movl	$0, -60(%rbp)
.LBB1_1:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_3 Depth 2
	cmpl	$2048, -60(%rbp)        # imm = 0x800
	jge	.LBB1_8
# %bb.2:                                #   in Loop: Header=BB1_1 Depth=1
	movl	$0, -64(%rbp)
.LBB1_3:                                #   Parent Loop BB1_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$2048, -64(%rbp)        # imm = 0x800
	jge	.LBB1_6
# %bb.4:                                #   in Loop: Header=BB1_3 Depth=2
	callq	rand@PLT
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	cvtsi2sd	%eax, %xmm1
	divsd	%xmm0, %xmm1
	movslq	-60(%rbp), %rcx
	shlq	$14, %rcx
	leaq	a(%rip), %rdx
	addq	%rcx, %rdx
	movslq	-64(%rbp), %rcx
	movsd	%xmm1, (%rdx,%rcx,8)
	callq	rand@PLT
	movsd	.LCPI1_0(%rip), %xmm0   # xmm0 = mem[0],zero
	cvtsi2sd	%eax, %xmm1
	divsd	%xmm0, %xmm1
	movslq	-60(%rbp), %rcx
	shlq	$14, %rcx
	leaq	b(%rip), %rdx
	addq	%rcx, %rdx
	movslq	-64(%rbp), %rcx
	movsd	%xmm1, (%rdx,%rcx,8)
	movslq	-60(%rbp), %rcx
	shlq	$14, %rcx
	leaq	c(%rip), %rdx
	addq	%rcx, %rdx
	movslq	-64(%rbp), %rcx
	xorps	%xmm0, %xmm0
	movsd	%xmm0, (%rdx,%rcx,8)
# %bb.5:                                #   in Loop: Header=BB1_3 Depth=2
	movl	-64(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -64(%rbp)
	jmp	.LBB1_3
.LBB1_6:                                #   in Loop: Header=BB1_1 Depth=1
	jmp	.LBB1_7
.LBB1_7:                                #   in Loop: Header=BB1_1 Depth=1
	movl	-60(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -60(%rbp)
	jmp	.LBB1_1
.LBB1_8:
	xorl	%eax, %eax
	movl	%eax, %esi
	leaq	-24(%rbp), %rdi
	callq	gettimeofday@PLT
	movl	$0, -68(%rbp)
.LBB1_9:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_11 Depth 2
                                        #       Child Loop BB1_13 Depth 3
	cmpl	$2048, -68(%rbp)        # imm = 0x800
	jge	.LBB1_20
# %bb.10:                               #   in Loop: Header=BB1_9 Depth=1
	movl	$0, -72(%rbp)
.LBB1_11:                               #   Parent Loop BB1_9 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB1_13 Depth 3
	cmpl	$2048, -72(%rbp)        # imm = 0x800
	jge	.LBB1_18
# %bb.12:                               #   in Loop: Header=BB1_11 Depth=2
	movl	$0, -76(%rbp)
.LBB1_13:                               #   Parent Loop BB1_9 Depth=1
                                        #     Parent Loop BB1_11 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	cmpl	$2048, -76(%rbp)        # imm = 0x800
	jge	.LBB1_16
# %bb.14:                               #   in Loop: Header=BB1_13 Depth=3
	movslq	-68(%rbp), %rax
	shlq	$14, %rax
	leaq	a(%rip), %rcx
	addq	%rax, %rcx
	movslq	-72(%rbp), %rax
	movsd	(%rcx,%rax,8), %xmm0    # xmm0 = mem[0],zero
	movslq	-72(%rbp), %rax
	shlq	$14, %rax
	leaq	b(%rip), %rcx
	addq	%rax, %rcx
	movslq	-76(%rbp), %rax
	mulsd	(%rcx,%rax,8), %xmm0
	movslq	-68(%rbp), %rax
	shlq	$14, %rax
	leaq	c(%rip), %rcx
	addq	%rax, %rcx
	movslq	-76(%rbp), %rax
	addsd	(%rcx,%rax,8), %xmm0
	movsd	%xmm0, (%rcx,%rax,8)
# %bb.15:                               #   in Loop: Header=BB1_13 Depth=3
	movl	-76(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -76(%rbp)
	jmp	.LBB1_13
.LBB1_16:                               #   in Loop: Header=BB1_11 Depth=2
	jmp	.LBB1_17
.LBB1_17:                               #   in Loop: Header=BB1_11 Depth=2
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	jmp	.LBB1_11
.LBB1_18:                               #   in Loop: Header=BB1_9 Depth=1
	jmp	.LBB1_19
.LBB1_19:                               #   in Loop: Header=BB1_9 Depth=1
	movl	-68(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -68(%rbp)
	jmp	.LBB1_9
.LBB1_20:
	xorl	%eax, %eax
	movl	%eax, %esi
	leaq	-40(%rbp), %rcx
	movq	%rcx, %rdi
	movq	%rcx, -88(%rbp)         # 8-byte Spill
	callq	gettimeofday@PLT
	leaq	-24(%rbp), %rdi
	movq	-88(%rbp), %rsi         # 8-byte Reload
	movl	%eax, -92(%rbp)         # 4-byte Spill
	callq	tdiff
	cvtss2sd	%xmm0, %xmm0
	leaq	.L.str(%rip), %rdi
	movb	$1, %al
	callq	printf@PLT
	movq	%fs:40, %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	jne	.LBB1_22
# %bb.21:
	xorl	%eax, %eax
	addq	$96, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.LBB1_22:
	.cfi_def_cfa %rbp, 16
	callq	__stack_chk_fail@PLT
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	a,@object               # @a
	.comm	a,33554432,16
	.type	b,@object               # @b
	.comm	b,33554432,16
	.type	c,@object               # @c
	.comm	c,33554432,16
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%0.6f\n"
	.size	.L.str, 7

	.ident	"clang version 10.0.1 "
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym tdiff
	.addrsig_sym srand
	.addrsig_sym time
	.addrsig_sym rand
	.addrsig_sym gettimeofday
	.addrsig_sym printf
	.addrsig_sym __stack_chk_fail
	.addrsig_sym a
	.addrsig_sym b
	.addrsig_sym c
