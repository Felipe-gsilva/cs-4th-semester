.MODEL SMALL
.STACK 100H

.DATA ; Uso do segment de dados
    vetor DB 9, 8, 7, 6, 5, 4, 3, 2, 1  ; Uso de DB para criar o vetor com bytes definidos
    mensagem DB 0DH, 0AH, 'Vetor ordenado: $'  ; Uso de DB para definir a mensagem
    n EQU 9  

.CODE ; Uso do segment de código
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    CALL BubbleSort  
    CALL DisplayVetor  

   
    MOV AH, 4CH
    INT 21H
MAIN ENDP

BubbleSort PROC
    MOV CX, n-1    
    OuterLoop:
        MOV SI, 0  
        MOV BX, CX 
        InnerLoop:
            MOV AL, [vetor + SI]        
            MOV AH, [vetor + SI + 1]    
            CMP AL, AH                  
            JBE NoSwap                  
            MOV [vetor + SI], AH        
            MOV [vetor + SI + 1], AL    
        NoSwap:
            INC SI                     
            DEC BX                      
            JNZ InnerLoop               
        DEC CX                          
        JNZ OuterLoop                   
    RET
BubbleSort ENDP

DisplayVetor PROC
    LEA DX, mensagem
    MOV AH, 09H
    INT 21H
    MOV CX, n               
    MOV SI, 0                

PrintLoop:
    MOV AL, [vetor + SI]     
    ADD AL, 30H              
    MOV DL, AL               
    MOV AH, 02H              
    INT 21H                  
    INC SI                   
    DEC CX                   
    JNZ PrintLoop            

    MOV AH, 02H
    MOV DL, 0DH              
    INT 21H
    MOV DL, 0AH              

    RET
DisplayVetor ENDP

END MAIN