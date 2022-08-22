package swea;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA2805 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= t; tc++){
            int n = Integer.parseInt(br.readLine());
            int [][] board = new int[n + 1][n + 1];

            for(int i = 0; i < n; i++){
                String str = br.readLine();
                for(int j = 1; j <= n; j++){
                    board[i][j] = str.charAt(j - 1) - 48;
                    if(j != 0) board[i][j] += board[i][j - 1];
                }
            }

            int sum = 0;
            int mid = n / 2;
            for(int i = 0; i <= mid; i++){
                int left = mid - i;
                int right = mid + i;

                sum += board[i][right + 1] - board[i][left];
            }

            for(int i = mid + 1, j = 1; i < n; i++, j++){
                int left = j;
                int right = (n - 1) - j;

                sum += board[i][right + 1] - board[i][left];
            }
            bw.write("#" + tc + " " + sum + "\n");
            bw.flush();
        }
    }
}
/*
1
5
14054
44250
02032
51204
52212

// 11
// 3 - 1
// 0 4 8 10 15 15
 */