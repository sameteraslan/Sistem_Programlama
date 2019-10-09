segment .text
global sumofarray

sumofarray:
    push ebp
    mov ebp, esp
    push ebx
    sub esp, 4

    mov eax, [ebp+12]  ;smallest will be here
    mov ebx, [eax]
    mov [ebp-8], ebx

    mov edx, [ebp+8]
    mov ecx, [ebp+12]
    xor ebx, ebx
    add ebx, [ecx]

loop:
    add ecx, 4
    mov eax, [ecx]
    add ebx, eax
    dec edx
    cmp edx, 1
    jne loop

ending:
    mov eax, ebx
    mov esp, ebp
    sub esp, 4
    pop ebx
    pop ebp
    ret