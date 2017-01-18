

void swap(int arr[], int idx1, int idx2)
{
    int tmp;
    tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

void shuffleMusicList(int arr[], int n)
{
    srand(time(NULL));
    
    int i, swap_idx;
    for (i = n - 1; i > 0; i--) {
        swap_idx = rand() / (i + 1);
        swap(arr, i, swap_idx);
    }
}

