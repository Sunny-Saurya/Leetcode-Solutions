class Solution {
    public boolean isAnagram(String s, String t) {
        char [] chars1 = s.toCharArray();
        char [] chars2 = t.toCharArray();

        Arrays.sort(chars1);
        Arrays.sort(chars2);

        if(chars1.length != chars2.length) {
            return false;
        }
        
        for(int i = 0; i < chars1.length; i++){
            if(chars1[i] != chars2[i]){
                return false;
            }
        }
        return true;
    }
}