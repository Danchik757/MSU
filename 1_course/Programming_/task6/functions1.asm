;   уравнения кривых - 10

section .data
    const1 dd 1.0
    const2 dd 2.0
    const3 dd 3.0
    const4 dd 4.0
    
section .text

;   f1 = 1 + 4/(x^2 + 1)
global _f1
_f1:
    push ebp
    mov ebp, esp
    sub esp, 4
    
    fld dword[const4]
    fld qword[esp+8]
    fld qword[esp+8]
    fmulp
    fld1
    faddp
    fdivp
    fld1
    faddp
    
    add esp, 4
    leave
    ret
    
    
    
;   f2 = x^3
global _f2
_f2:
    push ebp
    mov ebp, esp 
    sub esp, 4
    
    fld dword[ebp+8]; [x]
    fst dword[esp]; copy to st
    
    fmul dword[esp]; mul
    fmul dword[esp]; mul
    
    add esp, 4
    leave
    ret
    
;   f3 = 2^-x
global _f3
_f3:
    push ebp
    mov ebp, esp
    sub esp, 4
    
    fld1; load 1 for numerator
    fld qword[ebp+8] ;
    f2xm1 ; st0 = 2^x - 1
    fld1
    faddp ; st0 = 2^x
    
    fdiv ;st(1)/st(0)
    
    add esp, 4
    leave
    ret
    
    