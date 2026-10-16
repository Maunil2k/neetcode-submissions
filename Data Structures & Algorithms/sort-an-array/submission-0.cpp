class Solution {
private:
    vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int n1 = arr1.size(), n2 = arr2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (arr1[i] > arr2[j]) {
                ans.push_back(arr2[j]);
                j++;
            }

            else {
                ans.push_back(arr1[i]);
                i++;
            }
        }

        if (i!=n1) {
            while (i != n1) {
                ans.push_back(arr1[i]);
                i++;
            }
        }

        if (j!=n2) {
            while (j != n2) {
                ans.push_back(arr2[j]);
                j++;
            }
        }

        return ans;
    }

    vector<int> split(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;
        int m = n/2;
        vector<int> left(nums.begin(), nums.begin()+m);
        vector<int> right(nums.begin()+m, nums.end());

        left = split(left);
        right = split(right);

        return merge(left, right);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        return split(nums);
    }
};