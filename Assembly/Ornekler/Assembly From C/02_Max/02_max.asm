segment .text
global max

max:
  push ebp
  mov ebp, esp      ;ebp((extended) base pointer)
                    ;Fonksiyon calismaya basladigi andaki
                    ;baslangic adresi saklaniyor.
  sub esp, 4

  mov eax, [ebp+8]  ;Son parametre(num2)
  cmp eax, [ebp+12] ;if eax >= [ebp+12] go result label
  jge result
  mov eax, [ebp+12] ;else

result:
  mov esp, ebp
  pop ebp
  ret
