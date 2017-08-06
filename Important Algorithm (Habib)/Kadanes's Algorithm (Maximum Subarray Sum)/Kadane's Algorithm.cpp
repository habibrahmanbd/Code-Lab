def max_subarray(A)
{
    max_ending_here = max_so_far = A[0]
    for i:=1 to n-1
        max_ending_here = max(A[i], max_ending_here + A[i])
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far
}
