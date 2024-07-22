class Solution {
public:
    int minChanges(int n, int k) {
    int count_n_ones = 0, count_k_ones = 0;

    // Count the number of 1s in the binary representation of n
    int temp_n = n;
    while (temp_n) {
        count_n_ones += temp_n & 1;
        temp_n >>= 1;
    }

    // Count the number of 1s in the binary representation of k
    int temp_k = k;
    while (temp_k) {
        count_k_ones += temp_k & 1;
        temp_k >>= 1;
    }

    // If k has more 1s than n, it's impossible to convert n to k by changing 1s to 0s
    if (count_k_ones > count_n_ones) {
        return -1;
    }

    // XOR n and k to find the bits that are different
    int diff = n ^ k;
    int changes_needed = 0;

    // Count the number of 1s in the differing bits (which indicate where n has 1s that need to be changed to 0s)
    while (diff) {
        changes_needed += diff & 1;
        diff >>= 1;
    }

    return changes_needed;
}
};