	.text
	.intel_syntax noprefix
	.file	"main.cpp"
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90                         # -- Begin function __cxx_global_var_init
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	lea	rdi, [rip + _ZStL8__ioinit]
	call	_ZNSt8ios_base4InitC1Ev@PLT
	mov	rax, qword ptr [rip + _ZNSt8ios_base4InitD1Ev@GOTPCREL]
	mov	rdi, rax
	lea	rsi, [rip + _ZStL8__ioinit]
	lea	rdx, [rip + __dso_handle]
	call	__cxa_atexit@PLT
	pop	rbp
	.cfi_def_cfa rsp, 8
	ret
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
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 160
	mov	rax, qword ptr fs:[40]
	mov	qword ptr [rbp - 8], rax
	mov	dword ptr [rbp - 52], 0
	mov	dword ptr [rbp - 56], edi
	mov	qword ptr [rbp - 64], rsi
	mov	dword ptr [rbp - 68], 5
	mov	dword ptr [rbp - 32], 5
	mov	dword ptr [rbp - 28], 4
	mov	dword ptr [rbp - 24], 3
	mov	dword ptr [rbp - 20], 2
	mov	dword ptr [rbp - 16], 1
	lea	rdi, [rbp - 48]
	call	_ZN8demo_objC2Ev
	mov	edi, 4
	call	_Znwm@PLT
	mov	qword ptr [rbp - 80], rax
	mov	rax, qword ptr [rbp - 80]
	mov	dword ptr [rax], 5
	mov	edi, 20
	call	_Znam@PLT
	mov	qword ptr [rbp - 88], rax
	mov	rax, qword ptr [rbp - 88]
	mov	dword ptr [rax], 5
	mov	rax, qword ptr [rbp - 88]
	mov	dword ptr [rax + 4], 4
	mov	rax, qword ptr [rbp - 88]
	mov	dword ptr [rax + 8], 3
	mov	rax, qword ptr [rbp - 88]
	mov	dword ptr [rax + 12], 2
	mov	rax, qword ptr [rbp - 88]
	mov	dword ptr [rax + 16], 1
	mov	edi, 12
	call	_Znwm@PLT
	mov	rcx, rax
	mov	rdx, rax
.Ltmp0:
	mov	rdi, rax
	mov	qword ptr [rbp - 120], rcx      # 8-byte Spill
	mov	qword ptr [rbp - 128], rdx      # 8-byte Spill
	call	_ZN8demo_objC2Ev
.Ltmp1:
	jmp	.LBB1_1
.LBB1_1:
	mov	rax, qword ptr [rbp - 128]      # 8-byte Reload
	mov	qword ptr [rbp - 96], rax
	mov	rcx, qword ptr [rbp - 80]
	cmp	rcx, 0
	mov	qword ptr [rbp - 136], rcx      # 8-byte Spill
	je	.LBB1_3
# %bb.2:
	mov	rax, qword ptr [rbp - 136]      # 8-byte Reload
	mov	rdi, rax
	call	_ZdlPv@PLT
.LBB1_3:
	mov	rax, qword ptr [rbp - 88]
	cmp	rax, 0
	mov	qword ptr [rbp - 144], rax      # 8-byte Spill
	je	.LBB1_5
# %bb.4:
	mov	rax, qword ptr [rbp - 144]      # 8-byte Reload
	mov	rdi, rax
	call	_ZdaPv@PLT
.LBB1_5:
	mov	rax, qword ptr [rbp - 96]
	cmp	rax, 0
	mov	qword ptr [rbp - 152], rax      # 8-byte Spill
	je	.LBB1_7
# %bb.6:
	mov	rax, qword ptr [rbp - 152]      # 8-byte Reload
	mov	rdi, rax
	call	_ZdlPv@PLT
.LBB1_7:
	mov	rax, qword ptr fs:[40]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	.LBB1_11
# %bb.8:
	xor	eax, eax
	add	rsp, 160
	pop	rbp
	.cfi_def_cfa rsp, 8
	ret
.LBB1_9:
	.cfi_def_cfa rbp, 16
.Ltmp2:
                                        # kill: def $edx killed $edx killed $rdx
	mov	qword ptr [rbp - 104], rax
	mov	dword ptr [rbp - 108], edx
	mov	rdi, qword ptr [rbp - 120]      # 8-byte Reload
	call	_ZdlPv@PLT
# %bb.10:
	mov	rdi, qword ptr [rbp - 104]
	call	_Unwind_Resume@PLT
.LBB1_11:
	call	__stack_chk_fail@PLT
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
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	movss	xmm0, dword ptr [rip + .LCPI2_0] # xmm0 = mem[0],zero,zero,zero
	movss	xmm1, dword ptr [rip + .LCPI2_1] # xmm1 = mem[0],zero,zero,zero
	movss	xmm2, dword ptr [rip + .LCPI2_2] # xmm2 = mem[0],zero,zero,zero
	mov	qword ptr [rbp - 8], rdi
	mov	rax, qword ptr [rbp - 8]
	movss	dword ptr [rax], xmm2
	movss	dword ptr [rax + 4], xmm1
	movss	dword ptr [rax + 8], xmm0
	pop	rbp
	.cfi_def_cfa rsp, 8
	ret
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
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	call	__cxx_global_var_init
	pop	rbp
	.cfi_def_cfa rsp, 8
	ret
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
