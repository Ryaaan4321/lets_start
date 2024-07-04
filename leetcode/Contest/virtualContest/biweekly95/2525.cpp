#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    const int bulk=1e4;
    bool bulky(int length,int width,int height,int mass){
        return (length>=bulk || width >=bulk || height>=bulk || mass>=bulk);
    }
    string categorizeBox(int length, int width, int height, int mass) {
        string s="";
        if(length>=bulk || width >=bulk || height>=bulk || mass>=bulk){
            s= "Bulky";
        }else if(mass>=100){
            s= "Heavy";
        }else if(bulky(length,width,height,mass) && mass>=100){
            s= "Both";
        }else if(bulky(length,width,height,mass) && mass<100){
            s= "Bulky";
        }else if(!bulky(length,width,height,mass) && mass<100){
            s= "Neither";
        }else if (!bulky(length,width,height,mass && mass>=100)){
            s= "Heavy";
        }
        return s;
    }
};