segment .text
global russian

russian:
    push ebp
    mov ebp, esp

    mov ecx,[ebp+8]         ;x
    mov edx,[ebp+12]        ;y
    xor eax, eax            ;eax = 0 (daha hizli)

next:
    shr ecx, 1              ; eax = eax / 2
    jnc even                
    add eax, edx            ;

even:
    shl edx, 1
    cmp ecx,0
    jne next

    pop ebp
    ret