segment .text
global sumofarray

sumofarray:
    push ebp
    mov ebp, esp

    mov eax, [ebp+12]
    mov ebx, [ebp+8]
    xor ecx,ecx
    mov ecx, [eax]

loop:
    add eax, 4
    add ecx, [eax]
    sub ebx, 1
    cmp ebx, 1
    jne loop

    mov eax, ecx
    mov esp, ebp
    pop ebp
    ret

    
    

    
