import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.Vector;

public class BOJ3040 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] p = new int[9];
    static boolean[] sel = new boolean[9];
    static int [] selected = new int[7];

    static void combination(int th, int pre, int sum) throws Exception{
        //System.out.println(sum);
        if(th == 7){
            if(sum == 100){
                for(int i = 0; i < selected.length; i++)
                    bw.write(selected[i] + "\n");
                bw.flush();
            }
        }else{
            for(int cur = pre + 1; cur < 9; cur++){
                if(!sel[cur]){
                    sel[cur] = true;
                    selected[th] = p[cur];
                    combination(th + 1, cur, sum + p[cur]);
                    sel[cur] = false;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        for(int i = 0; i < 9; i++) p[i] = Integer.parseInt(br.readLine());
        combination(0, -1, 0);
    }
}
