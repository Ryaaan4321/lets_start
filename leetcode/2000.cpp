#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx=-1;
        for(int i=0;i<word.length();i++){
            if(word[i]==ch){
                idx=i;
            }
            

        }
        reverse<int>(0,idx);
        return word;
    }
};