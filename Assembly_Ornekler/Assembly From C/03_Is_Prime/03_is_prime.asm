segment .text
global is_prime

is_prime:
  push ebp
  mov ebp, esp              ;ebp((extended) base pointer)
                            ;Fonksiyon calismaya basladigi andaki
                            ;baslangic adresi saklaniyor.
  sub esp, 4

  mov eax, [ebp+8]          ;Parametre(num)

  cmp eax, 2
  je prime
  cmp eax, 3
  je prime
  mov dword [ebp-4], 2      ;sayac = 2
loop:
  mov eax, [ebp+8]          ;eax = num
  mov edx, 0                ;edx = 0 (kalan = 0)
  mov ebx, dword [ebp-4]    ;ebx = sayac
  idiv ebx                  ;eax:edx = eax/sayac
                            ;edx = kalan
                            ;eax = bolum
  mov eax, [ebp+8]          ;eax = num

  cmp edx, 0                ;if num % sayac == 0 -> not_prime
  je not_prime

  inc dword [ebp-4]         ;sayac += 1

  shr eax, 1D               ;eax >> 1
  cmp dword [ebp-4], eax    ;sayac <= eax/2 -> loop
  jle loop
  jmp prime

not_prime:
  mov eax, 0
  mov esp, ebp
  pop ebp
  ret
prime:
  mov eax, 1
  mov esp, ebp
  pop ebp
  ret
