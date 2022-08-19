package swea;

public class 거스름돈_길민호 {
    static int ans = Integer.MAX_VALUE;
    static int[] coins = {500, 400, 100, 50, 10};
    static int target = 800;
    static void back(int th, int sum){
        if(sum == target) ans = Math.min(ans, th);

        for(int i = 0; i < 4; i++){
            if(sum + coins[i] <= target){
                back(th + 1, sum + coins[i]);
            }
        }
    }

    public static void main(String[] args) {
        back(0, 0);
        System.out.println(ans);
    }
}
