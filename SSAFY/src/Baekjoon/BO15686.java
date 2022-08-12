package Baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

class Pos4{
    int x, y;
    Pos4(int x, int y){
        this.x = x; this.y = y;
    }
}

public class BO15686 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[][] board = new int[60][60];
    static int n, m;
    static List<Pos4> chicken = new LinkedList<>();
    static List<Pos4> house = new LinkedList<>();
    static boolean[] sel = new boolean[20];
    static int[] selChicken = new int[20];
    static int[][] dist = new int[101][20];

    static int manhattan(Pos4 p1, Pos4 p2){
        return Math.abs(p1.x - p2.x) + Math.abs(p1.y - p2.y);
    }
    static int ans = Integer.MAX_VALUE;
    static void combination(int th, int en, int pre){
        if(th == en){
            int sum = 0;
            for(int i = 0; i < house.size(); i++){
                int min = Integer.MAX_VALUE;
                for(int j = 0; j < en; j++){
                    min = Math.min(min, dist[i][selChicken[j]]);
                }
                sum += min;
            }
            ans = Math.min(ans, sum);
        }else{
            for(int cur = pre + 1; cur < chicken.size(); cur++){
                if(!sel[cur]){
                    sel[cur] = true;
                    selChicken[th] = cur;
                    combination(th + 1, en, cur);
                    sel[cur] = false;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
                if(board[i][j] == 1) house.add(new Pos4(i, j));
                if(board[i][j] == 2) chicken.add(new Pos4(i, j));
            }
        }

        for(int i = 0; i < house.size(); i++){  // 각 집과 치킨집간의 거리를 계산
            for(int j = 0; j < chicken.size(); j++){
                dist[i][j] = manhattan(house.get(i), chicken.get(j));
            }
        }

        for(int i = 1; i <= m; i++) // 폐업시키지 않을 치킨집을 1개 ~ m개 선택
            combination(0, i, -1);
        System.out.println(ans);
    }
}
