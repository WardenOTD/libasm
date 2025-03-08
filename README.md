# Recreating Functions in Assembly
*This readme is more or less for my own understanding please dont take it too seriously*
### nasm with intel syntax for x86-64 is used

Assembly is compiled from top to bottom just like C
and uses registers or the stack to store data, and instructions to
manipulate them.

---

### Registers


| x64      | x32        | x16        | x8         | common use                                 |
| -------- | ---------- | ---------- | ---------- | ------------------------------------------ |
| rax      | eax        | ax         | al         | return value / syscall number / arithmetic |
| rbx      | ebx        | bx         | bl         | indexed addressing                         |
| rcx      | ecx        | cx         | cl         | loop count                                 |
| rdx      | edx        | dx         | dl         | used with AX for larger  arithmetic values |
| rsi      | esi        | si         | sil        | source for data copies                     |
| rdi      | edi        | di         | dil        | destination for data copies                |
| rsp      | esp        | sp         | spl        | stack pointer                              |
| rbp      | ebp        | bp         | bpl        | base pointer                               |
| r8 - r15 | r8d - r15d | r8w - r15w | r8b - r15b | added registers                            |

---

### Arguments
Parameters are passed into registers in this order:
* `rdi, rsi, rdx, rcx, r8d, r9d`
* remaining parameters are pushed into the stack in reverse order
so when popped it will be in order

#### For example:
`int strlen(char *str)`
`rdi` would then equal to `char *str`

---

## `section .note.GNU-stack`
On newer version of **GNU Binutils (2.39+)**, a warning is raised when linking files using `ld / gcc`.

`/usr/bin/ld: warning: FILENAME.o: missing .note.GNU-stack section implies executable stack`

`section .note.GNU-stack` fixes this.

*check ld version:*
`ld -v`

*extra info of this warning:*
[git.kernel.org](https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=ffcf9c5700e49c0aee42dcba9a12ba21338e8136)

## `call [extern function] wrt ..plt`
This is needed to call external functions within you assembly code.\
Without `wrt ..plt` you will get an error similar to\
`relocatation against undefined symbol [function] ...`

* FYI, `wrt` stands for `with respect to` and `..plt` is `procedure linkage table`.
