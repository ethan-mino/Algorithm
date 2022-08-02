package Baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1244 {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());

        int [] switches = new int[n + 1];

        StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
        for(int i = 1; i <= n; i++)
            switches[i] = Integer.parseInt(st.nextToken());

        int m = Integer.parseInt(bf.readLine());
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(bf.readLine(), " ");
            int gen = Integer.parseInt(st.nextToken());
            int num = Integer.parseInt(st.nextToken());

            switch(gen){
                case 1 :
                    int cur = num;
                    int idx = 2;
                    while(cur <= n){
                        switches[cur] = 1- switches[cur];
                        cur = num * idx++;
                    }
                    break;
                case 2 :
                    int l = num, r = num;
                    while(l > 1 && r < n && switches[l - 1] == switches[r + 1]){
                        l--; r++;
                    }

                    for(int j = l; j <= r; j++){
                        switches[j] = 1 - switches[j];
                    }
                    break;
            }
        }

        for(int j = 1; j <= n; j++) {
            System.out.print(switches[j]+ " ");
            if(j % 20 == 0) System.out.println();
        }
    }
}

/*
14
0 0 0 0 0 0 0 0 0 0 0 0 0 0
1
1 3

14
0 0 0 0 0 0 0 0 0 0 0 0 0 0
1
2 3

8
0 1 1 1 0 1 0 1
1
2 4

8
0 1 0 1 0 0 0 1
2
1 3
2 3

 */
