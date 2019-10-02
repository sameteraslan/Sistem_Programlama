segment .data
k dd 5  ;k = 5

segment .bss
f resd 1

segment .text
global _start

fact:
    ...
    ...
    ...

_start:
    push ebp
    mov ebp, esp

    push dword [k]
    call fact
    add, esp, 4

    pop ebp
    ret