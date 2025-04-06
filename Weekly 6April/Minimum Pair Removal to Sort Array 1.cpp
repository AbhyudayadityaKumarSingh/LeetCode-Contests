class Solution {
    public:
        bool isNonDecreasing(vector<int> &nums) {
            for(int i=1;i<nums.size();i++) {
                if(nums[i]<nums[i-1])  return false ;
            }
            return true ;
        }
        int minimumPairRemoval(vector<int>& nums) {
               int ans = 0 ;
            while(!isNonDecreasing(nums) and nums.size()>1) {
                int currsum = 0 , minsum = 1e9 ;
                int idx =  -1 ;
                for(int i=1;i<nums.size();i++) {
                    currsum = nums[i-1] + nums[i] ;
                    if(currsum < minsum) {
                        minsum =currsum ;
                        idx = i ;
                    }
                }
                int desired = nums[idx-1] + nums[idx] ;
                nums.erase(nums.begin()+ idx -1, nums.begin()+idx+1) ;
                nums.insert(nums.begin()+ idx -1 , desired) ;
                ans ++ ;
            }
            return ans ;
           
        }
    };

    /*
    QUESTION :
    Given an array nums, you can perform the following operation any number of times:

Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

Example 1:

Input: nums = [5,2,3,1]

Output: 2

Explanation:

The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
The array nums became non-decreasing in two operations.

Example 2:

Input: nums = [1,2,2]

Output: 0

Explanation:

The array nums is already sorted.

 

Constraints:

1 <= nums.length <= 50
-1000 <= nums[i] <= 1000
    */