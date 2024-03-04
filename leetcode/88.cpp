// #include <bits/stdc++.h>
// #include <algorithm>
// #include <iostream>
// class Solution
// {
// public:
//     void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
//     {
//         int left = m - 1;         // to move in the array;
//         int right = n - 1;        // to move in the second arrray
//         int k = nums1.size() - 1; // to take a look that in which index we are placing our value

//         while (right >= 0)
//         { // as the question says ki we have to do inplace in this array so untill the ist array becomes 0;
//             if (left >= 0 && nums1[left] > nums2[right])
//             {                           // and u know what that it is;
//                 nums1[k] = nums1[left]; // nd if it is right then nums[left] is our candidate
//                 k--;
//                 left--;
//             }
//             else
//             {
//                 nums1[k] = nums2[right]; // else this will be our candidate;
//                 k--;
//                 right--;
//             }
//         }
//     }
// };