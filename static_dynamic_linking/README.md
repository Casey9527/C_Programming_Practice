# Create dynamic-linking library
http://www.geeksforgeeks.org/working-with-shared-libraries-set-2/

### dynamicLib.c
``` shell
gcc -shared -fPIC -o dynamicLib.so dynamicLib.c
```

### dynamicApp
``` shell
gcc dynamicApp.c -L /path/to/dynamicLib.so -llibrary -o dynamicApp
```

### run
``` shell
./dynamicApp
```
