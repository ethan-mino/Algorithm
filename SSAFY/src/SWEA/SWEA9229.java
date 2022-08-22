import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA9229 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception{
        int t = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= t; tc++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            int weight[] = new int[n];
            for(int i = 0; i < n; i++){
                weight[i] = Integer.parseInt(st.nextToken());
            }

            int ans = Integer.MIN_VALUE;

            for(int i =0 ; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    int sum = weight[i] + weight[j];
                    if(sum <= m) ans = Math.max(ans, weight[i] + weight[j]);
                }
            }

            if(ans == Integer.MIN_VALUE) ans = -1;
            bw.write("#" + tc + " " + ans + " " + "\n");
            bw.flush();
        }
    }
}

/*
4
3 45
20 20 20
6 10
1 2 5 8 9 11
4 100
80 80 60 60
4 20
10 5 10 16
 */