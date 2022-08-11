package Baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class BOJ16935 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[][] board = new int[101][101];

    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static int n, m;

    static void rotate(int dir){
        int[][] temp = new int[101][101];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dir == 1) temp[j][n - i - 1] = board[i][j];
                if(dir == 0) temp[m - j - 1][i] = board[i][j];
            }
        }
        int t  = n;
        n = m;
        m = t;
        for(int i = 0; i < n; i++)
            board[i] = Arrays.copyOf(temp[i], temp[i].length);
    }
    static void swap(int x1, int y1, int x2, int y2){
        int temp = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = temp;
    }

    static void printBoard() throws Exception{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                bw.write(board[i][j] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
    }

    static void sub(int roll){
        int col = n / 2;
        int row = m / 2;

        ArrayList<ArrayList<ArrayList<Integer>>> q = new ArrayList<>();

        int [][] order = {{2, 0, 3, 1}, {1, 3, 0, 2}};
        for(int xSt = 0; xSt < n; xSt += col){
            for(int ySt = 0; ySt < m; ySt += row){
                //System.out.println(xSt + " " + ySt);
                ArrayList<ArrayList<Integer>> subBoard = new ArrayList<>();
                for(int x = xSt; x < xSt + col; x++){
                    subBoard.add(new ArrayList<>());
                    for(int y = ySt; y < ySt +row; y++){
                        subBoard.get(x - xSt).add(board[x][y]);
                    }

                }
                q.add(subBoard);
            }
        }

        int idx = 0;
        int op = (roll == 1) ? 0 : 1;
        for(int xSt = 0; xSt < n; xSt += col){
            for(int ySt = 0; ySt < m; ySt += row){
                ArrayList<ArrayList<Integer>> front = q.get(order[op][idx++]);
                for(int x = xSt; x < xSt + col; x++){
                    for(int y = ySt; y <ySt +row; y++){
                        board[x][y] = front.get(x - xSt).get(y - ySt);
                    }
                }
            }
        }
    }
    static void operand(int op){
        if(op == 1){
            for(int i = 0; i < n / 2; i++)
                for(int j = 0; j < m; j++)
                    swap(i, j,  (n - 1) - i,  j);
        }else if(op == 2){
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m / 2; j++)
                    swap(i, j,  i,  (m - 1) - j);
        }else if(op == 3){
            rotate(1);
        }else if(op == 4){
            rotate(0);
        }else if(op == 5){
            sub(1);
        }else if(op == 6){
            sub(0);
        }
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

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < r; i++){
            int op = Integer.parseInt(st.nextToken());
            operand(op);
        }
        printBoard();
    }
}
