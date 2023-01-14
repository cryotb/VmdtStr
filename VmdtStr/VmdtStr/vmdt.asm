.CODE

VmdtRunCheck PROC
    push rsi
    push rdi

    mov rsi, 0FFFFFFFFFFFFFFFFh
    str rsi

    xor rdi, rdi
    mov rdi, 0FFFFh
    not rdi

    and rsi, rdi
    cmp rsi, 0
    jne finish
    mov ax, 1

finish:
    pop rdi
    pop rsi

    ret
VmdtRunCheck ENDP

END