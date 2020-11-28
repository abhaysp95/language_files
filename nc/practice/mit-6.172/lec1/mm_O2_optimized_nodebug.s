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
	movq	(%rsi), %rax
	movq	8(%rsi), %rcx
	subq	(%rdi), %rax
	cvtsi2sd	%rax, %xmm0
	subq	8(%rdi), %rcx
	cvtsi2sd	%rcx, %xmm1
	mulsd	.LCPI0_0(%rip), %xmm1
	addsd	%xmm0, %xmm1
	xorps	%xmm0, %xmm0
	cvtsd2ss	%xmm1, %xmm0
	retq
.Lfunc_end0:
	.size	tdiff, .Lfunc_end0-tdiff
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function main
.LCPI1_0:
	.quad	4746794007244308480     # double 2147483647
.LCPI1_1:
	.quad	4517329193108106637     # double 9.9999999999999995E-7
	.text
	.globl	main
	.p2align	4, 0x90
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
	pushq	%r13
	.cfi_def_cfa_offset 40
	pushq	%r12
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	subq	$56, %rsp
	.cfi_def_cfa_offset 112
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	%fs:40, %rax
	movq	%rax, 48(%rsp)
	xorl	%ebx, %ebx
	xorl	%edi, %edi
	callq	time@PLT
	movl	%eax, %edi
	callq	srand@PLT
	leaq	a(%rip), %r14
	leaq	b(%rip), %r15
	leaq	c(%rip), %r12
	xorl	%eax, %eax
	.p2align	4, 0x90
.LBB1_1:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_2 Depth 2
	movq	%rax, 8(%rsp)           # 8-byte Spill
	xorl	%ebp, %ebp
	.p2align	4, 0x90
.LBB1_2:                                #   Parent Loop BB1_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	callq	rand@PLT
	xorps	%xmm0, %xmm0
	cvtsi2sd	%eax, %xmm0
	divsd	.LCPI1_0(%rip), %xmm0
	leaq	(%rbx,%rbp), %r13
	movsd	%xmm0, (%r14,%r13)
	callq	rand@PLT
	movsd	.LCPI1_0(%rip), %xmm1   # xmm1 = mem[0],zero
	xorps	%xmm0, %xmm0
	cvtsi2sd	%eax, %xmm0
	divsd	%xmm1, %xmm0
	movsd	%xmm0, (%r15,%r13)
	movq	$0, (%r12,%r13)
	addq	$8, %rbp
	cmpq	$16384, %rbp            # imm = 0x4000
	jne	.LBB1_2
# %bb.3:                                #   in Loop: Header=BB1_1 Depth=1
	movq	8(%rsp), %rax           # 8-byte Reload
	addq	$1, %rax
	addq	$16384, %rbx            # imm = 0x4000
	cmpq	$2048, %rax             # imm = 0x800
	jne	.LBB1_1
# %bb.4:
	xorl	%ebx, %ebx
	leaq	32(%rsp), %rdi
	xorl	%esi, %esi
	callq	gettimeofday@PLT
	leaq	c+48(%rip), %rax
	leaq	b+48(%rip), %rcx
	.p2align	4, 0x90
.LBB1_5:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_6 Depth 2
                                        #       Child Loop BB1_7 Depth 3
	movq	%rcx, %rdx
	xorl	%esi, %esi
	.p2align	4, 0x90
.LBB1_6:                                #   Parent Loop BB1_5 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB1_7 Depth 3
	movq	%rbx, %rdi
	shlq	$14, %rdi
	addq	%r14, %rdi
	movsd	(%rdi,%rsi,8), %xmm0    # xmm0 = mem[0],zero
	unpcklpd	%xmm0, %xmm0    # xmm0 = xmm0[0,0]
	xorl	%edi, %edi
	.p2align	4, 0x90
.LBB1_7:                                #   Parent Loop BB1_5 Depth=1
                                        #     Parent Loop BB1_6 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movapd	-48(%rdx,%rdi,8), %xmm1
	mulpd	%xmm0, %xmm1
	movapd	-32(%rdx,%rdi,8), %xmm2
	mulpd	%xmm0, %xmm2
	addpd	-48(%rax,%rdi,8), %xmm1
	addpd	-32(%rax,%rdi,8), %xmm2
	movapd	%xmm1, -48(%rax,%rdi,8)
	movapd	%xmm2, -32(%rax,%rdi,8)
	movapd	-16(%rdx,%rdi,8), %xmm1
	mulpd	%xmm0, %xmm1
	movapd	(%rdx,%rdi,8), %xmm2
	mulpd	%xmm0, %xmm2
	addpd	-16(%rax,%rdi,8), %xmm1
	addpd	(%rax,%rdi,8), %xmm2
	movapd	%xmm1, -16(%rax,%rdi,8)
	movapd	%xmm2, (%rax,%rdi,8)
	addq	$8, %rdi
	cmpq	$2048, %rdi             # imm = 0x800
	jne	.LBB1_7
# %bb.8:                                #   in Loop: Header=BB1_6 Depth=2
	addq	$1, %rsi
	addq	$16384, %rdx            # imm = 0x4000
	cmpq	$2048, %rsi             # imm = 0x800
	jne	.LBB1_6
# %bb.9:                                #   in Loop: Header=BB1_5 Depth=1
	addq	$1, %rbx
	addq	$16384, %rax            # imm = 0x4000
	cmpq	$2048, %rbx             # imm = 0x800
	jne	.LBB1_5
# %bb.10:
	leaq	16(%rsp), %rdi
	xorl	%esi, %esi
	callq	gettimeofday@PLT
	movq	16(%rsp), %rax
	movq	24(%rsp), %rcx
	subq	32(%rsp), %rax
	xorps	%xmm0, %xmm0
	cvtsi2sd	%rax, %xmm0
	subq	40(%rsp), %rcx
	xorps	%xmm1, %xmm1
	cvtsi2sd	%rcx, %xmm1
	mulsd	.LCPI1_1(%rip), %xmm1
	addsd	%xmm0, %xmm1
	xorps	%xmm0, %xmm0
	cvtsd2ss	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	.L.str(%rip), %rdi
	movb	$1, %al
	callq	printf@PLT
	movq	%fs:40, %rax
	cmpq	48(%rsp), %rax
	jne	.LBB1_12
# %bb.11:
	xorl	%eax, %eax
	addq	$56, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%r12
	.cfi_def_cfa_offset 40
	popq	%r13
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.LBB1_12:
	.cfi_def_cfa_offset 112
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
	.addrsig_sym __stack_chk_fail
