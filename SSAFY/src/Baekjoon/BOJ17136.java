package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ17136 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int [][]board = new int[10][10];

    static int ans = Integer.MAX_VALUE;
    static List<Pair> lenList = new LinkedList<>();
    static void back(int th, int cnt, boolean [][] cover, int paper[]){
        if(th == lenList.size()){
            ans = Math.min(ans, cnt);
        }else if(cnt < ans && th < lenList.size()){
            if(cover[lenList.get(th).pos.x][lenList.get(th).pos.y])
                back(th + 1, cnt, cover, paper);
            else{
                Pair cur = lenList.get(th);
                for(int len = cur.len; len >= 1; len--){
                    if(paper[len] >= 5) continue;

                    boolean [][] temp = new boolean[10][10];
                    int [] tempPaper = new int[6];

                    boolean avail = true;
                    for(int i =0 ; i < 10; i++) temp[i] = Arrays.copyOf(cover[i], 10);
                    tempPaper = Arrays.copyOf(paper, 6);

                    loop :
                    for(int x = cur.pos.x; x < cur.pos.x + len; x++){
                        for(int y = cur.pos.y; y < cur.pos.y + len; y++){
                            if(cover[x][y]) {
                                avail = false;
                                break loop;
                            }
                            temp[x][y] = true;
                        }
                    }

                    if(avail){
                        tempPaper[len]++;
                        back(th + 1, cnt + 1, temp, tempPaper);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        for(int i =0 ; i < 10; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < 10; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(board[i][j] == 1){   // 색종이를 붙일 수 있는 시작 지점이라면
                    int len = 1;
                    loop :
                    while(true){
                        for(int x = i; x < i + len; x++){
                            if(x >= 10){len--; break loop;}
                            for(int y = j; y < j + len; y++){
                                if(y >= 10 || board[x][y] != 1) {
                                    len--;
                                    break loop;
                                }
                            }
                        }
                        if(len == 5) break;
                        len++;
                    }
                    lenList.add(new Pair(new Pos7(i, j), len));
                }
            }
        }

        for(int i = 0; i < lenList.size(); i++){
            Pair p = lenList.get(i);
            // System.out.println("(" + p.pos.x + " " + p.pos.y + ") " + p.len);
        }
        back(0, 0, new boolean[10][10], new int[6]);
        if(lenList.size() != 0 && ans == Integer.MAX_VALUE)System.out.println(-1);
        else System.out.println(ans);
    }
}

class Pair{
    Pos7 pos;
    int len;
    Pair(Pos7 pos, int len){
        this.pos = pos;
        this.len = len;
    }
}

class Pos7{
    int x, y;
    Pos7(int x, int y){
        this.x = x;
        this.y = y;
    }
}

/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
-> 1

0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0

1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 1 0 0 0
1 1 1 1 1 1 1 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
-> 3

 */
