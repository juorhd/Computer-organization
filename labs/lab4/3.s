main:	li $t0, 25
		li $t1, 1000

loop: 	beq $t0, $t1, end
		slt $t2, $t0, $t1
		beq $t2, 1, gcd1
		beq $t2, 0, gcd2

end:	li $v0, 1
		move $a0, $t0
		syscall
		jr $ra

gcd1:	sub $t1, $t1, $t0
		j loop

gcd2:	sub $t0, $t0, $t1
		j loop