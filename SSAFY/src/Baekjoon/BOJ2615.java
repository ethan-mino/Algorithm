package Baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ2615 {
    static int[] dx = {-1, -1, -1, 0, 1, 1, 1, 0};
    static int[] dy = {-1, 0, 1, 1, 1, 0, -1, -1};
    static final int boardSize = 19;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int[][] board = new int [boardSize][boardSize];

        for(int i = 0; i < boardSize; i++){
            StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
            for(int j = 0; j < boardSize; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        boolean end = false;	// 게임의 승부가 결정되었는지를 나타내는 flag 변수
        int win = -1;	// 검은색이 이기면 1, 흰색이 이기면 2
        int posX = boardSize + 1, posY = boardSize + 1;	// 가장 왼쪽 바둑알 또는 가장 위쪽 바둑알

        for(int i = 0; i < boardSize; i++){
            for(int j = 0; j < boardSize; j++){
                if(!end && board[i][j] != 0){
                    int [] cnt = new int[8];	// 해당 방향에 연속해서 놓인 동일한 바둑알의 개수
                    int [] px = new int[8];
                    int [] py = new int[8];

                    for(int x =0 ; x < 8; x++) px[x] = boardSize + 1;
                    for(int y =0 ; y < 8; y++) py[y] = boardSize + 1;

                    for(int dir = 0; dir < 8; dir++){
                        int curX = i, curY = j;
                        while(board[curX][curY] == board[i][j]){
                            if(dir == 1 || dir == 5){	// 세로인 경우
                                if(curX < px[dir]){
                                    px[dir] = curX; py[dir] = curY;
                                }
                            }else{
                                if(curY < py[dir]){
                                    px[dir] = curX; py[dir] = curY;
                                }
                            }

                            curX += dx[dir];
                            curY += dy[dir];
                            cnt[dir]++;
                            if(curX < 0 || curY < 0 || curX >= boardSize || curY >= boardSize) break;
                        }
                    }

                    for(int k = 0; k < 4; k++){
                        int cntSum = cnt[k] + cnt[k + 4] - 1;
                        if(cntSum == 5){
                            if(k == 0 || k == 1){
                                posX = px[k]; posY = py[k];
                            }else{
                                posX = px[k + 4]; posY = py[k + 4];
                            }
                            win = (board[i][j] == 1) ? 1 : 2;
                            end = true;
                            break;
                        }
                    }
                }
            }
        }

        if(end){
            System.out.println(win);
            System.out.println((posX  + 1) + " " + (posY + 1));
        }else{
            System.out.println(0);
        }
    }
}