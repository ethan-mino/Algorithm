package swea;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class P_7272
{
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        int[] group = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

        for(int i = 1; i <= t; i++) {
            String same = "SAME", diff = "DIFF";
            String result = same;

            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            String str1 = st.nextToken();
            String str2 = st.nextToken();

            if(str1.length() != str2.length()) result = diff;
            else {
                for(int j = 0; j < str1.length(); j++) {
                    if(group[str1.charAt(j) - 65] != group[str2.charAt(j) - 65]) {
                        result = diff;
                    }
                }
            }

            System.out.println("#" + i + " " + result);
        }
    }
}