; Implement a program to find the nearest smaller (or equal) perfect square of a given positive number
; The input will be stored in R2 and output (the nearest perfect square) should be stored in R3
; TODO: Write a subroutine called "PSquare" which returns the nearest perfect square of a given input and 
;       you must invoke this subroutine in the main part.
; Note : R2, R4, R5 and R6 must be left unchanged in PSquare.
;
; 
; PSquare :  input is stored in R2
;            output is stored in R3

.ORIG	x3000		; starting address is x3000

;;YOUR CODE STARTS HERE

AND R1, R1, #0; PSQUARE REGISTER
AND R3, R3, #0;
AND R4, R4, #0;CHECK REGISTER
AND R5, R5, #0;
AND R6, R6, #0;TEST RESGISTER ADD 1 EVERY LOOP
AND R0, R0, #0;DECREMENT
ADD R6, R6, #1

		
NEG	JSR PSQUARE
	ADD R6, R6, #1	
	NOT R3, R3
	ADD R3, R3, #1
	ADD R4, R3, R2
	BRp NEG
	BRn DONE
	BRz DONE0


DONE0	ADD R6, R6, #-1
	JSR PSQUARE
	HALT


DONE	ADD R6, R6, #-2
	JSR PSQUARE
	HALT

PSQUARE
	ST R7, SAVE_R7
	ADD R0, R6, R0; SAME NUM	
	AND R3, R3, #0
MULT	ADD R3, R6, R3
	ADD R0, R0, #-1
	BRnp MULT	
	LD R7, SAVE_R7
	RET

SAVE_R7	.BLKW #1





.END



