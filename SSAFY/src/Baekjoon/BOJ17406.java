package Baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.InputStreamReader;

class Pos{
    int x, y;
    public Pos(int x, int y) {this.x = x; this.y = y;}
}

public class BOJ17406 {
    // 하우상좌
    static int n, m, k;
    static int ans = Integer.MAX_VALUE;
    static int [] dx = {1, 0, -1, 0};
    static int [] dy = {0, 1, 0, -1};

    static boolean [] isSelect = new boolean [50];
    static int[][] np;

    static int min(int [][]board) {
        int max = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++) {
            int rowSum = 0;
            for(int j = 0 ; j < m; j++) {
                rowSum += board[i][j];
            }
            max = Math.min(max, rowSum);
        }

        return max;
    }

    static void rotate(int [][]board, int r, int c, int s){
        Pos leftUpper = new Pos(r - s, c - s), rightLower = new Pos(r + s, c + s);

        while(leftUpper.y < rightLower.y) {
            int dir = 0;
            Pos cur = new Pos(leftUpper.x, leftUpper.y);
            Pos nx = null;
            int startValue = board[cur.x][cur.y];

            while(nx == null || !(nx.x == leftUpper.x && nx.y == leftUpper.y)){
                nx = new Pos(cur.x + dx[dir], cur.y + dy[dir]);

                board[cur.x][cur.y] = board[nx.x][nx.y];
                cur = nx;

                if((cur.x == leftUpper.x && cur.y == rightLower.y)	// 오른쪽 상단
                        || (cur.x == rightLower.x && cur.y == rightLower.y)	// 오른쪽 하단
                        || (cur.x == rightLower.x && cur.y == leftUpper.y))	// 왼쪽 하단
                    dir = (dir + 1) % 4;
            }

            board[leftUpper.x][leftUpper.y + 1] = startValue;
            leftUpper.x++; leftUpper.y++;
            rightLower.x--; rightLower.y--;
        }
    }

    static void permutation(int th, int[][] board){
        if(th == k) {
            ans = Math.min(ans, min(board));
        }else{
            for(int i = 0; i < k; i++) {
                if(!isSelect[i]) {
                    isSelect[i] = true;
                    int [][]temp = new int [50][50];
                    for(int x = 0; x < n; x++) {
                        for(int y = 0; y < m; y++) {
                            temp[x][y] = board[x][y];
                        }
                    }
                    rotate(temp, np[i][0], np[i][1], np[i][2]);
                    permutation(th + 1, temp);
                    isSelect[i] = false;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine(), " ");

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        np = new int[k][3];
        int[][] board = new int[50][50];

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(bf.readLine(), " ");
            for(int j = 0 ; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 0; i < k; i++) {
            st = new StringTokenizer(bf.readLine(), " ");
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());

            np[i][0] = r - 1; np[i][1] = c - 1; np[i][2] = s;
        }

        permutation(0, board);

        System.out.println(ans);
    }
}