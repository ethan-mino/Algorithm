package swea;

import sun.applet.Main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

class Pos6{
    int x, y;
    Pos6(int x, int y){
        this.x = x; this.y = y;
    }
}

class BC{
    Pos6 pos;
    int c, p;
    BC(int x, int y, int c, int p){
        this.pos = new Pos6(x, y);
        this.c = c; this.p = p;
    }
}

public class SWEA5644 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int []dx = {0, -1, 0, 1, 0};
    static int []dy = {0, 0, 1, 0, -1};

    static int dist(Pos6 p1, Pos6 p2){
        return Math.abs(p1.x - p2.x) + Math.abs(p1.y - p2.y);
    }

    public static void main(String[] args) throws Exception{
        int t = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= t; tc++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());

            int [][] move = new int[2][m];
            BC []bc = new BC[a];

            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < m; i++) move[0][i] = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < m; i++) move[1][i] = Integer.parseInt(st.nextToken());

            for(int i = 0; i < a; i++){
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                int p = Integer.parseInt(st.nextToken());
                bc[i] = new BC(y - 1, x - 1, c, p);
            }

            int ans = 0;
            Pos6 p1 = new Pos6(0, 0);
            Pos6 p2 = new Pos6(9, 9);
            for(int i = 0; i <= m; i++){
                List<BC> avail1 = new LinkedList<>();
                List<BC> avail2 = new LinkedList<>();

                for(int j = 0; j < a; j++){
                    int d1 = dist(p1, bc[j].pos);
                    int d2 = dist(p2, bc[j].pos);
                    if(d1 <= bc[j].c) avail1.add(bc[j]);
                    if(d2 <= bc[j].c) avail2.add(bc[j]);
                }

                Collections.sort(avail1, (b1, b2)-> b2.p - b1.p);
                Collections.sort(avail2, (b1, b2)-> b2.p - b1.p);

                if(!avail1.isEmpty() && !avail2.isEmpty()){
                    if(avail1.get(0).pos.x == avail2.get(0).pos.x
                    && avail1.get(0).pos.y == avail2.get(0).pos.y){
                        int maxPower = Integer.MIN_VALUE;
                        maxPower = Math.max(maxPower, avail1.get(0).p);
                        maxPower = Math.max(maxPower, avail2.get(0).p);
                        if(avail1.size() > 1){
                            maxPower = Math.max(maxPower, avail1.get(1).p + avail2.get(0).p);
                        }else if(avail2.size() > 1){
                            maxPower = Math.max(maxPower, avail1.get(0).p + avail2.get(1).p);
                        }
                        //System.out.println(maxPower);
                        ans += maxPower;
                    }else{
                        ans += avail1.get(0).p;
                        ans += avail2.get(0).p;
                    }
                }else if(!avail1.isEmpty()){
                    ans += avail1.get(0).p;
                }else if(!avail2.isEmpty()){
                    ans += avail2.get(0).p;
                }

                if(i == m) break;
                p1 = new Pos6(p1.x + dx[move[0][i]], p1.y + dy[move[0][i]]);
                p2 = new Pos6(p2.x + dx[move[1][i]], p2.y + dy[move[1][i]]);
                //System.out.println("p1 : " + p1.x + " " + p1.y + "\n");
                //System.out.println("p2 : " + p2.x + " " + p2.y + "\n");
            }

            bw.write("#" + tc + " " + ans + "\n");;
            bw.flush();
        }
    }
}

/*
1
20 3
2 2 3 2 2 2 2 3 3 4 4 3 2 2 3 3 3 2 2 3
4 4 1 4 4 1 4 4 1 1 1 4 1 4 3 3 3 3 3 3
4 4 1 100
7 10 3 40
6 3 2 70

1
1 1
0
0
1 1 1 100
 */