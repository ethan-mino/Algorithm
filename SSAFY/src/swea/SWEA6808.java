package swea;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA6808 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int []p1 = new int[9];
    static int []p2 = new int[9];

    static int lose = 0;
    static int win = 0;
    static boolean []sel = new boolean[9];
    static void back(int th, int score1, int score2){
        if(th == 10){
            if(score1 > score2) win++;
            else if(score1 < score2) lose++;
        }else{
            for(int i = 0; i < 9; i++){
                if(!sel[i]){
                    sel[i] = true;
                    int sum = p1[th - 1] + p2[i];
                    if(p1[th - 1] < p2[i]) back(th + 1, score1, score2 + sum);
                    else back(th + 1, score1 + sum, score2);
                    sel[i] = false;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        int t = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= t; tc++){
            win = 0; lose = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());

            for(int i = 0; i < 9; i++)
                p1[i] = Integer.parseInt(st.nextToken());

            int idx = 0;
            for(int i = 1; i <= 18; i++){
                boolean exist = false;
                for(int j = 0; j < 9; j++){
                    if(i == p1[j]) exist = true;
                }
                if (!exist) p2[idx++] = i;
            }

            back(1, 0, 0);
            bw.write("#" + tc + " " + win + " " + lose + "\n");
            bw.flush();
        }
    }
}

/*
4
1 3 5 7 9 11 13 15 17
18 16 14 12 10 8 6 4 2
13 17 9 5 18 7 11 1 15
1 6 7 9 12 13 15 17 18
 */