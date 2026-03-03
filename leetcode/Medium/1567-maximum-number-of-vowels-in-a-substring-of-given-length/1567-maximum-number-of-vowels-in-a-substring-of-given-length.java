/*
 Problem: 1567. Maximum Number of Vowels in a Substring of Given Length
 Language: java
 Runtime: 8 ms (98.69%)
 Memory: 46.5 MB (66.69%)
 Tags: String, Sliding Window
*/
class Solution {
    private static final boolean[] VOWEL = new boolean[128];
    static {
        VOWEL['a'] = VOWEL['e'] = VOWEL['i'] = VOWEL['o'] = VOWEL['u'] = true;
    }

    public int maxVowels(String s, int k) {
        int n = 0;
        for (int i = 0; i < k; i++) {
            n += VOWEL[s.charAt(i)] ? 1 : 0;
        }

        int max = n;
        int len = s.length();

        for (int right = k; right < len; right++) {
            n += (VOWEL[s.charAt(right)] ? 1 : 0)
               - (VOWEL[s.charAt(right - k)] ? 1 : 0);
            if (n > max) max = n;
        }
        return max;
    }
}
