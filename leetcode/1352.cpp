#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class ProductOfNumbers {
    public:
        priority_queue<int,greater<int>>pq;
        ProductOfNumbers() {
            
        }
        void add(int num) {
            pq.push(num);
        }
        int getProduct(int k) {
            int sm=0;
            while (!pq.empty() && k--)
            {
              sm+=pq.top();
              pq.pop();
            }
            return sm;
        }
    };

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */