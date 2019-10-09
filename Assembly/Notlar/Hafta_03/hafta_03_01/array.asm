segment .text
global smallest

smallest:
    push ebp
    mov ebp, esp
    push ebx
    sub esp, 4

    mov eax, [ebp+12]  ;smallest will be here
    mov ebx, [eax]
    mov [ebp-8], ebx

    mov edx, [ebp+8]
    mov ecx, [ebp+12]


loop:
    add ecx, 4
    mov eax, [ecx]
    cmp eax, [ebp-8]
    jge next
    mov [ebp-8], eax

next:
    dec edx
    cmp edx, 1
    jne loop

ending:
    mov eax, [ebp-8]
    mov esp, ebp
    sub esp, 4
    pop ebx
    pop ebp
    ret