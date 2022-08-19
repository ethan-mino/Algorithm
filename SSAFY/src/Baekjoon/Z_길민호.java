package Baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Z_길민호 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int search(int n, int r, int c){
        if(n == 1) {return (2*r) + c;}

        int p = (int) Math.pow(2, n);
        int pow = (int) Math.pow(2, 2*n - 2);

        if(r < p/2 && c < p/2){ // 좌상단 부분배열에서 탐색
            return search(n - 1, r, c);
        }else if(r < p/2 && c >= p/2){   // 우상단 부분배열
            return search(n - 1, r, c - p/2) + pow;
        }else if(r >= p/2 && c < p/2){  // 좌하단 부분배열
            return search(n - 1, r - p/2, c) + pow * 2;
        }else if(r >= p/2 && c >= p/2){  // 우하단 부분배열
            return search(n - 1, r - p/2, c - p/2) + pow * 3;
        }
        return -1;
    }

    public static void main(String[] args) throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        bw.write(search(n, r, c) + "\n");
        bw.flush();;
    }
}
