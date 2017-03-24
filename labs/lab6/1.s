main:	li $v0, 5
		syscall
		move $t0, $v0
		li $t1, 0 #count
		li $t2, 0 #sum

loop:	beq $t1, $t0, Exit
		add $t2, $t2, $t1
		addi $t1, $t1, 1
		j loop

Exit:	li $v0, 1
		move $a0, $t2
		syscall
		jr $ra