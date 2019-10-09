segment .text
global sum

sum:
  push ebp
  mov ebp, esp      ;ebp((extended) base pointer)
                    ;Fonksiyon calismaya basladigi andaki
                    ;baslangic adresi saklaniyor.
  sub esp, 4

  mov eax, [ebp+8]  ;Son parametre(num2)
  add eax, [ebp+12] ;num2 += num1

  mov esp, ebp
  pop ebp
  ret
