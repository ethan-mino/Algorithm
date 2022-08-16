import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

class Top{
    int idx;
    int v;
    Top(int idx, int v){
        this.idx = idx;
        this.v = v;
    }
}

public class BOJ2493 {
    static int [] top = new int[500010];

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        Stack<Top> s = new Stack<>();
        s.push(new Top(0, 200_000_000));
        for(int i = 1; i <= n; i++)  top[i] = Integer.parseInt(st.nextToken());

        for(int i = 1; i <= n; i++){
            while(s.peek().v < top[i]){    // 현재 탑이 더 큰 경우
                s.pop();
            }
            bw.write(s.peek().idx + " ");
            s.push(new Top(i, top[i]));
        }
        bw.flush();
    }
}
/*
5
10 6 14 12 111
 */