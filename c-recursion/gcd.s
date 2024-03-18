	.text
	.file	"gcd.c"
	.globl	gcd_rec                         # -- Begin function gcd_rec
	.p2align	4, 0x90
	.type	gcd_rec,@function
gcd_rec:                                # @gcd_rec
	.cfi_startproc
# %bb.0:
	movl	%edi, %eax
	testl	%esi, %esi
	je	.LBB0_4
# %bb.1:
	movl	%esi, %edx
	.p2align	4, 0x90
.LBB0_2:                                # =>This Inner Loop Header: Depth=1
	movl	%edx, %ecx
	xorl	%edx, %edx
	divl	%ecx
	movl	%ecx, %eax
	testl	%edx, %edx
	jne	.LBB0_2
# %bb.3:
	movl	%ecx, %eax
.LBB0_4:
	retq
.Lfunc_end0:
	.size	gcd_rec, .Lfunc_end0-gcd_rec
	.cfi_endproc
                                        # -- End function
	.globl	gcd_itr                         # -- Begin function gcd_itr
	.p2align	4, 0x90
	.type	gcd_itr,@function
gcd_itr:                                # @gcd_itr
	.cfi_startproc
# %bb.0:
	movl	%edi, %eax
	testl	%esi, %esi
	je	.LBB1_4
# %bb.1:
	movl	%esi, %edx
	.p2align	4, 0x90
.LBB1_2:                                # =>This Inner Loop Header: Depth=1
	movl	%edx, %ecx
	xorl	%edx, %edx
	divl	%ecx
	movl	%ecx, %eax
	testl	%edx, %edx
	jne	.LBB1_2
# %bb.3:
	movl	%ecx, %eax
.LBB1_4:
	retq
.Lfunc_end1:
	.size	gcd_itr, .Lfunc_end1-gcd_itr
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 14.0.0-1ubuntu1.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
