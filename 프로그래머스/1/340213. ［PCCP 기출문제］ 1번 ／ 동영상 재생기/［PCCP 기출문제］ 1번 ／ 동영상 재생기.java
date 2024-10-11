import java.util.*;

class Solution {
    
    int time_extract(String str){
        
        int min = Integer.parseInt(str.substring(0,2));
        int sec = Integer.parseInt(str.substring(3,5));
        
        int time = min * 60 + sec;
        
        return time;
    }
    
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        
        int time = time_extract(pos);
        int op_s = time_extract(op_start);
        int op_e = time_extract(op_end);
        int v_l = time_extract(video_len);
        
        if(time >= op_s && time<= op_e){
            time = op_e;
        }

        for(int i = 0; i < commands.length; i++){
            if(commands[i].equals("next")){
                if(time + 10 >= v_l){
                    time = v_l;
                }
                else{
                    time += 10;
                }
            }
            else if(commands[i].equals("prev")){
                if(time  < 10){
                    time = 0;
                }
                else{
                    time -= 10;
                }
            }
            if(time >= op_s && time<= op_e){
                time = op_e;
            }
        }        

        if(time / 60 < 10){
            answer += "0";
        }
        answer += time/60+":";
        
        if(time%60 < 10){
            answer+="0";
        }
        answer+= time % 60;
        
        return answer;
    }
}