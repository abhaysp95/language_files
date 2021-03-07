	.text
	.file	"main.cpp"
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90                         # -- Begin function __cxx_global_var_init
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	_ZStL8__ioinit(%rip), %rdi
	callq	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	leaq	_ZStL8__ioinit(%rip), %rsi
	leaq	__dso_handle(%rip), %rdx
	callq	__cxa_atexit@PLT
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc
                                        # -- End function
	.text
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
.Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, DW.ref.__gxx_personality_v0
	.cfi_lsda 27, .Lexception0
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$160, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	movl	$0, -52(%rbp)
	movl	%edi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movl	$5, -68(%rbp)
	movl	$5, -32(%rbp)
	movl	$4, -28(%rbp)
	movl	$3, -24(%rbp)
	movl	$2, -20(%rbp)
	movl	$1, -16(%rbp)
	leaq	-48(%rbp), %rdi
	callq	_ZN8demo_objC2Ev
	movl	$4, %edi
	callq	_Znwm@PLT
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movl	$5, (%rax)
	movl	$20, %edi
	callq	_Znam@PLT
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movl	$5, (%rax)
	movq	-88(%rbp), %rax
	movl	$4, 4(%rax)
	movq	-88(%rbp), %rax
	movl	$3, 8(%rax)
	movq	-88(%rbp), %rax
	movl	$2, 12(%rax)
	movq	-88(%rbp), %rax
	movl	$1, 16(%rax)
	movl	$12, %edi
	callq	_Znwm@PLT
	movq	%rax, %rcx
	movq	%rax, %rdx
.Ltmp0:
	movq	%rax, %rdi
	movq	%rcx, -120(%rbp)                # 8-byte Spill
	movq	%rdx, -128(%rbp)                # 8-byte Spill
	callq	_ZN8demo_objC2Ev
.Ltmp1:
	jmp	.LBB1_1
.LBB1_1:
	movq	-128(%rbp), %rax                # 8-byte Reload
	movq	%rax, -96(%rbp)
	movq	-80(%rbp), %rcx
	cmpq	$0, %rcx
	movq	%rcx, -136(%rbp)                # 8-byte Spill
	je	.LBB1_3
# %bb.2:
	movq	-136(%rbp), %rax                # 8-byte Reload
	movq	%rax, %rdi
	callq	_ZdlPv@PLT
.LBB1_3:
	movq	-88(%rbp), %rax
	cmpq	$0, %rax
	movq	%rax, -144(%rbp)                # 8-byte Spill
	je	.LBB1_5
# %bb.4:
	movq	-144(%rbp), %rax                # 8-byte Reload
	movq	%rax, %rdi
	callq	_ZdaPv@PLT
.LBB1_5:
	movq	-96(%rbp), %rax
	cmpq	$0, %rax
	movq	%rax, -152(%rbp)                # 8-byte Spill
	je	.LBB1_7
# %bb.6:
	movq	-152(%rbp), %rax                # 8-byte Reload
	movq	%rax, %rdi
	callq	_ZdlPv@PLT
.LBB1_7:
	movq	%fs:40, %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	.LBB1_11
# %bb.8:
	xorl	%eax, %eax
	addq	$160, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.LBB1_9:
	.cfi_def_cfa %rbp, 16
.Ltmp2:
                                        # kill: def $edx killed $edx killed $rdx
	movq	%rax, -104(%rbp)
	movl	%edx, -108(%rbp)
	movq	-120(%rbp), %rdi                # 8-byte Reload
	callq	_ZdlPv@PLT
# %bb.10:
	movq	-104(%rbp), %rdi
	callq	_Unwind_Resume@PLT
.LBB1_11:
	callq	__stack_chk_fail@PLT
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.p2align	2
GCC_except_table1:
.Lexception0:
	.byte	255                             # @LPStart Encoding = omit
	.byte	255                             # @TType Encoding = omit
	.byte	1                               # Call site Encoding = uleb128
	.uleb128 .Lcst_end0-.Lcst_begin0
.Lcst_begin0:
	.uleb128 .Lfunc_begin0-.Lfunc_begin0    # >> Call Site 1 <<
	.uleb128 .Ltmp0-.Lfunc_begin0           #   Call between .Lfunc_begin0 and .Ltmp0
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp0-.Lfunc_begin0           # >> Call Site 2 <<
	.uleb128 .Ltmp1-.Ltmp0                  #   Call between .Ltmp0 and .Ltmp1
	.uleb128 .Ltmp2-.Lfunc_begin0           #     jumps to .Ltmp2
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp1-.Lfunc_begin0           # >> Call Site 3 <<
	.uleb128 .Lfunc_end1-.Ltmp1             #   Call between .Ltmp1 and .Lfunc_end1
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
.Lcst_end0:
	.p2align	2
                                        # -- End function
	.section	.rodata.cst4,"aM",@progbits,4
	.p2align	2                               # -- Begin function _ZN8demo_objC2Ev
.LCPI2_0:
	.long	0x41f00000                      # float 30
.LCPI2_1:
	.long	0x41a00000                      # float 20
.LCPI2_2:
	.long	0x41200000                      # float 10
	.section	.text._ZN8demo_objC2Ev,"axG",@progbits,_ZN8demo_objC2Ev,comdat
	.weak	_ZN8demo_objC2Ev
	.p2align	4, 0x90
	.type	_ZN8demo_objC2Ev,@function
_ZN8demo_objC2Ev:                       # @_ZN8demo_objC2Ev
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movss	.LCPI2_0(%rip), %xmm0           # xmm0 = mem[0],zero,zero,zero
	movss	.LCPI2_1(%rip), %xmm1           # xmm1 = mem[0],zero,zero,zero
	movss	.LCPI2_2(%rip), %xmm2           # xmm2 = mem[0],zero,zero,zero
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movss	%xmm2, (%rax)
	movss	%xmm1, 4(%rax)
	movss	%xmm0, 8(%rax)
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end2:
	.size	_ZN8demo_objC2Ev, .Lfunc_end2-_ZN8demo_objC2Ev
	.cfi_endproc
                                        # -- End function
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90                         # -- Begin function _GLOBAL__sub_I_main.cpp
	.type	_GLOBAL__sub_I_main.cpp,@function
_GLOBAL__sub_I_main.cpp:                # @_GLOBAL__sub_I_main.cpp
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	callq	__cxx_global_var_init
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end3:
	.size	_GLOBAL__sub_I_main.cpp, .Lfunc_end3-_GLOBAL__sub_I_main.cpp
	.cfi_endproc
                                        # -- End function
	.type	_ZStL8__ioinit,@object          # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.section	.init_array,"aw",@init_array
	.p2align	3
	.quad	_GLOBAL__sub_I_main.cpp
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.DW.ref.__gxx_personality_v0,"aGw",@progbits,DW.ref.__gxx_personality_v0,comdat
	.p2align	3
	.type	DW.ref.__gxx_personality_v0,@object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.ident	"clang version 11.0.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym __cxx_global_var_init
	.addrsig_sym __cxa_atexit
	.addrsig_sym _Znwm
	.addrsig_sym _Znam
	.addrsig_sym __gxx_personality_v0
	.addrsig_sym _ZdlPv
	.addrsig_sym _ZdaPv
	.addrsig_sym _GLOBAL__sub_I_main.cpp
	.addrsig_sym _Unwind_Resume
	.addrsig_sym __stack_chk_fail
	.addrsig_sym _ZStL8__ioinit
	.addrsig_sym __dso_handle
