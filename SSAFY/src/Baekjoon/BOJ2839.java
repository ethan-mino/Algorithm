import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ2839 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception{
        int n = Integer.parseInt(br.readLine());

        int ans = 0;
        if((n % 5) % 3 != 0){
            for(int i = (n / 5); i >= 0; i--){
                if((n - (i * 5)) % 3 != 0) continue;
                ans += i;
                ans += (n - (i * 5)) / 3;
                break;
            }
        }else{
            ans += (n / 5);
            ans += (n % 5) / 3;
        }
        if(ans == 0) System.out.println(-1);
        else System.out.println(ans);
    }
}
