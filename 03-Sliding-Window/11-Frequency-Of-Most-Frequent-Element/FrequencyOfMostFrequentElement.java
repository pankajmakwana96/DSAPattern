/**
 * Frequency of the Most Frequent Element
 * Time: O(n log n), Space: O(1)
 */

import java.util.Arrays;

class FrequencyOfMostFrequentElement {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int left = 0, maxFreq = 1;
        long sum = 0;

        for (int right = 0; right < nums.length; right++) {
            sum += nums[right];
            long target = (long) nums[right] * (right - left + 1);

            while (target - sum > k) {
                sum -= nums[left];
                left++;
            }

            maxFreq = Math.max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }

    public static void main(String[] args) {
        FrequencyOfMostFrequentElement solution = new FrequencyOfMostFrequentElement();
        System.out.println(solution.maxFrequency(new int[]{1, 2, 4}, 5));  // 3
        System.out.println(solution.maxFrequency(new int[]{1, 4, 8, 13}, 5));  // 2
    }
}
