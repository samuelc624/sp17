;ADD R5, R5, #0						USE THIS AFTER EVERY SUBROUTINE
;BRp	FAIL
;
;
.ORIG x3000
	
;your code goes here
	



















BRnzp	DONE

FAIL	LEA R0, STRING
	PUTS
DONE	HALT




STRING	.STRINGZ "Invalid Expression."


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R3- value to print in hexadecimal
PRINT_HEX

	
	LDR R3,R6,#0	;let value be stored in R4
	ADD R1,R1,#4	;digit counter

DIGIT	BRz NEXT	;checks if digit counter is 0
	AND R0,R0,#0	;resets used registers for next digit
	AND R4,R4,#0

	AND R2,R2,#0
	ADD R2,R2,#4	;bit counter

BIT	BRz PRINT	
	ADD R4,R4,R4	;shift digit left
	ADD R3,R3,#0	;set nzp
	BRn ONEBIT	;check most significant bit
	BRzp ZEROBIT

ONEBIT	ADD R4,R4,#1	;if negative, add 1
	BRnzp NXTDGT

ZEROBIT	ADD R4,R4,#0	;if positive, add 0
	BRnzp NXTDGT

NXTDGT	ADD R3,R3,R3	;shift R4 left
	ADD R2,R2,#-1	;decrement bit counter
	BRp BIT	;less than 4 digits from R4
	BRnz PRINT	;if 4 bits taken, go to output
	
PRINT	ADD R4,R4,#-10	;calculate offset by subtracting -10 or xA
	BRn NMBR	;if negative, its a number
	BRzp ALPH	;if zero or positive, then letter
	
NMBR	ADD R4,R4,#10	;get number offset
	LD R0,NUM	;load ASCII 0
	ADD R0,R0,R4	;add offset
	OUT		;display
	ADD R1,R1,#-1	;decrement digit counter
	BRnzp DIGIT	;loop
	
ALPH 	LD R0,LETTER	;load ASCII A 
	ADD R0,R0,R4	;add offset
	OUT		;display
	ADD R1,R1,#-1	;decrement digit counter
	BRnzp DIGIT	;loop






;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R0 - character input from keyboard
;R6 - current numerical output
;
;
EVALUATE

;your code goes here










;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
PLUS	
;your code goes here



JSR POP
ADD R5, R5, #0
BRp	RETURN
ADD R4, R0, #0
JSR POP
ADD R5, R5, #0
BRp	RETURN
ADD R3, R0, #0
AND R0, R0, #0
ADD R0, R3, R4
RETURN	RET
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MIN	
;your code goes here

JSR POP
ADD R5, R5, #0
BRp	RETURN	
ADD R4, R0, #0
JSR POP
ADD R5, R5, #0
BRp	RETURN
ADD R3, R0, #0
NOT R4, R4
ADD R4, R4, #1
ADD R0, R3, R4
JSR PUSH
RETURN	RET




	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MUL	
;your code goes here

	JSR POP
	ADD R5, R5, #0
	BRp	RETURN
	ADD R4, R0, #0
	JSR POP
	ADD	R5, R5, #0
	BRp	RETURN
	AND R3, R4, #O
LOOP_M	ADD R4, R4, R0
	ADD R3, R3, #-1
	BRp LOOP_M
	ADD R0, R4, #0
	JSR PUSH
RETURN	RET


	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
DIV	
;your code goes here



JSR POP
ADD R5, R5, #0
BRp	RET
ADD R4, R0, #0
JSR POP
ADD R5, R5, #0
BRp	RET
ADD R3, R0, #0
AND R0, R0, #0
AND R1, R1, #0
ADD R1, R3, R1
ZERO	ADD R0, R0, #1
NOT R4, R4
ADD R4, R4, #1
ADD R1, R1, R4
BRzp	ZERO
ADD R0, R0, #-1
NOT R4, R4
ADD R4, R4, #1
ADD R1, R1, R4
RETURN	RET


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
;EXP
;your code goes here
	
	
	
ST R2, SAVE_R2
	JSR POP
	ADD R5, R5, #0
	BRp	RETURN
	ADD R4, R0, #0
	JSR POP
	ADD R5, R5, #0
	BRp	RETURN
	ADD R3, R0, #0
	AND R3, R3, #0
LOOP_OU	ADD R2, R0, #0
LOOP_IN	ADD R3, R3, R0
	ADD R2, R2, #-1
	BRp LOOP_IN
	ADD R4, R4, #-1
	BRp LOOP_OU
	ADD R0, R3, #0
	JSR PUSH
	LD R2, SAVE_R2
RETURN	RET
SAVE_R2	.BLKW #1
	
	
	
	
	
	
	
	
	
	
	
	
	
	




	
	
	
	
	
	
;IN:R0, OUT:R5 (0-success, 1-fail/overflow)
;R3: STACK_END R4: STACK_TOP
;
PUSH	
	ST R3, PUSH_SaveR3	;save R3
	ST R4, PUSH_SaveR4	;save R4
	AND R5, R5, #0		;
	LD R3, STACK_END	;
	LD R4, STACk_TOP	;
	ADD R3, R3, #-1		;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz OVERFLOW		;stack is full
	STR R0, R4, #0		;no overflow, store value in the stack
	ADD R4, R4, #-1		;move top of the stack
	ST R4, STACK_TOP	;store top of stack pointer
	BRnzp DONE_PUSH		;
OVERFLOW
	ADD R5, R5, #1		;
DONE_PUSH
	LD R3, PUSH_SaveR3	;
	LD R4, PUSH_SaveR4	;
	RET


PUSH_SaveR3	.BLKW #1	;
PUSH_SaveR4	.BLKW #1	;


;OUT: R0, OUT R5 (0-success, 1-fail/underflow)
;R3 STACK_START R4 STACK_TOP
;
POP	
	ST R3, POP_SaveR3	;save R3
	ST R4, POP_SaveR4	;save R3
	AND R5, R5, #0		;clear R5
	LD R3, STACK_START	;
	LD R4, STACK_TOP	;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz UNDERFLOW		;
	ADD R4, R4, #1		;
	LDR R0, R4, #0		;
	ST R4, STACK_TOP	;
	BRnzp DONE_POP		;
UNDERFLOW
	ADD R5, R5, #1		;
DONE_POP
	LD R3, POP_SaveR3	;
	LD R4, POP_SaveR4	;
	RET


POP_SaveR3	.BLKW #1	;
POP_SaveR4	.BLKW #1	;
STACK_END	.FILL x3FF0	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;


.END
