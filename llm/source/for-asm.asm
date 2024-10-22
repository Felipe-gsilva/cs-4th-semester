section .data
    ; Nenhuma se��o de dados necess�ria para esse exemplo simples

section .bss
    ; Nenhuma se��o n�o inicializada necess�ria para esse exemplo simples

section .text
    global _start

_start:
    mov ecx, 1               ; Inicializa o contador com 1

loop_start:
    ; Converte o valor do contador para ASCII e imprime
    mov eax, ecx             ; Move o valor de ECX para EAX
    call PrintNumber         ; Chama a sub-rotina para imprimir o n�mero

    ; Incrementa o contador
    inc ecx
    cmp ecx, 6               ; Verifica se o contador atingiu o valor 6
    jne loop_start           ; Salta de volta para loop_start se n�o for igual a 6

    ; Finaliza o programa
    mov eax, 1               ; C�digo da chamada de sistema para sair
    xor ebx, ebx             ; C�digo de sa�da 0
    int 0x80                 ; Interrup��o para a chamada de sistema do Linux

; Sub-rotina para imprimir um n�mero
PrintNumber:
    add eax, '0'             ; Converte o n�mero em caractere ASCII
    mov [esp-4], eax         ; Armazena o caractere na pilha
    mov eax, 4               ; C�digo da chamada de sistema para escrever
    mov ebx, 1               ; File descriptor (stdout)
    lea ecx, [esp-4]         ; Endere�o do caractere na pilha
    mov edx, 1               ; N�mero de bytes a escrever
    int 0x80                 ; Interrup��o para a chamada de sistema do Linux
    ret                      ; Retorna da sub-rotina
