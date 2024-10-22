.model small
.stack 10h
; Definindo uma constante
VALOR1 EQU 2

.data                 ; In�cio do segmento de dados

; Definindo vari�veis
NUM1 db VALOR1        ; NUM1 armazenar� o valor 2
NUM2 db 4             ; NUM2 armazenar� o valor 4
RESULTADO db 0        ; Vari�vel para armazenar o resultado

.code                 ; In�cio do segmento de c�digo
ORG 1000h

main proc
    mov ax, @data     ; Carrega o segmento de dados em AX
    mov ds, ax        ; Inicializa DS com o segmento de dados

    ; Carregar os valores em registradores
    mov al, NUM1      ; Carrega o valor de NUM1 em AL
    add al, NUM2      ; Adiciona o valor de NUM2 a AL

    NOP               ; Simula uma pausa

    mov RESULTADO, al ; Armazena o resultado

    ; Finaliza o programa
    mov ax, 4C00h     ; C�digo de sa�da
    int 21h
main endp

end main              ; Fim do programa
