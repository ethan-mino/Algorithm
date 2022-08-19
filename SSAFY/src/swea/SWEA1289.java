package swea;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class SWEA1289 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception{

        int t = Integer.parseInt(br.readLine());
        for(int i = 1; i <= t; i++){

            int ans = 0;
            char[] bits = br.readLine().toCharArray();
            char[] recover = new char[bits.length];
            for(int j = 0; j < bits.length; j++) recover[j] = '0';

            for(int j = 0; j < bits.length; j++){
                if(bits[j] != recover[j]){
                    ans++;
                    for(int idx = j; idx < bits.length; idx++){
                        recover[idx] = (char) (('1' + 48) - recover[idx]);
                    }
                }
            }

            bw.write("#" + i + " " + ans + "\n");
        }
        bw.flush();
    }
}
