class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> mpp = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            mpp.put(nums[i], mpp.getOrDefault(nums[i], 0 )+1);
        }

        for(Map.Entry<Integer,Integer> yo: mpp.entrySet()){
            if(yo.getValue() == 1){
                return yo.getKey();
            }
        }
        return -1;
    }
}