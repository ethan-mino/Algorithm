import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

class Temp implements Comparable<Temp>{
    int low, high;
    public Temp(int low, int high){
        this.low = low; this.high = high;
    }

    @Override
    public int compareTo(Temp o) {
        if(this.low == o.low){
            return this.high - o.high;  // 최고온도 오름차순
        }else return this.low - o.low;  // 최저온도 오름차순
    }
}

public class JUNGOL1828 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static List<Temp> temp = new LinkedList<>();

    public static void main(String[] args) throws Exception{
        int n = Integer.parseInt(br.readLine());
        for(int i =0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int low = Integer.parseInt(st.nextToken());
            int high = Integer.parseInt(st.nextToken());
            temp.add(new Temp(low, high));
        }

        Collections.sort(temp);

        int ans = 0;
        int l = 1, h = -1;
        int cur = 0;
        while(cur < n){
            if(l <= temp.get(cur).low && temp.get(cur).low <= h){
                l = temp.get(cur).low;
                if(temp.get(cur).high < h) h = temp.get(cur).high;
            }else{
                l = temp.get(cur).low;
                h = temp.get(cur).high;
                ans++;
            }
            cur++;
        }

        bw.write(ans + "\n");
        bw.flush();
    }
}

/*
3
1 14
1 20
1 32
->  1

3
-15 5
-10 36
27 44
-> 2

3
-15 5
-10 36
40 44
-> 2

3
1 2
3 4
5 6
-> 3

 */