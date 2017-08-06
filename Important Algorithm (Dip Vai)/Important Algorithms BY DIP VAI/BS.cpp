#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

bool chc(int val) //according to problem
{

}

int bs(int st,int end) //for increasing
{
    if(st>end) return -1;
    int mid=(st+end)/2;
    if(chc(mid))
    {
        if(!mid) return mid; //0 handle for index
        if(chc(mid-1)) return bs(st,mid-1);
        return mid;
    }
    return bs(mid+1,end);
}

int bs(int st,int end) //for decreasing
{
    if(st>end) return -1;
    int mid=(st+end)/2;
    if(chc(mid))
    {
        if(chc(mid+1)) return bs(mid+1,end);
        return mid;
    }
    return bs(st,mid-1);
}

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}
