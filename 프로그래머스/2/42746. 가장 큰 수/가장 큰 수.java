import java.util.*;

class Solution {    
    public String solution(int[] numbers) {
        StringBuilder answer = new StringBuilder();
        int N = numbers.length;
        String[] arr = new String[N];
        for(int i = 0; i < N; i++){
            arr[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(arr, (s1, s2) -> (s2 + s1).compareTo(s1 + s2));
        
        if (arr[0].equals("0")) {
           return "0";
        }
        
        for(int i = 0; i < N; i++){
            answer.append(arr[i]);
        }
        
        String ans = answer.toString();
        
        return ans;
    }
}