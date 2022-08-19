import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ2023 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static boolean isPrime(int n){
        if(n < 2) return false;
        for(int i = 2; i*i <= n; i++){
            if(n%i ==0) return false;
        }
        return true;
    }

    static void back(int th, int num) throws Exception{
        if(th == 0) {
            bw.write(num + "\n");
        }else{
            for(int i = 1; i < 10; i+=2){
                int nx = num * 10 + i;
                if(isPrime(nx)) back(th - 1, nx);
            }
        }
    }
    public static void main(String[] args) throws Exception{
        int n = Integer.parseInt(br.readLine());

        int [] prime = {2, 3, 5, 7};
        for(int i =0; i < prime.length; i++){
            back(n - 1, prime[i]);
        }
        bw.flush();
    }
}
