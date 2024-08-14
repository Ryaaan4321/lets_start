#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;
#define ll long long
class Solution {
public:
    static const int MX=1005;
    bool prime[MX];
    void sieve(){
        fill(prime,prime+MX,true);
        prime[0]=prime[1]=0;
        for(ll i=2;i*i<MX;i++){
            if(prime[i]){
                for(ll j=i*i;j<MX;j+=i){
                   prime[j]=0;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        sieve();
        int n=nums.size();
        vector<int>primes;
        for(int i=2;i<=1000;i++){
            if(prime[i])primes.push_back(i);
        }
        vector<int>new_num(n,-1);
        new_num[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]<new_num[i+1]){
              new_num[i]=nums[i];
              continue;
            }
            for(auto p:primes){
                if(p>=nums[i]){
                    new_num[i]=nums[i];
                    break;
                }
                if(nums[i]-p<new_num[i+1]){
                    new_num[i]=nums[i]-p;
                    break;
                }
            }
        }
        bool f=1;
        for(int i=0;i<n;i++){
            if(new_num[i]>new_num[i+1]){
                f=0;
            }
        }
        return f;
    }
    
};

