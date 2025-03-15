public long maxScore(int[] nums1, int[] nums2, int k) {
    return backtracking(nums1, nums2, k, 0, 0, 0L, 0, Integer.MAX_VALUE);
}

private long backtracking(int[] nums1, int[] nums2, int k, int cnt, int sum, long maxScore, int start, int min) {
    
    if (k == cnt) return sum * min; 
    
    for (int i = start; i < nums1.length; i++) {
        long score = backtracking(nums1, nums2, k, cnt + 1, sum + nums1[i] , maxScore, i + 1, min > nums2[i] ? nums2[i] : min);
        maxScore = Math.max(maxScore, score);
    }
    return maxScore;
} 