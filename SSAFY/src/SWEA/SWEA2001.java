package swea;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA2001 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int sum(int[][] board, int x1, int y1, int x2, int y2){
        int s = 0;

        for(int j = x1 - 1; j <= x2 - 1; j++){
            s += board[j][y2] - board[j][y1 - 1];
        }
        return s;
    }

    public static void main(String[] args) throws Exception{
        int t = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= t; tc++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int [][] board = new int[n][n + 1];

            for(int i =0 ; i < n; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 1; j <= n; j++){
                    board[i][j] = board[i][j - 1] + Integer.parseInt(st.nextToken());
                }
            }

            int ans = 0;
            for(int x1 = 1; x1 <= n - m + 1; x1++){
                for(int y1 = 1; y1 <= n - m + 1; y1++){
                    ans = Math.max(ans, sum(board, x1, y1, x1 + m - 1, y1 + m - 1));
                }
            }

            bw.write("#" + tc + " " +ans + "\n");
            bw.flush();
        }
    }
}
