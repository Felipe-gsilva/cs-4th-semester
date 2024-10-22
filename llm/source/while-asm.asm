org 100h                    ; Define o endere�o inicial do c�digo em programas de 16 bits (para DOS)

start:
    mov cx, 1               ; Inicializa o contador (CX) com 1

while_loop:
    ; Verifica a condi��o do loop (CX < 6)
    cmp cx, 6               ; Compara o contador com 6
    jge end_program         ; Se CX >= 6, salta para o final do programa

    ; Converte o valor do contador para ASCII e imprime
    mov ax, cx              ; Move o valor de CX para AX (prepara o n�mero para a sub-rotina)
    mov bl, 10              ; Define a base para convers�o (n�o usado diretamente aqui)

    call PrintNumber        ; Chama a sub-rotina PrintNumber para converter e imprimir o n�mero

    ; Incrementa o contador
    inc cx                  ; Incrementa o valor do contador em 1

    jmp while_loop          ; Volta para o in�cio do loop

end_program:
    ; Finaliza o programa
    mov ah, 4Ch             ; Define a fun��o de t�rmino do programa
    int 21h                 ; Chama a interrup��o do DOS para terminar o programa

; Sub-rotina para imprimir um n�mero
PrintNumber:
    mov ah, 02h             ; Fun��o para imprimir um caractere
    mov dl, al              ; Move o valor de AL para DL (o caractere a ser impresso)
    add dl, '0'             ; Converte o n�mero para o caractere ASCII
    int 21h                 ; Chama a interrup��o do DOS para imprimir o caractere
    ret                     ; Retorna da sub-rotina
