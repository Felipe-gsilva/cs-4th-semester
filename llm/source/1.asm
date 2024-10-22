.model small
.stack 100h
.DATA
    array db 5, 3, 8, 1, 2, 9, 4, 7, 6
    n equ 9
    msg db 0Dh, 0Ah, '$'

.CODE
MAIN:
    MOV AX, @DATA
    MOV DS, AX
    MOV ES, AX
    LEA SI, array
    MOV CX, n
    CALL Sort
    LEA DX, msg
    MOV AH, 09h
    INT 21h
    CALL Display
    MOV ah, 4Ch
    INT 21h

Sort proc
    MOV BX, CX
    DEC BX
OuterLoop:
    MOV SI, 0
    MOV CX, BX
InnerLoop:
    MOV AL, [array + SI]
    MOV DL, [array + SI + 1]
    CMP AL, DL
    JBE NoSwap
    XCHG AL, DL
    MOV [array + SI], AL
    MOV [array + SI + 1], DL
NoSwap:
    INC SI
    LOOP InnerLoop
    DEC BX
    JNZ OuterLoop
    RET
Sort ENDP

Display PROC
    MOV CX, n
    MOV SI, 0
PrintLoop:
    MOV AL, [array + SI]
    ADD AL, 30h
    MOV AH, 02h
    MOV DL, AL
    INT 21h
    INC SI
    LOOP PrintLoop
    RET
Display ENDP
END MAIN
