#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <cassert>

// Original Solution - Two Pointer Approach (OPTIMAL)
class OptimalSolution {
public:
    int maxArea(std::vector<int>& height) {
        long int maxSpace = 0;

        int start = 0, end = height.size() - 1;
        while(start < end){
            long int space = (end - start) * (long int)(std::min(height[start], height[end]));
            if(space > maxSpace) maxSpace = space;
            if(height[start] < height[end]) ++start;
            else --end;
        }

        return maxSpace;
    }
};

// Brute Force Solution for comparison (O(n^2))
class BruteForceSolution {
public:
    int maxArea(std::vector<int>& height) {
        int maxSpace = 0;
        int n = height.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int area = (j - i) * std::min(height[i], height[j]);
                maxSpace = std::max(maxSpace, area);
            }
        }
        
        return maxSpace;
    }
};

// Test function to verify correctness and compare performance
void runTests() {
    OptimalSolution optimal;
    BruteForceSolution bruteForce;
    
    // Test case 1: Basic example
    std::vector<int> test1 = {1,8,6,2,5,4,8,3,7};
    int expected1 = 49; // max area between index 1 (height=8) and index 8 (height=7), width=7
    
    assert(optimal.maxArea(test1) == expected1);
    assert(bruteForce.maxArea(test1) == expected1);
    std::cout << "✓ Test 1 passed: Basic example\n";
    
    // Test case 2: Two elements
    std::vector<int> test2 = {1,1};
    int expected2 = 1;
    
    assert(optimal.maxArea(test2) == expected2);
    assert(bruteForce.maxArea(test2) == expected2);
    std::cout << "✓ Test 2 passed: Two elements\n";
    
    // Test case 3: Decreasing heights
    std::vector<int> test3 = {5,4,3,2,1};
    int expected3 = 6; // between index 0 (height=5) and index 3 (height=2), width=3, area=6
    
    assert(optimal.maxArea(test3) == expected3);
    assert(bruteForce.maxArea(test3) == expected3);
    std::cout << "✓ Test 3 passed: Decreasing heights\n";
    
    // Test case 4: Large test for performance comparison
    std::vector<int> largeTest;
    for(int i = 1; i <= 10000; i++) {
        largeTest.push_back(i % 100 + 1);
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    int optimalResult = optimal.maxArea(largeTest);
    auto end = std::chrono::high_resolution_clock::now();
    auto optimalTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    start = std::chrono::high_resolution_clock::now();
    int bruteForceResult = bruteForce.maxArea(largeTest);
    end = std::chrono::high_resolution_clock::now();
    auto bruteForceTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    assert(optimalResult == bruteForceResult);
    std::cout << "✓ Test 4 passed: Large test (10000 elements)\n";
    std::cout << "  Optimal solution time: " << optimalTime.count() << " microseconds\n";
    std::cout << "  Brute force time: " << bruteForceTime.count() << " microseconds\n";
    std::cout << "  Speed improvement: " << (double)bruteForceTime.count() / optimalTime.count() << "x\n";
}

void analyzeAlgorithm() {
    std::cout << "\n=== ALGORITHM ANALYSIS ===\n";
    std::cout << "The current solution uses the Two Pointer technique:\n\n";
    
    std::cout << "✓ Time Complexity: O(n) - Single pass through the array\n";
    std::cout << "✓ Space Complexity: O(1) - Constant extra space\n";
    std::cout << "✓ Algorithm Correctness: Proven optimal for this problem\n\n";
    
    std::cout << "Key Insight:\n";
    std::cout << "- Start with widest possible container (leftmost and rightmost lines)\n";
    std::cout << "- Move the pointer with smaller height inward\n";
    std::cout << "- Why? Moving the taller line inward can never improve the area\n";
    std::cout << "  because width decreases and height is limited by the shorter line\n\n";
    
    std::cout << "Alternative approaches and their complexities:\n";
    std::cout << "1. Brute Force: O(n²) time, O(1) space - Check all pairs\n";
    std::cout << "2. Two Pointer (current): O(n) time, O(1) space - OPTIMAL\n\n";
    
    std::cout << "CONCLUSION: Yes, this solution IS the best possible solution!\n";
    std::cout << "- It achieves optimal time complexity O(n)\n";
    std::cout << "- It uses minimal space O(1)\n";
    std::cout << "- The algorithm is mathematically proven to be correct\n";
}

int main() {
    std::cout << "=== CONTAINER WITH MOST WATER - SOLUTION ANALYSIS ===\n\n";
    
    runTests();
    analyzeAlgorithm();
    
    return 0;
}