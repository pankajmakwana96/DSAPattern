/**
 * Count Subarrays With Score Less Than K
 * Time: O(n), Space: O(1)
 */

class CountSubarraysScoreLessThanK {
    public long countSubarrays(int[] nums, long k) {
        long count = 0, sum = 0;
        int left = 0;

        for (int right = 0; right < nums.length; right++) {
            sum += nums[right];

            while (sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    public static void main(String[] args) {
        CountSubarraysScoreLessThanK solution = new CountSubarraysScoreLessThanK();
        System.out.println(solution.countSubarrays(new int[]{2, 1, 4, 3, 5}, 10));  // 6
        System.out.println(solution.countSubarrays(new int[]{1, 1, 1}, 5));  // 5
    }
}
