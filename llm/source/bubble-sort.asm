section .data
  vector db 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

section .bss
  vector resd 10 

section .text
    global _start


_start:
    mov ecx, 1            
    mov eax [vector + ecx * 4 - 1]
    mov ebx [vector + ecx * 4]

    call loop_start
    
loop_start:
    cmp ecx, 11            
    jge end_program 

    inc ecx
    call sort
    jmp loop_start

sort:
  cmp ebx, eax
  jg swap

swap:
  mov edx, ebx
  mov ebx, eax
  mov eax, edx
  dec ecx
  ret


end_program:


    
