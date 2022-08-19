package Baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;

class Node implements Comparable<Node>{
    int v, sign;
    Node(int v, int sign){
        this.v = v; this.sign = sign;
    }

    @Override
    public int compareTo(Node o) {
        if(this.v == o.v){
            return this.sign - o.sign;
        }else return this.v - o.v;
    }
}

public class BOJ11286 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n;

    public static void main(String[] args) throws Exception{
        n = Integer.parseInt(br.readLine());

        PriorityQueue<Node> q = new PriorityQueue<>();
        for(int i = 0; i < n; i++){
            int op = Integer.parseInt(br.readLine());
            if(op == 0){    // 절대값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거
                if(q.size() != 0){
                    Node node = q.peek(); q.remove();
                    //System.out.println(((e.sign == 1) ? e.v : e.v * -1) + " "));
                    bw.write(((node.sign == 1) ? node.v : node.v * -1) + "\n");
                }else{
                    bw.write("0" + "\n");
                }
            }else { // x라는 값을 넣는 연산
                Node e = new Node(Math.abs(op), (op >= 0) ? 1 : 0);
                q.add(e);
            }

            System.out.println("size : " + q.size());
        }
        bw.flush();
    }
}
