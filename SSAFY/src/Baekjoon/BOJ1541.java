package Baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ1541 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static String exp;

    static int sectionSum(int st, int en){
        String subString = exp.substring(st, en + 1);
        String[] numbers = subString.split("[-+]");

        int sum = 0;
        for(String number : numbers) sum += Integer.parseInt(number);
        return sum;
    }

    public static void main(String[] args) throws Exception{
        // -로 시작해서 가장 큰 값에 괄호를 쳐주면 됨
        exp = br.readLine();

        boolean minus = false;
        int ans = Integer.MAX_VALUE;

        for(int i =0; i < exp.length(); i++){
            if(exp.charAt(i) == '-') minus = true;
        }

        if(minus){
            int cur = 0;
            int st = -1, en = -1;
            while(cur < exp.length()){
                if((exp.charAt(cur) == '-' && st != -1)){
                    en = cur - 1;
                    int sum = sectionSum(0, st - 2)
                            - sectionSum(st, en)
                            + sectionSum(en + 2, exp.length() - 1);
                    ans = Math.min(ans, sum);
                }else if(exp.charAt(cur) == '-' && st == -1){
                    st = cur + 1;
                }

                cur++;
            }

            if(st != -1){
                en = exp.length() - 1;
                int sum = sectionSum(0, st - 2)
                        - sectionSum(st, en);
                ans = Math.min(ans, sum);
            }
        }else{
            ans = sectionSum(0, exp.length() - 1);
        }
        System.out.println(ans);
    }
}
