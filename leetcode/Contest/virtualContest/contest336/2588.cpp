#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

class Solution {
public:
    bool isvowel(char c){
        return c=='a' || c=='e'|| c=='i' || c=='o' || c=='u';
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int n=words.size();
        int c=0;
        for(int i=0;i<n;i++){
            string t=words[i];
            int len=t.length();
            if(len<=2){
                if(isvowel(t[0]) || isvowel(t[len])){
                    c++;
                }
            }
        }
        return c;
    }
};