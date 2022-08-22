package swea;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

class Position{
    int x, y;
    public Position(int x, int y){this.x = x; this.y = y;}
}

public class SWEA1954 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int []dx = {0, 1, 0, -1};
    static int []dy = {1, 0, -1, 0};
    public static void main(String[] args) throws Exception{
        int t = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= t; tc++){
            int n = Integer.parseInt(br.readLine());
            int [][]board = new int [n][n];
            for(int i = 0; i < n; i++)
                Arrays.fill(board[i], 0);

            Position cur = new Position(0, 0);

            int dir = 0;
            int idx = 2;
            board[cur.x][cur.y] = 1;

            while(true){
                Position nx = null;
                int avail = 0;

                for(int i = 0; i < 4; i++){
                    nx = new Position(cur.x + dx[dir], cur.y + dy[dir]);
                    if((nx.x < 0 || nx.y < 0 || nx.x >= n || nx.y >= n)
                            || board[nx.x][nx.y] != 0)
                        dir = (dir + i) % 4;
                    else {
                        avail++;
                        break;
                    }
                }

                if(avail == 0) break;
                nx = new Position(cur.x + dx[dir], cur.y += dy[dir]);
                board[nx.x][nx.y] = idx++;
                cur = nx;
            }

            bw.write("#" + tc + "\n");
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++)
                    bw.write(board[i][j] + " ");
                bw.write("\n");
            }
            bw.flush();
        }
    }
}
