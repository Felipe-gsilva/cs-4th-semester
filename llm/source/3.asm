.model small
.stack 100h

.data
    tec db 'Tecle um digito hexadecimal: $'
    input db 2 dup (''), '$'
    con db 0Dh, 0Ah, 'Deseja continuar? (S/N): $'
    tryagain db 0Dh, 0Ah, 'Valor fora da faixa. Tente novamente.$'
    hexval db 0Dh, 0Ah, 'Valor decimal: $'
    msg db 0Dh, 0Ah, '$'

.code
MAIN:
    mov ax, @data
    mov ds, ax

LoopStart:
    mov ah, 09h
    lea dx, tec
    int 21h
    mov ah, 01h
    int 21h
    mov bl, al
    cmp bl, '0'
    jl InvalidInput
    cmp bl, '9'
    jle ConvertHex

    cmp bl, 'A'
    jl InvalidInput
    cmp bl, 'F'
    jle ConvertHex

    cmp bl, 'a'
    jl InvalidInput
    cmp bl, 'f'
    jle ConvertHex

InvalidInput:
    mov ah, 09h
    lea dx, tryagain
    int 21h
    jmp LoopStart

ConvertHex:
    cmp bl, '0'
    jl InvalidInput
    cmp bl, '9'
    jle ConvertNumber
    sub bl, 7

ConvertNumber:
    sub bl, '0'
    mov ax, bx
    mov ah, 09h
    lea dx, hexval
    int 21h

    call PrintDecimal
    mov ah, 09h
    lea dx, con
    int 21h

    mov ah, 01h
    int 21h
    cmp al, 'S'
    je LoopStart
    mov ah, 4Ch
    int 21h

PrintDecimal PROC
    mov cx, 0 
    mov bx, 10   

PrintLoop:
    xor dx, dx
    div bx    
    add dl, '0'
    push dx    
    inc cx     
    test ax, ax 
    jnz PrintLoop
    
PrintDigits:
    pop dx         
    mov ah, 02h    
    int 21h
    loop PrintDigits

    ret
PrintDecimal ENDP

END MAIN
