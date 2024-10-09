import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        int N = citations.length;
        Arrays.sort(citations);
        int max = citations[N-1];
        for(int i = 1; i < max && i <= N; i++){
            if(citations[N-i] >= i){
                answer = i;
            }
            else{
                break;
            }
        }
        
        return answer;
    }
}