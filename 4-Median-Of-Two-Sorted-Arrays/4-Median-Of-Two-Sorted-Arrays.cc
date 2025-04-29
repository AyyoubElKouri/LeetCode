#include <vector>
#include <algorithm>
#include <iostream>

/**************************************************************************************************************************
 * Execution Time : 0 ms (leetcode test)
 **************************************************************************************************************************/

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> mergeVector;
        std::merge  (
                        nums1.begin(),
                        nums1.end(),
                        nums2.begin(),
                        nums2.end(),
                        std::back_insert_iterator(mergeVector)
                    );

        int size = mergeVector.size();
        if((size % 2) == 0) return (mergeVector.at((size / 2) - 1) + mergeVector.at((size / 2)))/2.0;
        else return mergeVector.at((size / 2));
    }
};

int main(){
    Solution s;
    std::vector<int> v1 {1, 3};
    std::vector<int> v2 {2};
    double v = s.findMedianSortedArrays(v1, v2);
    std::cout << "Your number is : " << v << std::endl;

    return 0;
}