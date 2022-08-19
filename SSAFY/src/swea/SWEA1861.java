package swea;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Pos1 {
    int x, y;
    public Pos1(int x, int y){
        this.x = x; this.y = y;
    }
}

public class SWEA1861 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[][] board = new int[1010][1010];
    static int[][] vis = new int[1010][1010];
    static int [] dx = {-1, 0, 1, 0};
    static int [] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws Exception{
        int t = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= t; tc++){
            int n = Integer.parseInt(br.readLine());

            HashMap<Integer, Pos1> m = new HashMap<>();

            for(int i = 0; i < n; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++){
                    board[i][j] = Integer.parseInt(st.nextToken());
                    m.put(board[i][j], new Pos1(i, j));
                }
            }

            int maxCnt = Integer.MIN_VALUE;
            Pos1 ans = null;
            for(int k = 0; k < n; k++)
                Arrays.fill(vis[k], 0);

            for(int i = 1; i <= n * n; i++){
                int x = m.get(i).x;
                int y = m.get(i).y;

                int cnt = 1;
                Queue<Pos1> q = new LinkedList<>();
                q.add(new Pos1(x, y));
                vis[x][y] = 1;

                while(!q.isEmpty()){
                    Pos1 cur = q.peek(); q.remove();

                    for(int dir = 0; dir < 4; dir++){
                        Pos1 nxt = new Pos1(cur.x + dx[dir], cur.y + dy[dir]);

                        if(nxt.x < 0 || nxt.y < 0 || nxt.x >= n || nxt.y >= n) continue;
                        if(vis[nxt.x][nxt.y] != 0) continue;
                        if(board[nxt.x][nxt.y] != board[cur.x][cur.y] + 1) continue;
                        q.add(nxt);
                        vis[nxt.x][nxt.y] = vis[cur.x][cur.y] + 1;
                        cnt++;
                    }
                }

                if(maxCnt < cnt){
                    maxCnt = cnt;
                    ans = new Pos1(x, y);
                }else if(maxCnt == cnt){
                    if(board[ans.x][ans.y] > board[x][y]) ans = new Pos1(x, y);
                }
            }

            bw.write("#" + tc + " " + + board[ans.x][ans.y] + " " + maxCnt + "\n");
            bw.flush();
        }
    }
}

/*
2
2
1 2
3 4
3
9 3 4
6 1 5
7 8
 */