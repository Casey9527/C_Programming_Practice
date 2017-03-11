
al_off	equ     8	; offset from ebp to low  bits of a (al)
ah_off	equ     12	; offset from ebp to high bits of a (ah)
bl_off	equ     16	; offset from ebp to low  bits of b (bl)
bh_off	equ     20	; offset from ebp to high bits of b (bh)
res_off	equ     24	; offset from ebp to result array pointer

section .data
num1_high   dd  0xFFFEFFFF
num1_low    dd  0xFFFFFFFF
num2_high   dd  0xFFFF0001
num2_low    dd  0xFFFFFFFF
res0    dd  0x00000000
res1    dd  0x00000000
res2    dd  0x00000000
res3    dd  0x00000000

section .text
    align	16
    bits	32
    global _start

_start:
    mov eax, num1_high
    mov ebx, num1_low
    mov ecx, num2_high
    mov edx, num2_low
    push eax
    push ebx
    push ecx
    push edx
    
    call llmultiply



llmultiply:
    push ebp
    mov ebp, esp
		
    push eax
    push ebx
    push ecx
    push edx	
    push edi
    push esi
    
    mov eax, [ebp + al_off]
    mov edx, [ebp + bl_off]
    mul edx			            ; al * bl, eax = low(al * bl), edx = high(al * bl)
    
    mov edi, eax	            ; save low(al * bl) in edi
    mov esi, edx                ; save high(al * bl) in esi
    
    mov eax, [ebp + ah_off]
    mov edx, [ebp + bl_off]
    mul edx			            ; ah * bl, eax = low(ah * bl), edx = high(ah * bl)
    
    add esi, eax	            ; add low(ah * bl) to high(al * bl)
;    adc ecx, edx               	; add carry from the previous addition to high(ah * bl) and save in ecx

   adc edx, 0
   mov ecx, edx


    mov eax, [ebp + al_off]
    mov edx, [ebp + bh_off]
    mul edx                 	; al * bh, eax = low(al * bh), edx = high(al * bh)

    add esi, eax             	; add low(al * bh) to high(al * bl) and low(ah * bl) 
    adc ecx, edx             	; add carry from the previous addition and high(al * bh) to high(ah * bl) and earlier carry, save in ecx
   pushfd
;   there should generate a carry

    mov eax, [ebp + ah_off]
    mov edx, [ebp + bh_off]
    mul edx                 	; ah * bh, eax = low(ah * bh), edx = high(ah * bh)

   popfd
   adc ecx, eax
   
   ; add eax, ecx             	; add high(al * bh), high(ah * bl) and carry to low(ah * bh)
    adc edx, 0               	; add carry from the previous addition to high(ah * bh)



   ; mov ebx, [ebp + res_off]
    mov [res0], edi		        ; put low 32 bit of result in array
    mov [res1], esi		    ; put next 32 bit of result in array
    mov [res2], ecx		    ; put next 32 bit of result in array
    mov [res3], edx         ; put high 32 bit of result in array

    pop esi
    pop edi
    pop edx
    pop ecx
    pop ebx
    pop eax
		
    pop ebp			            ; restore ebp reg
    ret				            ; return