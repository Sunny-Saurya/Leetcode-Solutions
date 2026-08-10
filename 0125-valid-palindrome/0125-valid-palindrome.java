class Solution {
    public boolean isPalindrome(String s) {

        String str = "";

        for(int i = 0; i < s.length(); i++) {

            char ch = Character.toLowerCase(s.charAt(i));

            if(Character.isLetterOrDigit(ch)) {
                str += ch;
            }
        }

        return check(str, 0, str.length() - 1);
    }

    boolean check(String str, int l, int r) {

        while(l <= r) {

            if(str.charAt(l) != str.charAt(r)) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
}