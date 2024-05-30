int countTriplets(int* arr, int arrSize)
{
		int j,k;
		int out = 0;
    int i = 0;

    while(i < arrSize - 1)
    {
        int a = 0;
        j = i + 1;
        while(j < arrSize)
        {
            a ^= arr[j - 1];
            int b = 0;
            k = j;
            while(k < arrSize)
            {
                b ^= arr[k];
                if(a == b)
                    out++;
                k++;
            }
            j++;
        }
        i++;
    }
    return out;
}