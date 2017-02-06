

int writers; // Number writer threads that want to enter the critical section (some or all of these may be blocked)
int writing; // Number of threads that are actually writing inside the C.S. (can only be zero or one)
int reading; // Number of threads that are actually reading inside the C.S.
// if writing !=0 then reading must be zero (and vice versa)


reader() {
    lock(&m);
    // reader arrive *after* the writer arrived will have to wait here
    while (writers)
        con_wait(&turn, &m);
    // No need to wait while(writing here) because we can only exit the above loop
    // when writing is zero    
    reading++;
    unlock(&m);
    
    // perform reading here
    lock(&m)
    reading--;
    cond_broadcast(&turn)
    unlock(&m)
}

writer() {
    lock(&m)
    writers++;                  // register the writer
    while (reading || writing) 
        con_wait(&turn, &m)
    writing++;
    unlock(&m)
    
    // perform writing here
    lock(&m)
    writing--;
    writers--;
    cond_broadcast(&turn)
    unlock(&m)
}

/////////////////////////////////////////////////////////
/* 
solution 3 
drawbacks: 
1. con_signal() can only notify one writer / reader
2. writer starvation. To solve it, use bounded-wait for the writer.
Future coming readers is placed in a "holding pen" and wait for the writer to
finish. The holding pen can be implemented using a variable and a condition
variable

when a writer arrives, and before waiting for current readers to finish, register
our inten to write (by incrementing a counter "writer")

And incoming readers will not be allowed to continue while writer is nonzero
Notice 'writer' indicates a wirter has arrived, while 'reading' and 'writing'
counters indicate there is an active reader or writer
*/
read() {
  lock(&m)
  while (writing) {
    pthread_cond_wait(&cv,&m)
  }
  reading++
  
  // unlock and then multiple readers can read
  unlock(&m)
  // do read stuff
  
  lock(&m)
  reading--
  pthread_cond_signal(&cv)
  unlock(&m)
}


write() {
  lock(&m)
  while (reading || writing)
    pthread_cond_wait(&cv,&m)

  writing++
  // do write stuff
  writers--
  pthread_cond_signal(&cv)
  unlock(&m)
}



/*
pthread_cond_wait performs three actions:
1. atomically unlocks the mutex
2. sleeps until it is woken up by pthread_cond_signal or pthread_cond_broadcast
3. the awoken thread must re-acquire the mutex lock before returning

*/

/* solution 2 */
read() {
  while(writing) {/*spin*/}
  reading = 1
  // do read stuff
  reading = 0
}

write() {
  while(reading || writing) {/*spin*/}
  writing = 1
  // do write stuff
  writing = 0
}



/* solution 1 */
read() {
  lock(&m)
  // do read stuff
  unlock(&m)
}

write() {
  lock(&m)
  // do write stuff
  unlock(&m)
}