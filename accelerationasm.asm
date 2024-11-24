section .data
kmh_to_ms: dd 0.27777778 ; Conversion factor from km/h to m/s

section .text
bits 64
default rel
global accelerationasm
accelerationasm:
  
    push rbp
    mov rbp, rsp

    xor r9, r9        ; r9- the index of current car in input array
L1:
    ; Compare current index with rows (@ecx)
    cmp r9d, ecx      
    jge exit          ; Exit if all rows processed

    
    ; point to the start of current car
    imul rax, r9, 12; rax = r9 * 12 (offset of 12 for every car)
 

    movss xmm0, dword [rdx + rax]        ; Load Vi
    movss xmm1, dword [rdx + rax + 4]    ; Load Vf
    movss xmm2, dword [rdx + rax + 8]    ; Load T

    ; Convert velocities to m/s
    movss xmm3, dword [rel kmh_to_ms]    ; Load conversion factor
    mulss xmm0, xmm3                     ; Vi * 0.27777778
    mulss xmm1, xmm3                     ; Vf * 0.27777778

    ; Calculate acceleration
    subss xmm1, xmm0                     ; Vf - Vi
    divss xmm1, xmm2                     ; (Vf - Vi) / T

    ; Convert acceleration to integer
    cvtss2si eax, xmm1                  ; Convert float to int

    ; Store result in output array
    mov [r8 + r9 * 4], eax               ; store in 1d array [output base pointer + index*4] 

    ; Increment index and repeat
    inc r9d                              
    jmp L1

exit:
    ; Restore callee-saved registers
    mov rsp, rbp
    pop rbp
    ret





