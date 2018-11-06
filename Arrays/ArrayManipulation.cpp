// Question link : https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   long int n , m;
    cin>>n>>m;
    vector<long int> arr(n,0);
    long int max = INT_MIN;
    for (long int i=0;i<m;i++){
        long int a,b,k;
        cin>>a>>b>>k;
        arr[a-1] +=k;
        arr[b]-=k;
    }
    long int x=0;
    for (int i=0 ;i<n ; i++){
        x+= arr[i];
        if(x>max)
                 max = x;
    }
   
    cout<<max;
    return 0;
}

