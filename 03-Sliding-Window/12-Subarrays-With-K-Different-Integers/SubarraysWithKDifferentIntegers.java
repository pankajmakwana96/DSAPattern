/**
 * Subarrays with K Different Integers
 * Time: O(n), Space: O(k)
 */

import java.util.HashMap;
import java.util.Map;

class SubarraysWithKDifferentIntegers {
    public int subarraysWithKDistinct(int[] nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    private int atMostK(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        int left = 0, count = 0;

        for (int right = 0; right < nums.length; right++) {
            freq.put(nums[right], freq.getOrDefault(nums[right], 0) + 1);

            while (freq.size() > k) {
                freq.put(nums[left], freq.get(nums[left]) - 1);
                if (freq.get(nums[left]) == 0) {
                    freq.remove(nums[left]);
                }
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    public static void main(String[] args) {
        SubarraysWithKDifferentIntegers solution = new SubarraysWithKDifferentIntegers();
        System.out.println(solution.subarraysWithKDistinct(new int[]{1, 2, 1, 2, 3}, 2));  // 7
    }
}
