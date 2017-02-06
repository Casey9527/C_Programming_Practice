Node* cmpxchg(Node* *top_ref, Node* old_top, Node* new_top)
{
    Node* ret;
    
    __asm__ __volatile__ (
        "lock \n"
        "mov %0, %1\n"
        "cmpxchgl %2, %1\n"
        : "=q"(ret), "=m"(*top_ref)
        : "m"(*top_ref), "r"(new_top), "a"(old_top)
        : "memory");

    return ret;
}

