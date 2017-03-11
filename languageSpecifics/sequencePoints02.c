/**
 *
 * sequence point: certain points in program execution sequence
 * A sequence point means at this point, all side effects of previous
 * evaluations will have been performed, and no side effects of 
 * subsequent evaluations haven been performed yet. 
 *
 **/

#include <stdio.h>
int f1() { printf ("Geeks"); return 1;}
int f2() { printf ("forGeeks"); return 1;}
 
// PROGRAM 4
int main()
{ 
   // Since && defines a sequence point after first operand, it is 
   // guaranteed that f1() is completed first.
   int p = f1() && f2();  
   printf("\n\n");

   // Since comma operator defines a sequence point after first operand, it is
   // guaranteed that f1() is completed first.
   int q = (f1(), f2());
   printf("\n\n");

   // Since ? operator defines a sequence point after first operand, it is 
   // guaranteed that f1() is completed first.
   int r = f1()? f2(): 3;
   printf("\n\n");

   return 0; 
}