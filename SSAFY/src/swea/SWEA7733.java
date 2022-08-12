package swea;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pos{
    public int x, y;
    public Pos(int x, int y){
        this.x= x; this.y = y;
    }
}

public class SWEA7733 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[][] board = new int[101][101];
    static int[][] vis = new int[101][101];
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    public static void main(String[] args) throws Exception{
        int t = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= t; tc++){
            int n = Integer.parseInt(br.readLine());
            for(int i = 0; i < n; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j = 0; j < n; j++){
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int area = Integer.MIN_VALUE;
            int curArea = 0;
            int day = 0;

            do{
                for(int i =0 ; i < n; i++)
                    for(int j = 0; j < n; j++)
                        if(board[i][j] == day) board[i][j] = 0;

                curArea = 0;
                for(int k = 0; k < n; k++) Arrays.fill(vis[k], 0);
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(board[i][j] != 0 && vis[i][j] == 0){
                            Queue<Pos> q = new LinkedList<>();

                            q.add(new Pos(i, j));
                            vis[i][j] = 1;
                            curArea++;

                            while(!q.isEmpty()){
                                Pos cur = q.peek(); q.remove();

                                for(int dir = 0; dir < 4; dir++){
                                    int nx = cur.x + dx[dir];
                                    int ny = cur.y + dy[dir];

                                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                                    if(board[nx][ny] == 0 || vis[nx][ny] != 0) continue;
                                    q.add(new Pos(nx, ny));
                                    vis[nx][ny] = vis[cur.x][cur.y] + 1;
                                }
                            }
                        }
                        area = Math.max(curArea, area);
                    }
                }

                day++;
            }while(day < 100 && curArea > 0);

            bw.write("#" + tc + " " + area + "\n");
            bw.flush();
        }
    }
}

/*
2
2
1 2
2 1
5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7


1
5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7
 */