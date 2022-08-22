package swea;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA1208 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception{
        int t = 1;
        int row = 100;
        StringTokenizer st;

        for(int tc = 1; tc <= t; tc++){
            int[] h = new int[row];
            int n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());

            for(int i = 0; i < row; i++) h[i] = Integer.parseInt(st.nextToken());
            for(int i = 0; i < n; i++){
                int maxIdx = 0;
                int minIdx = 0;
                for(int j = 0; j < row; j++){
                    if(h[maxIdx] < h[j]) maxIdx = j;
                    if(h[minIdx] > h[j]) minIdx = j;
                }
                h[maxIdx]--;
                h[minIdx]++;
            }

            int maxIdx = 0;
            int minIdx = 0;
            for(int j = 0; j < row; j++){
                if(h[maxIdx] < h[j]) maxIdx = j;
                if(h[minIdx] > h[j]) minIdx = j;
            }

            bw.write("#" + tc + " " + (h[maxIdx] - h[minIdx]) + "\n");
            bw.flush();
        }
    }
}
