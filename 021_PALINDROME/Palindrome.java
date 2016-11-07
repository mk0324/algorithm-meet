//Hyeonsik Park
import java.io.*;

public class Palindrome {
    public static void main(String[] args){
        Palindrome palindrome = new Palindrome();
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            int length = Integer.parseInt(br.readLine());
            String[] input = br.readLine().split(" ");
            boolean[][] ret = palindrome.solution(input);
            int count = Integer.parseInt(br.readLine());
            while(count-->0){
                String[] quest = br.readLine().split(" ");
                int start = Integer.parseInt(quest[0])-1
                        ,end = Integer.parseInt(quest[1])-1;
                bw.write(ret[start][end]?"1\n":"0\n");
            }
                        
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
   
    //Dynamic Programming
    public boolean[][] solution(String[] input){
        boolean cache[][] = null;
        boolean ret = true;
        cache = new boolean[input.length+1][input.length+1];
        for(int i = 0; i < input.length; i++){
            cache[i][i] = true;
        }
        cache[0][1] = (input[0] == input[1]);
        for(int i = 1; i < input.length; i++){
            for(int j = 0; j < i; j++){
                cache[j][i] = (input[i].equals(input[j]));
                if(i-1>j+1) cache[j][i] &=cache[j+1][i-1];
            }
        }
        return cache;              
    }
}
