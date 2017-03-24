#Name: Ding Li

.data
matrix_a:			.space 64
newline:			.asciiz "\n"
tab:        		.asciiz "\t"
matrix_A:   		.asciiz "Enter the values for matrix A:\n"
scalar_B:     		.asciiz "Enter a scalar b:\n"
Matrix_A_times_b:	.asciiz "Product of A x b:\n"

.text
main:
	store_stack:
		addi $sp, $sp, -4
    	sw $ra, 0($sp)

	output_matrix_A:
		li $v0, 4 
		la $a0, matrix_A
		syscall

	li $t0, 0 # $t0 = i
	A_loop:
		beq $t0, 64, output_scalar_B	
		li $v0, 5
        syscall
        sw $v0, matrix_a($t0)
        addi $t0, $t0, 4
        j A_loop
    
    output_scalar_B:
    	li $v0, 4 
		la $a0, scalar_B 
		syscall

	read_b:
		li $v0, 5
		syscall
		move $t2, $v0 # $t2 = b

	output_Matrix_A_times_b:
		li $v0, 4
		la $a0, Matrix_A_times_b
		syscall

	la $s0, matrix_a
	li $t0, 0 # $t0 = i
	calculate_output:
		column_loop_head:
			beq $t0, 4, load_stack
			j column_loop_body

		column_loop_body:
			li $t1, 0 # $t1 = j
			j row_loop_head

			row_loop_head:
				beq $t1, 4, j_exit

			row_loop_body:
				sll $t3, $t0, 2 	# t3 = 4i
				add $t3, $t3, $t1 	# t3 = 4i + j
				sll $t3, $t3, 2 	# t3 = 16i + 4j
				add $t3, $t3, $s0 	# t3 = matrix_a + 16i + 4j
				lw $t4, 0($t3) 	    # t4 = matrix_a[4i+j]
				mult $t4, $t2 		# matrix_a[4i+j] * b
				mflo $t4 			# t4 = matrix_a[4i+j] * b
				
				li  $v0, 1           
    			add $a0, $t4, $zero
    			syscall

				j row_loop_latch

			row_loop_latch:
				li $v0, 4
        		la $a0, tab
        		syscall
				addi $t1, $t1, 1
				j row_loop_head

			j_exit:
				j column_loop_latch

		column_loop_latch:
			li $v0, 4
        	la $a0, newline
        	syscall
			addi $t0, $t0, 1
			j column_loop_head


	load_stack:
		lw $ra, 0($sp)
    	addi $sp, $sp, 4
    
    jr $ra