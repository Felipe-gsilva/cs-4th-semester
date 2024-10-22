.model small          ; Modelo de mem�ria pequeno

.data                 ; Se��o de dados
contador dw 0         ; Inicializa a vari�vel contador com o valor 0
espaco db 2           ; Reserva um espa�o de 2 bytes na mem�ria


.code                 ; Se��o de c�digo
ORG 1000h

; Declara uma fun��o global
incrementa_contador proc
    mov ax, contador  ; Move o valor de contador para AX
incrementa:
    inc ax            ; Incrementa AX em 1
    mov contador, ax  ; Armazena o valor de AX de volta em contador
    cmp ax, 6         ; Compara o valor de AX com 6
    jne incrementa    ; Se AX n�o for 6, continua incrementando
    ret               ; Retorna da fun��o
incrementa_contador endp

ADD proc
    mov ax, 0         ; Inicializa AX com 0
somar:
    inc ax            ; Incrementa AX em 1
    cmp ax, 6         ; Compara AX com 6
    jne somar         ; Se AX n�o for 6, continua somando
    ret               ; Retorna da fun��o
ADD endp

main proc
    mov ax, @data     ; Carrega o segmento de dados em AX
    mov ds, ax        ; Inicializa DS com o segmento de dados

    call incrementa_contador  ; Chama a fun��o incrementa_contador
    call ADD                  ; Chama a fun��o ADD

    ; Finaliza��o do programa
    mov ax, 4C00h     ; C�digo de sa�da
    int 21h           ; Chama a interrup��o para finalizar o programa
main endp

end main              ; Define o ponto de entrada do programa
