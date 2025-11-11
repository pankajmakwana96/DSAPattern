/**
 * Fruit Into Baskets
 * LeetCode: https://leetcode.com/problems/fruit-into-baskets/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) - at most 3 keys in map
 */

import java.util.HashMap;
import java.util.Map;

class FruitIntoBaskets {

    // Sliding Window: At Most 2 Distinct Elements
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> map = new HashMap<>();
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.length; right++) {
            // Add fruit to window
            map.put(fruits[right], map.getOrDefault(fruits[right], 0) + 1);

            // Shrink while more than 2 types
            while (map.size() > 2) {
                map.put(fruits[left], map.get(fruits[left]) - 1);
                if (map.get(fruits[left]) == 0) {
                    map.remove(fruits[left]);
                }
                left++;
            }

            // Update maximum
            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    // Test cases
    public static void main(String[] args) {
        FruitIntoBaskets solution = new FruitIntoBaskets();

        // Test case 1
        System.out.println("Test 1: " + solution.totalFruit(new int[]{1, 2, 1}));
        // Expected: 3

        // Test case 2
        System.out.println("Test 2: " + solution.totalFruit(new int[]{0, 1, 2, 2}));
        // Expected: 3

        // Test case 3
        System.out.println("Test 3: " + solution.totalFruit(new int[]{1, 2, 3, 2, 2}));
        // Expected: 4

        // Test case 4: All same
        System.out.println("Test 4: " + solution.totalFruit(new int[]{1, 1, 1, 1}));
        // Expected: 4

        // Test case 5: Two types
        System.out.println("Test 5: " + solution.totalFruit(new int[]{1, 2, 1, 2, 1, 2}));
        // Expected: 6
    }
}
