	.data
vetor: .word 5,9,3,2,10
	.text
main:
	la a0,vetor
	addi a1,zero,5
	lw a3,0(a0)
	addi a4,zero,0
	jal percorre
	nop
	ebreak

percorre:
	beq a1,zero fim
	lw t0,0(a0)
	
	blt t0,a3,menor
	addi a0,a0,4
	addi a1,a1,-1
	addi a4,a4,1
	j percorre
menor:
	addi t1,a4,0
	addi t2,t0,0
	addi a4,a4,1
	addi a3,t0,0
	addi a1,a1,-1
	addi a0,a0,4
	j percorre
fim:
	addi a0,t1,0
	addi a1,t2,0
	ret 
