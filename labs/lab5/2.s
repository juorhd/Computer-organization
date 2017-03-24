.data
msg: 	.asciiz "What is n?: "
star:	.asciiz "*"
newline:.asciiz "\n"

.text
main:	li $v0, 4
		la $a0, msg
		syscall

		li $v0, 5
		syscall
		move $t0, $v0 #t0 = n

		li $t1, 0 #tcount1 = 0;

loop1:	beq $t1, $t0, Exit

		addi $t1, $t1, 1
		
		li $t2,0 #count2 = 0;

		j loop2

back:	li $v0, 4
		la $a0, newline
		syscall

		j loop1

loop2:	beq $t2, $t1, back
		
		li $v0, 4
		la $a0, star
		syscall

		addi $t2, $t2, 1

		j loop2

Exit:	jr $ra