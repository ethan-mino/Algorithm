package Baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Pos3{
    int x, y;
    Pos3(int x, int y){
        this.x = x; this.y = y;
    }
}

public class BOJ16927 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[][] board = new int[500][500];

    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static int n, m;
    static void printArr() throws Exception{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                bw.write(board[i][j] + " ");
            }
            bw.write("\n");
        }
        bw.write("\n");
        bw.flush();
    }

    public static void main(String[] args) throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++)
                board[i][j] = Integer.parseInt(st.nextToken());
        }

        Pos3 leftUpper = new Pos3(0, 0);
        Pos3 rightLower = new Pos3(n - 1, m - 1);

        while(leftUpper.y < rightLower.y && leftUpper.x < rightLower.x){
            int cnt = (rightLower.y - leftUpper.y + 1) * 2 + (rightLower.x - leftUpper.x - 1) * 2;
            for(int i = 0; i < r % cnt; i++){
                Pos3 cur = new Pos3(leftUpper.x, leftUpper.y);
                int dir = 0;

                int tmp = board[cur.x][cur.y];
                while(!(cur.x == leftUpper.x + 1 && cur.y == leftUpper.y)){
                    Pos3 nxt = new Pos3(cur.x + dx[dir] , cur.y + dy[dir]);
                    board[cur.x][cur.y] = board[nxt.x][nxt.y];
                    cur = nxt;

                    if((cur.x == rightLower.x && cur.y == leftUpper.y)
                            || (cur.x == rightLower.x && cur.y == rightLower.y)
                            || (cur.x == leftUpper.x && cur.y == rightLower.y)){
                        dir++;
                    }
                }

                board[cur.x][cur.y] = tmp;
            }
            leftUpper.x++; leftUpper.y++;
            rightLower.x--; rightLower.y--;
        }

        printArr();
    }
}

/*
3 10 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
 */