package swea;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA5215 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int []d = new int [10010];
    static int ans;
    static boolean[] selected = new boolean[30];
    static int [] scores;
    static int [] cals;

    // n개의 수열중 th번째를 선택
    static void combination(int th, int n, int pre, int score, int cal, int limit){
        if(th <= n){
            if(cal <= limit) ans = Math.max(ans, score);
        }

        if(th < n){
            for(int cur = pre + 1; cur < n; cur++){
                if(!selected[cur]){
                    selected[cur] = true;
                    combination(th + 1, n, cur, score + scores[cur], cal + cals[cur], limit);
                    selected[cur] = false;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        int t = Integer.parseInt(br.readLine());
        StringTokenizer st = null;

        for(int i = 1; i <= t; i++){
            ans = Integer.MIN_VALUE;
            st = new StringTokenizer(br.readLine(), " ");

            int gn = Integer.parseInt(st.nextToken());
            int limit = Integer.parseInt(st.nextToken());
            scores = new int [gn];
            cals = new int [gn];

            for(int j = 0; j < gn; j++){
                st = new StringTokenizer(br.readLine(), " ");
                scores[j] = Integer.parseInt(st.nextToken());
                cals[j] = Integer.parseInt(st.nextToken());
            }

            for(int j = 1; j <= gn; j++){
                combination(0, j, -1, 0, 0, limit);
            }
            bw.write("#" + i + " " + ans);
        }
    }
}
/*
1
1 1000
100 1000

2
5 1000
100 200
300 500
250 300
500 1000
400 400
5 1000
100 200
300 500
250 300
500 1000
400 400
 */