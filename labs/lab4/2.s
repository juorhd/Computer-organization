main: 	li $v0, 1
		li $t0, 4
		li $t1, 5
		blt $t0, $t1, ADD_5
		j NOT_ADD

ADD_5: 	addi $t0, $t0, 5

NOT_ADD:li $v0, 1
		move $a0, $t0
		syscall
		jr $ra