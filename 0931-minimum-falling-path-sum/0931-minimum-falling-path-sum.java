class Solution {
    public int minFallingPathSum(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return 0;
        }

        int n = matrix.length;

        // Iterate through the matrix starting from the second row
        for (int row = 1; row < n; row++) {
            for (int col = 0; col < n; col++) {
                // Update the current element with the minimum falling path sum
                matrix[row][col] += Math.min(
                    matrix[row - 1][Math.max(0, col - 1)],
                    Math.min(matrix[row - 1][col], matrix[row - 1][Math.min(n - 1, col + 1)])
                );
            }
        }

        // The minimum falling path sum is the minimum value in the last row
        int minSum = Integer.MAX_VALUE;
        for (int col = 0; col < n; col++) {
            minSum = Math.min(minSum, matrix[n - 1][col]);
        }

        return minSum;
    }
}