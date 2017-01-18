

// a linux system call with three arguments
#define _syscall3(type, name, type1, arg1, type2, arg2, type3, arg3) \
type name(type1 arg1, type2 arg2, type3, arg3) \
{ \
long __res;\
__asm__ __volatile ( "int $0x80" \
                     : "=a" (__res) \
                     : "0" (_NR_##name), "b" ((long)(arg1)), \
                       "c" ((long)(arg2)),"d" ((long)(arg3)) \
                   ); \
__syscall_return(type, __res); \
}

// SYS_exit
{
    asm("movl $1, %%eax;        /* SYS_exit is 1 */
         xorl %%ebx, %ebx;      /* Argument is in ebx, it is 0 */
         int $0x80"             /* Enter kernel mode  */
       );
}