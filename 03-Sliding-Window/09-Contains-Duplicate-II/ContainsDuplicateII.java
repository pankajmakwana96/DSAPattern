/**
 * Contains Duplicate II
 * Time: O(n), Space: O(min(n,k))
 */

import java.util.HashSet;
import java.util.Set;

class ContainsDuplicateII {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> window = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {
            if (window.contains(nums[i])) {
                return true;
            }
            window.add(nums[i]);
            if (window.size() > k) {
                window.remove(nums[i - k]);
            }
        }

        return false;
    }

    public static void main(String[] args) {
        ContainsDuplicateII solution = new ContainsDuplicateII();
        System.out.println(solution.containsNearbyDuplicate(new int[]{1, 2, 3, 1}, 3));  // true
        System.out.println(solution.containsNearbyDuplicate(new int[]{1, 0, 1, 1}, 1));  // true
        System.out.println(solution.containsNearbyDuplicate(new int[]{1, 2, 3, 1, 2, 3}, 2));  // false
    }
}
