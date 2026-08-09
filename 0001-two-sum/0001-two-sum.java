class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer>mapp = new HashMap<>();
        int[] ans = new int[2];

        for(int i = 0; i < nums.length; i++){
            mapp.put(nums[i], i);
        }

        for(int i = 0; i < nums.length; i++){
            int diff = target - nums[i];
            if(mapp.containsKey(diff) && mapp.get(diff) != i){
                ans[0] = i;
                ans[1] = mapp.get(diff);
                return ans;
            }
        }
        return ans;
    }
}