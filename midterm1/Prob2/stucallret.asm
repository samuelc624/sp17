.ORIG x3000
AND R0, R0, #0;
AND R1, R1, #0
ADD R1, R1, #2
JSR BITSWAP
LEA R0, RETURNED
PUTS
HALT

RETURNED .STRINGZ "Successfully Returned\n"
; x3000

LD R2, STRSTART

LOOP
LDR R0, R2, #0
BRz FINISH		; We are done when we hit NULL
LD R1, BITMASK
JSR BITSWAP		; Do the bitswap
STR R0, R2, #0		; Writes back to the original location
ADD R2, R2, #1
BRnzp LOOP 
FINISH 
HALT

STRSTART .FILL x4000
BITMASK .FILL x0003	; set n = 3

;Do not touch or change and code above this line
;---------------------------------------------
;You must not change the separation line above
;Please write ALL your code for BITSWAP in between the separations lines,
;including all the labels, code, and .FILL commands

 
;Subroutine to swap bits
;Input: 
;R0: the ascii that to be swapped 
;R1: the number of bits to be swapped
; You can assume R1 is always 0, 1, 2, or 3
;Output: R0, the swapped ascii
BITSWAP

ST R4, SAVE_REG1
ST R5, SAVE_REG2
ST R6, SAVE_REG3
ST R7, SAVE_REG
ADD R4, R4, R0
ADD R5, R5, R0
ADD R6, R6, R0


JSR EXTRACT

LEFT	ADD R4, R4, R4
	ADD R1, R1, #-1
	BRp LEFT

LD R3, LAST8
AND R4, R4, R3; LEFTMOST BITS
ADD R4, R0, R4; BITS WITHOUT NOT CHANGED
NOT R6, R6
ADD R6, R6, #-1
ADD R6, R6, R4;NOT CHANGED BITS
ADD R4, R4, R6
AND R0, R0, #0
ADD R0, R4, R0



LD R7, SAVE_REG
LD R4, SAVE_REG1
LD R5, SAVE_REG2
LD R6, SAVE_REG3

RET



LAST8	.FILL x00FF
SAVE_REG	.BLKW #1
SAVE_REG1	.BLKW #1
SAVE_REG2	.BLKW #1
SAVE_REG3	.BLKW #1




;You must not change the separation line below.
;Write all your code for BITSWAP above this line
;=============================================

;DO NOT CHANGE THE GIVEN CODE BELOW
;=============================================
;;EXTRACT Subroutine (Given Code) 
;;Input: R0 - ASCII value
;;       R1 - n (between 0 and 4) bits to be extracted
EXTRACT
ST R0, SAVER1
ST R7, SAVER3
LEA R0, EXCALLED
PUTS
LD R0, SAVER1
LD R7, SAVER3
RET
EXCALLED .STRINGZ "\nEXTRACT CALLED\n"
SAVER1 .FILL #0
SAVER2 .FILL #0
SAVER3 .FILL #0
.END
