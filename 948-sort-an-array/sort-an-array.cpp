class Solution {
public:

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> merged;
    int left_index = 0;
    int right_index = 0;

    while (left_index < left.size() && right_index < right.size()) {
        if (left[left_index] <= right[right_index]) {
            merged.push_back(left[left_index]);
            left_index++;
        } else {
            merged.push_back(right[right_index]);
            right_index++;
        }
    }

    merged.insert(merged.end(), left.begin() + left_index, left.end());
    merged.insert(merged.end(), right.begin() + right_index, right.end());
    return merged;
}

std::vector<int> merge_sort(const std::vector<int>& nums) {
    if (nums.size() <= 1) {
        return nums;
    }

    int mid = nums.size() / 2;
    std::vector<int> left(nums.begin(), nums.begin() + mid);
    std::vector<int> right(nums.begin() + mid, nums.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}

std::vector<int> sortArray(const std::vector<int>& nums) {
    return merge_sort(nums);
}
};