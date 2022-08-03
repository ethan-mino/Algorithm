package swea;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA1873 {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static char [][] board = new char[30][30];

    static char[] dirs = {'^', '>', 'v', '<'};
    static char[] keys = {'U', 'R', 'D', 'L'};
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static void swap(int x1, int y1, int x2, int y2){
        char temp = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = temp;
    }

    public static void main(String[] args) throws Exception{
        int t = Integer.parseInt(bf.readLine());

        for(int tc = 1; tc <= t; tc++){
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int x = -1, y = -1;
            int dir = 0;
            for(int i = 0; i < n; i++) {
                String str = bf.readLine();
                for (int j = 0; j < m; j++){
                    board[i][j] = str.charAt(j);
                    for(int d = 0; d < 4; d++){
                        if(board[i][j] == dirs[d]) {
                            x = i; y = j;
                            dir = d;
                        }
                    }

                }
            }
            bf.readLine();
            String ops = bf.readLine();
            for(int i = 0; i < ops.length(); i++){
                //System.out.println(x + " " + y + dir);
                if(ops.charAt(i) == 'S'){
                    int sx = x, sy = y; // 현재 총알의 위치
                    while(true){
                        int nx = sx + dx[dir];
                        int ny = sy + dy[dir];

                        // 총알이 격자판을 넘는 경우 break;
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                        if(board[nx][ny] == '#') break; // 강철로 만들어진 벽인 경우 break;
                        if(board[nx][ny] == '*'){   // 벽을 파괴하고 break;
                            board[nx][ny] = '.';
                            break;
                        }else{  // 물이거나 평지인 경우
                            sx = nx; sy = ny;
                        }
                    }
                }else{
                    for(int j = 0; j < 4; j++){
                        // 입력한 키에 맞는 방향으로 문자 바꿔줌
                        if(keys[j] == ops.charAt(i)) dir = j;
                    }
                    board[x][y] = dirs[dir];    // 방향에 맞게 dir 값도 바꾸어줌

                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    // 이동 위치가 격자판을 벗어나거사 평지가 아닐 경우 continue;
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(board[nx][ny] != '.') continue;

                    swap(x, y, nx, ny);
                    x = nx; y = ny;
                }
            }

            System.out.print("#" + tc + " ");
            for(int a = 0; a < n; a++){
                for(int b = 0; b < m; b++){
                    System.out.print(board[a][b]);
                }
                System.out.println();
            }
        }
    }
}
