main:	li $t0, 0
		li $t1, 3
		li $t2, 5

loop:	beq $t0, 20, Exit
		addi $t0, $t0, 1

		div $t0, $t1 #div by 3
		mfhi $t3 

		div $t0, $t2 #div by 5
		mfhi $t4

		add $t5, $t3, $t4

		beq $t5, 0, fbuzz
		beq $t3, 0, buzz
		beq $t4, 0, fizz
		
		j loop

fbuzz:	li $v0, 1
		move $a0, $t0
		syscall
		li $v0, 4
		la $a0, FB
		syscall
		j loop

buzz:	li $v0, 1
		move $a0, $t0
		syscall
		li $v0, 4
		la $a0, B
		syscall
		j loop

fizz:	li $v0, 1
		move $a0, $t0
		syscall
		li $v0, 4
		la $a0, F
		syscall
		j loop

Exit:	jr $ra

.data
F: .asciiz ": Fizz\n"
B: .asciiz ": Buzz\n"
FB: .asciiz ": FizzBuzz\n"

