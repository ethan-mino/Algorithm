import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class SWEA1225 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static final int CASE = 10;

    public static void main(String[] args) throws Exception{
        for(int tc = 1; tc <= CASE; tc++){
            int t = Integer.parseInt(br.readLine());
            Queue<Integer> q = new LinkedList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i =0; i < 8; i++){
                int c = Integer.parseInt(st.nextToken());
                q.add(c);
            }

            boolean end = false;
            while(!end){
                for(int i = 1; i <= 5; i++){
                    int p = Math.max(0, q.peek() - i);
                    q.remove();
                    q.add(p);
                    if(p == 0) {
                        end = true;
                        break;
                    }
                }
            }

            bw.write("#" + tc + " " );
            for(int i = 0; i < 8; i++){
                bw.write(q.peek() + " ");
                q.remove();
            }
            bw.write("\n");
            bw.flush();
        }
    }
}

/*
1
10 6 12 8 9 4 1 3
*/