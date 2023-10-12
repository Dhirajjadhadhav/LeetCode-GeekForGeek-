/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int get(MountainArray *, int index);
 * int length(MountainArray *);
 */
int find_pivot(MountainArray* p_marr)
{
    int start = 0;
    int end = length(p_marr)-1;
    int mid;

    while(start<end)
    {
        mid = start+(end-start)/2;
        //printf("mid = %d\n",get(p_marr, mid));
        if(get(p_marr, mid)<get(p_marr, mid+1))
            start = mid+1;
        else
            end = mid;
    }
    return start;

}
int binary_seach(MountainArray* p_marr, int start, int end, int target, bool basc)
{
    int mid;
    int val;
    int ans = -1;

    if(basc)
    {
       while(start<=end)
       {
            mid = start +(end-start)/2;
            //printf("start = %d, end= %d, mid = %d\n",start ,end,  mid);
            val = get(p_marr, mid);
            if(val == target)
                return mid;
            else if(val<target)
                start = mid+1;
            else 
                end = mid-1;
       }
      
    }
    else
    {
       while(start<=end)
        {
            mid = start + (end-start)/2;
            val = get(p_marr, mid);
            if(val == target)
                return mid;
            else if(val<target)
                end = mid-1;
            else
                start = mid+1;
        }
    }
    return ans;
}
int findInMountainArray(int target, MountainArray* mountainArr) {
	
    int pivot = find_pivot(mountainArr);
   
    int ans;
    ans = binary_seach(mountainArr, 0, pivot-1, target, 1);
    if(ans!=-1)
        return ans;
    ans = binary_seach(mountainArr, pivot, length(mountainArr)-1, target, 0);
    return ans;
}   