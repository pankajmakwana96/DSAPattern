/**
 * Diet Plan Performance
 * Time: O(n), Space: O(1)
 */

class DietPlanPerformance {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int points = 0, sum = 0;

        for (int i = 0; i < k; i++) {
            sum += calories[i];
        }

        if (sum < lower) points--;
        else if (sum > upper) points++;

        for (int i = k; i < calories.length; i++) {
            sum = sum - calories[i - k] + calories[i];
            if (sum < lower) points--;
            else if (sum > upper) points++;
        }

        return points;
    }

    public static void main(String[] args) {
        DietPlanPerformance solution = new DietPlanPerformance();
        System.out.println(solution.dietPlanPerformance(new int[]{1, 2, 3, 4, 5}, 1, 3, 3));  // 0
        System.out.println(solution.dietPlanPerformance(new int[]{3, 2}, 2, 0, 1));  // 1
    }
}
