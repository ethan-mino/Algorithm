import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class BOJ1158 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        LinkedList<Integer> list = new LinkedList<>();


        for(int i = 1; i <= n; i++) list.add(i);

        List<Integer> order = new ArrayList<>();

        int cur = k - 1;
        while(!list.isEmpty()){
            order.add(list.get(cur));
            list.remove(cur);
            cur += k - 1;

            while(!list.isEmpty() && cur >= list.size()){
                cur = cur - list.size();
            }
        }

        bw.write("<");
        for(int i = 0; i < n; i++){
            bw.write(order.get(i) + "");
            if(i != n - 1) bw.write(", ");
        }
        bw.write(">");
        bw.flush();
    }
}