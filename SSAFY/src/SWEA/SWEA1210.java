package swea;

import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

class Pos{
    int x, y;
    public Pos(int x, int y){
        this.x = x; this.y = y;
    }
}
public class SWEA1210 {

    static final int BOARD_SIZE = 100;
    static final int CASE = 10;
    static int [][] board = new int[BOARD_SIZE][BOARD_SIZE];

    // 하, 우, 상, 좌
    static int []dx = {1, 0, 0};
    static int []dy = {0, 1, -1};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int tc = 1; tc <= CASE; tc++){
            br.readLine();
            StringTokenizer st = null;
            List<Pos> starts = new LinkedList<>();
            for(int i = 0; i < BOARD_SIZE; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < BOARD_SIZE; j++){
                    board[i][j] = Integer.parseInt(st.nextToken());
                    if(i == 0 && board[i][j] == 1) starts.add(new Pos(i, j));
                }
            }

            for(int i = 0; i < starts.size(); i++){
                boolean [][]vis = new boolean[BOARD_SIZE + 1][BOARD_SIZE + 1];
                for(int j = 0; j < BOARD_SIZE + 1; j++){
                    Arrays.fill(vis[j], false);
                }

                int dir = 0;
                Pos cur = new Pos(starts.get(i).x, starts.get(i).y);

                while(cur.x != BOARD_SIZE - 1){
                    // 오른쪽으로 이동할 수 있는 경우
                    if(cur.y + 1 < BOARD_SIZE
                    && !vis[cur.x][cur.y + 1]
                            && board[cur.x][cur.y + 1] == 1){
                        dir = 1;
                    }else if(cur.y - 1 >= 0
                            && !vis[cur.x][cur.y - 1]
                            && board[cur.x][cur.y - 1] == 1){
                        dir = 2;
                    }else{
                        dir = 0;
                    }

                    cur.x += dx[dir];
                    cur.y += dy[dir];
                    vis[cur.x][cur.y] = true;
                }

                if(board[cur.x][cur.y] == 2){
                    System.out.println("#" + tc + " " + starts.get(i).y + "\n");
//                    bw.write("#" + tc + " " + cur.x + "\n");
//                    bw.flush();
                    break;
                }
            }
        }
    }
}


/*
1
1 0 0 0 1 0 1 0 0 1
1 0 0 0 1 0 1 1 1 1
1 0 0 0 1 0 1 0 0 1
1 0 0 0 1 1 1 0 0 1
1 0 0 0 1 0 1 0 0 1
1 1 1 1 1 0 1 1 1 1
1 0 0 0 1 0 1 0 0 1
1 1 1 1 1 0 1 0 0 1
1 0 0 0 1 1 1 0 0 1
1 0 0 0 1 0 1 0 0 2
 */