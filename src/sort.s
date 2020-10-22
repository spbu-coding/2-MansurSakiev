	.file	"sort.c"
	.text
	.p2align 4
	.globl	sort
	.type	sort, @function
sort:
.LFB0:
	.cfi_startproc
	endbr64
	leaq	-1(%rsi), %r8
	testq	%r8, %r8
	jle	.L1
	leaq	-8(%rdi,%rsi,8), %rsi
	.p2align 4,,10
	.p2align 3
.L3:
	movq	%rdi, %rax
	testq	%r8, %r8
	jle	.L6
	.p2align 4,,10
	.p2align 3
.L5:
	movq	(%rax), %rcx
	movq	8(%rax), %rdx
	cmpq	%rdx, %rcx
	jle	.L4
	movq	%rdx, %xmm0
	movq	%rcx, %xmm1
	punpcklqdq	%xmm1, %xmm0
	movups	%xmm0, (%rax)
.L4:
	addq	$8, %rax
	cmpq	%rsi, %rax
	jne	.L5
.L6:
	subq	$8, %rsi
	subq	$1, %r8
	cmpq	%rsi, %rdi
	jne	.L3
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	sort, .-sort
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
