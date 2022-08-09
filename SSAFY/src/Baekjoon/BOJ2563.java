package Baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ2563 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int [][] board = new int[100][100];

    public static void main(String[] args) throws Exception{
        int n = Integer.parseInt(br.readLine());

        int sum = 0;
        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());

            for(int x = x1; x < x1 + 10; x++){
                for(int y = y1; y < y1 + 10; y++){
                    if(board[x][y] != 1){
                        board[x][y] = 1;
                        sum++;
                    }
                }
            }
        }
        bw.write(sum +"");
        bw.flush();
    }
}
