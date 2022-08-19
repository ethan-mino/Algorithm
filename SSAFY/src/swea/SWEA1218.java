import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class SWEA1218 {
    static BufferedReader br = new BufferedReader(new BufferedReader(new InputStreamReader(System.in)));
    static BufferedWriter bw = new BufferedWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static final int CASE = 10;

    public static void main(String[] args) throws Exception{
        for(int tc = 1; tc <= CASE; tc++){
            Stack<Character> s = new Stack<>();

            br.readLine();
            String str = br.readLine();
            int valid = 1;
            for(int i = 0; i < str.length(); i++){
                char c = str.charAt(i);
                switch (c){
                    case '<' :
                    case '[' :
                    case '{' :
                    case '(' :
                        s.push(c);
                        break;
                    case '>' :
                    case ']' :
                    case '}' :
                    case ')' :
                        if(!s.empty()){
                            char top = s.pop();
                            if(c == ']' && top != '['
                                || c == ')' && top != '('
                                || c == '}' && top != '{'
                                || c == '>' && top != '<'){
                                valid = 0;
                            }
                        }else{
                            valid = 0;
                        }
                        break;
                }
            }
            //System.out.println(s.size());
            if(!s.empty()) valid = 0;
            bw.write("#" +  tc + " " + valid + "\n");
            bw.flush();
        }
    }
}

/*
3
())
 */