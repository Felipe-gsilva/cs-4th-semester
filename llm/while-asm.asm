org 100h                    ; Define o endereço inicial do código em programas de 16 bits (para DOS)

start:
    mov cx, 1               ; Inicializa o contador (CX) com 1

while_loop:
    ; Verifica a condição do loop (CX < 6)
    cmp cx, 6               ; Compara o contador com 6
    jge end_program         ; Se CX >= 6, salta para o final do programa

    ; Converte o valor do contador para ASCII e imprime
    mov ax, cx              ; Move o valor de CX para AX (prepara o número para a sub-rotina)
    mov bl, 10              ; Define a base para conversão (não usado diretamente aqui)

    call PrintNumber        ; Chama a sub-rotina PrintNumber para converter e imprimir o número

    ; Incrementa o contador
    inc cx                  ; Incrementa o valor do contador em 1

    jmp while_loop          ; Volta para o início do loop

end_program:
    ; Finaliza o programa
    mov ah, 4Ch             ; Define a função de término do programa
    int 21h                 ; Chama a interrupção do DOS para terminar o programa

; Sub-rotina para imprimir um número
PrintNumber:
    mov ah, 02h             ; Função para imprimir um caractere
    mov dl, al              ; Move o valor de AL para DL (o caractere a ser impresso)
    add dl, '0'             ; Converte o número para o caractere ASCII
    int 21h                 ; Chama a interrupção do DOS para imprimir o caractere
    ret                     ; Retorna da sub-rotina
