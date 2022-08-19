import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ2164 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        Queue<Integer> q = new LinkedList<>();

        for(int i = 1; i <= n; i++) q.add(i);

        while(q.size() > 1){
            q.remove();
            int v = q.remove();
            q.add(v);
        }

        bw.write(q.peek() + "\n");
        bw.flush();;
    }
}
