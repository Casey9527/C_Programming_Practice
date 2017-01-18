
typedef struct trip {
    char src[3];
    char dst[3];
} single_trip;


// convert the 26 uppercase alphabetic letters into distinct prime numbers 
int char2prime[26] =
{ // A   B   C   D   E   F   G   H 
     2,  3,  5,  7,  11, 13, 17, 19, 
  // I   J   K   L   ,   N   O   P
     23, 29, 31, 37, 41, 43, 47, 53
  // 
  47, 53, 59  
}

void getSortedSeq(single_trip trips[], int trip_num, int *seq)
{
    
    
}


int main()
{
    single_trip trips[6] = {
        {"SEA", "KOA"},
        {"ITO", "JFK"},
        {"PHX", "SEA"},
        {"LHR", "CDG"},
        {"JFK", "LHR"},
        {"KOA", "ITO"}
    };
    
    
    
    int sorted_seq[6] = {0};
    
    
    getSortedSeq(trips, sizeof(trips) / sizeof(single_trip), sorted_seq);
    
    int i;
    for (i = 0; i < 6; i ++)
        printf("%s -> %s \n", trips[sorted_seq[i]]->src, 
                              trips[sorted_seq[i]]->dst);
    
    return 0;
}