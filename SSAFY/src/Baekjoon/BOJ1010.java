import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ1010 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[][] dp = new int[40][40];    // dp[n][m]는 서쪽의 1번째 ~ n번째 사이트와 동쪽의 1번째 ~ m번째 사이트를 연결하는 경우의 수

    static public int topDown(int w, int e){
        if(dp[w][e] != 0) return dp[w][e];
        else{
            dp[w][e] = topDown(w, e - 1) + topDown(w - 1, e - 1);
            return dp[w][e];
        }
    }

    public static void main(String[] args) throws Exception{
        int t = Integer.parseInt(br.readLine());

        for(int tc = 0; tc < t; tc++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            for(int i = 1; i <= m; i++) dp[1][i] = i;
            for(int i = 1; i <= m; i++) dp[i][i] = 1;

//            for(int i = 2; i <= n; i++){
//                for(int j = i + 1; j <= m; j++){
//                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
//                }
//            }

            topDown(n, m);
            bw.write(dp[n][m] + "\n");
            bw.flush();
        }
    }
}