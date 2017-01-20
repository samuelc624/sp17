 Lab 1 
 ; assignment: develop a code to print a value stored in a register 
 ;             as a hexadecimal number to the monitor
 ; algorithm: turnin each group of four bits into a digit
 ;            calculate the corresponding ASCII character;
 ;            print the character to the monitor

 .ORIG x3000
		
		AND R3, #0
		ADD R3, xBRUH
		STI R3, VALUE
		ADD R0, #4
MEME	ADD R1, #4
		AND R4, #0

		
		ADD R5, R5, R3
		AND R5 X8000
		BRn ECE
		
SHIFT						; take digits from left side (R3) and load from right side into R4
		
		ADD R3, R3, R3
		ADD R1, #-1
		BRp SHIFT
ECE								; if MSB is 0

		ADD R5, R5, R4
PRINT	ADD R5, #-9
		BRzp POOP
		ADD R4, #65
POOP	OUT
		AND R4, #0
		ADD R0, #-1
		BRp MEME



 ; stop the computer
 HALT

 ; program data section starts here

VALUE	.FILL	X4000

 .END

