import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class BOJ12891 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int [] limit = new int [4];
    static int [][] cnt = new int [1000010][4];
    static Map<Character, Integer> dna = new HashMap<Character, Integer>(){
        {
            put('A', 0);
            put('C', 1);
            put('G', 2);
            put('T', 3);
        }
    };

    public static void main(String[] args) throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        String str = br.readLine();
        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < 4; i++) limit[i] = Integer.parseInt(st.nextToken());

        int ans = 0;
        cnt[1][dna.get(str.charAt(0))]++;
        for(int start = 2; start <= str.length(); start++) {
            cnt[start] = Arrays.copyOf(cnt[start - 1], 4);
            cnt[start][dna.get(str.charAt(start - 1))]++;
        }

        for(int start = 0; start <= str.length() - p; start++){ // start는 부분문자열의 시작 위치
            int end = start + p - 1;

            boolean avail = true;
            for(int i = 0; i < 4; i++){
                if(limit[i] > cnt[end + 1][i] - cnt[start][i])
                    avail = false;
            }

            if(avail) ans++;
        }
        System.out.println(ans);
    }
}
