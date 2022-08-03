package Baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ11660 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int [][] prefix = new int [1030][1030];
    public static void main(String[] args) throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j =1 ; j <= n; j++){
                prefix[i][j] = prefix[i][j - 1] + Integer.parseInt(st.nextToken());
            }
        }
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int sum = 0;
            for(int j = x1 - 1; j <= x2 - 1; j++){
                sum += prefix[j][y2] - prefix[j][y1 - 1];
            }
            bw.write(sum + "\n");
        }
        bw.flush();
    }
}
