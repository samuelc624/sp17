; Lab 1 
 ; assignment: develop a code to print a value stored in a register 
 ;             as a hexadecimal number to the monitor
 ; algorithm: turnin each group of four bits into a digit
 ;            calculate the corresponding ASCII character;
 ;            print the character to the monitor

.ORIG x3000
AND	R5,R5,#0
ADD R6,R6,#4
AND R1,R1,#0
MEME	ADD R1,R1,#4
AND R4,R4,#0
ADD R5,R5,R3
AND R5,R5,#-1
SHIFT	BRzp ECE	;take digits from left side (R3) and load from right side into R4
ADD R4,R4,#1
ADD R4,R4,R4
ADD R1,R1,#-1
BRp SHIFT
ECE		ADD R5,R5,R5						; if MSB is 0
ADD R5,R5,R4
PRINT	ADD R5,R5,#-9
BRzp POOP
ADD R4,R4,xA
ADD R4,R4,#-10
POOP	OUT
AND R4,R4,#0
ADD R6,R6,#-1
BRp MEME



 ; stop the computer
 HALT

 ; program data section starts here


 .END

