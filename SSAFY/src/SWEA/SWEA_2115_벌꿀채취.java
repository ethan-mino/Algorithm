package SWEA;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class SWEA_2115_벌꿀채취 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m, c;
    static int [][] board;
    static int maxBenefit;

    // honey 중에서 최대 m개의 벌통을 선택하여 꿀의 양이 c를 넘어가지 않으면서, 최대 수익을 maxBenefit에 저장해주는 함수
    /*
        @param honeyIdx honey의 idx
        @param totalHoney 선택한 꿀의 총합
        @param totalBenefit 선택한 꿀의 총 수익
     */

    static void back(int honeyIdx, List<Integer> honeyList, int totalHoney, int totalBenefit){
        if(honeyIdx == honeyList.size()){
            maxBenefit = Math.max(maxBenefit, totalBenefit);
        }else{
            int curHoney = honeyList.get(honeyIdx);
            // 현재 꿀을 선택하지 않은 경우
            back(honeyIdx + 1, honeyList, totalHoney, totalBenefit);

            // 현재 꿀을 선택하는 경우
            int nxHoney = totalHoney + curHoney;
            int nxBenefit = totalBenefit + (curHoney * curHoney);
            if(nxHoney <= c) back(honeyIdx + 1, honeyList, nxHoney, nxBenefit);
        }
    }

    public static void main(String[] args) throws Exception{
        int t = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= t; tc++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            board = new int[n][n];

            for(int i = 0; i < n; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < n; j++){
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int ans = Integer.MIN_VALUE;
            boolean [][] selected = new boolean[n][n];   // true면 해당 벌통을 수집했음을 나타냄

            for(int x1 = 0; x1 < n; x1++){
                for(int y1 = 0; y1 < n; y1++){
                    for(int i = 0 ; i < n; i++)
                        Arrays.fill(selected[i], false);

                    int aBenefit = 0; // 두 일꾼이 채취한 꿀의 양
                    List<Integer> honeyList = new LinkedList<>();

                    // 첫 번째 일꾼의 벌통 수익 계산
                    for(int dy = 0; dy < m; dy++){
                        int ny = y1 + dy;

                        // y1 + dy가 n * n을 벗어나는 경우
                        if(ny >= n) break;

                        aBenefit += board[x1][ny];
                        honeyList.add(board[x1][ny]);
                        selected[x1][ny] = true;
                    }

                    if(honeyList.size() < m) continue;

                    if(aBenefit > c){   // 첫 번째 일꾼이 선택한 꿀이 c를 넘어가는 경우
                        maxBenefit = Integer.MIN_VALUE;
                        back(0, honeyList, 0, 0);
                    }else{  // 첫 번째 일꾼이 선택한 꿀이 c를 넘어가지 않는 경우
                        maxBenefit = 0;
                        for(int honey : honeyList){
                            maxBenefit += honey * honey;
                        }
                    }
                    int aMaxBenefit = maxBenefit;

                    // 두 번째 일꾼의 벌통 수익 계산
                    for(int x2 = 0; x2 < n; x2++){
                        for(int y2 = 0; y2 < n; y2++){
                            int bBenefit = 0;
                            honeyList.clear();

                            for(int dy = 0; dy < m; dy++){
                                int ny = y2 + dy;

                                // y1 + dy가 n * n을 벗어나는 경우
                                if(ny >= n) break;

                                // 첫 번째 일꾼이 이미 채취한 경우
                                if(selected[x2][ny]) break;

                                bBenefit += board[x2][ny];
                                honeyList.add(board[x2][ny]);
                            }
                            if(honeyList.size() < m) continue;

                            // 꿀의 양 계산
                            if(bBenefit > c){   // 첫 번째 일꾼이 선택한 꿀이 c를 넘어가는 경우
                                maxBenefit = Integer.MIN_VALUE;
                                back(0, honeyList, 0, 0);
                            }else{  // 첫 번째 일꾼이 선택한 꿀이 c를 넘어가지 않는 경우
                                maxBenefit = 0;
                                for(int honey : honeyList){
                                    maxBenefit += honey * honey;
                                }
                            }
                            int bMaxBenefit = maxBenefit;

                            ans = Math.max(ans, aMaxBenefit + bMaxBenefit);
                        }
                    }
                }
            }

            bw.write("#" + tc + " " + ans + "\n");
            bw.flush();
        }
    }
    // 제한조건을 보고 백트래킹이 가능한 지 확인
    // n = 10, m = 5일 때의 시간복잡도를 계산
    // (10 * 10C5) * (10 * 10C5)
    // (10 * 252) * (10 * 252) = 6,350,400

    // 단, 최대 수익을 계산해야하기 때문에, 최저 수익을 계산할 때의 최적화 기법을 사용할 수 없음
    // 벌통은 가로로 연속적으로 채취해야한다.
    // 꿀을 채취할 수 있는 최대 양이 정해져 있음
}

/*
1
4 2 13
6 1 9 7
9 8 5 8
3 4 5 3
8 2 6 7

1
3 3 10
7 2 9
6 6 6
5 5 7

1r
10 5 30
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
 */