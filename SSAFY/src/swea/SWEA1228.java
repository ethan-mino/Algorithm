import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class SWEA1228 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static final int CASE = 10;
    public static void main(String[] args) throws Exception{
        for(int tc = 1; tc <= CASE; tc++){
            int n = Integer.parseInt(br.readLine());

            String encryptStr = br.readLine();
            String[] tokenizedEncrypt = encryptStr.split(" ");
            List<String> encrypt = Arrays.stream(tokenizedEncrypt).collect(Collectors.toList());

            int opNum = Integer.parseInt(br.readLine());

            String[] token = br.readLine().split("I");

            for(int i =1; i < opNum + 1; i++){
                String[] t = token[i].trim().split(" ");
                int x = Integer.parseInt(t[0]);
                int y = Integer.parseInt(t[1]);
                for(int j = 2; j < t.length; j++){
                    encrypt.add(x + j - 2, t[j]);
                }
            }
            bw.write("#" + tc + " " );
            for(int i = 0; i < 10; i++){
                bw.write(encrypt.get(i) + " ");
            }
            bw.write("\n");
            bw.flush();
        }
    }
}
