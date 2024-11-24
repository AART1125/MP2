section .data
    toms dd 0.27777778
section .text
global asmaccelleration
asmaccelleration:
    ;write your code here
    movss xmm4, [toms]
    
    subss xmm1, xmm0
    mulss xmm1, xmm4
    divss xmm1, xmm2
    cvtss2si rax, xmm1
    
    ret