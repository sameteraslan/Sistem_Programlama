segment .text
global kucuk

kucuk:
    push ebp
    mov ebp, esp
    sub esp, 4
    mov eax, [ebp+8]  ;1.
    cmp eax, [ebp+12] ; 1. < 2.
    jl cmp1
    
cmp1:
    cmp eax, [ebp+16]
    jl cmp2
    mov eax, [ebp+16]   
cmp2:
    cmp eax, [ebp+20]
    jl result
    mov eax, [ebp+20]


result:
    mov esp, ebp
    pop ebp
    ret