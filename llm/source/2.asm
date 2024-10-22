.MODEL SMALL
.STACK 100h

.DATA
    buffer db 6           
    count db ?     
    input db 5 dup(' ') 
    term db '$'                
    msg db 0Dh, 0Ah, '$'

.CODE
MAIN:
    MOV AX, @DATA
    MOV DS, AX
    MOV ES, AX
    CALL GetUserInput
    LEA DX, msg
    MOV AH, 09h
    INT 21h
    CALL DisplayInput
    MOV AH, 4Ch
    INT 21h

GetUserInput PROC
    LEA DX, buffer            
    MOV AH, 0Ah               
    INT 21h   
    MOV AL, [term]
    LEA DI, input
    ADD DI, 5                 
    MOV [DI], AL              
    RET
GetUserInput ENDP

DisplayInput PROC
    LEA DX, input    
    MOV AH, 09h               
    INT 21h
    RET
DisplayInput ENDP
END MAIN