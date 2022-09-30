import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Jungol_2577_회전초밥 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());   // 접시의 수
        int d = Integer.parseInt(st.nextToken());   // 초밥의 가짓수
        int k = Integer.parseInt(st.nextToken());   // 연속해서 먹는 접시의 수
        int c = Integer.parseInt(st.nextToken());   // 쿠폰 번호

        int [] sushi = new int[n];
        int [] cnt = new int [d + 1]; // selected[i]는 번호가 i인 초밥을 선택했는지를 나타냄

        for(int i = 0 ; i < n; i++)
            sushi[i] = Integer.parseInt(br.readLine());

        int curKind = 0;
        for(int i = 0; i < k; i++){
            cnt[sushi[i]]++;
            if(cnt[sushi[i]] == 1){
                curKind++;
            }
        }

        int maxKind = curKind;    // 연속해서 k개의 초밥을 먹었을 때의 초밥 가짓수의 최댓
        for(int firstDishIdx = 1; firstDishIdx < n; firstDishIdx++){
            int preDishIdx = firstDishIdx - 1;  // 제거되는 접시의 idx
            int newDishIdx = (firstDishIdx + (k - 1)) % n;  // 새로운 접시의 idx
            int preSushiNum = sushi[preDishIdx];    // 제거되는 초밥의 번호
            int newSushiNum = sushi[newDishIdx];    // 새로운 초밥의 번호

            // 슬라이딩 윈도우를 벗어나는 접시 선택 해제
            cnt[preSushiNum]--;
            if(cnt[preSushiNum] == 0) {
                curKind--;
            }

            // 추가되는 접시 선택
            cnt[newSushiNum]++;
            if(cnt[newSushiNum] == 1){  // 포함되지 않았던 종류의 스시인 경우
                curKind++;  // 스시 종류 증가
            }

            cnt[c]++;
            if(cnt[c] == 1) {   // 쿠펀 번호의 스시가
                curKind++;
            }

            maxKind = Math.max(maxKind, curKind);
        }

        System.out.println(maxKind);// 초밥 가짓수의 최댓값 출력
    }
}
