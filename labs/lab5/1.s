.data
msg: 	.asciiz "input n: "
newline:.asciiz "\n"

.text
main: 	li $v0, 4
		la $a0, msg
		syscall

		li $v0, 5
		syscall
		move $t0, $v0

		li $t1, 0

loop:	beq $t1, $t0, Exit
		
		li $v0, 1
		move $a0, $t1
		syscall

		li $v0, 4
		la $a0, newline
		syscall

		addi $t1, $t1, 1

		j loop

Exit:	jr $ra