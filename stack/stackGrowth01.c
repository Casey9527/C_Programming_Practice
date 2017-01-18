
// 10:41 - 10:5

stackGrowthDir(NULL);

void stackGrowthDir(void *arg)
{
    int var1;
    
    if (arg == NULL) {
        stackGrowthDir(&var);
    } else {
        if (arg > &var1) {
            printf("growing down\n");
        } else {
            printf("growing up\n");
        }
    }
}

