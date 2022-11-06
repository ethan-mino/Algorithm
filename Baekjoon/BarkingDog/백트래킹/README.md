# 백트래킹
## 백트래킹이란?
    1. 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하다가, 가능성이 없다고 판단되면, 되돌아가서 다시 해를 찾아가는 기법
    2. 조합, 순열, 부분집합도 가지치기가 없는 백트래킹이라고 할 수 있습니다.
    3. 백트래킹을 이용하여, 완전탐색을 수행할 수 있고, 가지치기를 통해 최적화가 가능합니다.

백트래킹은 크게 두 부분으로 구분할 수 있습니다.

    void back(int depth, int m){
        if(depth == m){
            // 1. 선택한 원소로 기반으로 결과를 계산하는 부분
        }else{
            // 2. 원소를 선택하는 부분
        }
    }

## 꿀팁
재귀 함수는 함수를 명확히 정의하는 것이 좋습니다.   
함수를 명확하게 정의하면, 나를 이용하여 나를 정의하는 것이 명확해집니다.

예를 들어 아래와 같은 함수는 m - cnt개를 선택하는 모든 경우의 수를 탐색하는 함수로 정의할 수 있습니다.  
back 함수의 전체적인 틀은 아래와 같습니다.

	1. m개를 모두 선택한 경우
		1-1. 선택한 원소들을 기반으로 결과를 계산
	2. m개를 선택하지 않은 경우
		2-1. 원소를 하나 선택
		2-2. 남은 원소를 선택하는 역할을 back(cnt + 1, m) 호출에 위임 
		2-3. 즉, m - (cnt + 1)개를 선택하는 모든 경우의 수를 탐색하는 함수에게 남은 원소의 선택을 위임

함수 구현은 아래와 같습니다.

    /*
        * @param m 선택해야 할 원소의 총 개수
        * m은 반드시 backtracking 함수의 인자로 전달될 필요는 없습니다, static 변수로 두어도 됩니다
        * @param cnt 현재까지 선택한 원소의 개수
        * cnt는 main 함수 호출 시 0또는 1로 시작할 수 있습니다. 
        * 다만, 주로 원소가 배열로 주어지기 때문에, 저는 배열의 인덱스와 맞추기 위해 0을 사용합니다.
    */

    void back(int cnt, int m){
        if(cnt == m){
            // 1. 선택한 원소로 기반으로 결과를 계산하는 부분
        }else{
            // 2. 원소를 선택하는 부분
            for(int cur = XXX; cur < XXX ; cur++){
                // 원소를 선택
                back(cnt + 1, m); // cnt + 1부터 총 m개를 선택하는 함수를 호출
                // 원소의 선택을 해제
            }
        }
    }

	public static void main(String[] args) {
        back(0, 10); // (10 - 0)개를 선택하는 모든 경우의 수를 탐색
	}

## 원소 선택
원소를 선택하는 부분은 두 가지 유형으로 구분될 수 있습니다.

    1. depth가 기준이 되는 유형
    2. 원소가 기준이 되는 유형

### depth가 기준이 되는 유형
depth란 단계라고 생각하시면 됩니다.  
depth가 기준이 되는 유형은 현재 단계에서 원소를 선택하고, 다음 단계에게 나머지 역할을 위임시켜 주면 됩니다.    
순열/중복 순열/조합이 이 유형에 해당됩니다.

### 순열 
순열은 순서에 따라 결과가 달라질 수 있는 문제에 적용시킬 수 있습니다.  

    static boolean [] isSelected = new boolean[10];
    static int [] selected = new int[10];

    static void back(int depth, int m){
        if(depth == m){
            // 1. 선택한 원소로 기반으로 결과를 계산하는 부분
        }else{
            // 2. 원소를 선택하는 부분
            for(int curIdx = 0; curIdx < n; curIdx++){  // curIdx는 n개의 원소 중에서 선택할 원소의 idx
                if(!isSelected[curIdx]){ // curIdx번째 원소가 선택되지 않았다면
                    isSelected[curIdx] = true; // curIdx번째 원소를 선택 처리
                    selected[depth] = cur;  // depth 단계에서 선택한 값 저장
                    back(idx + 1, maxNum); 
                    isSelected[curIdx] = false;  // curIdx번째 원소를 선택 해제 처리
                }
            }
        }
    }

### 중복 순열
중복 순열은 순열과 같지만, 같은 원소를 중복 선택 가능한 경우 문제에 적용시킬 수 있습니다.

    static void back(int depth){
        if(depth == n){
            // 1. 선택한 원소로 기반으로 결과를 계산하는 부분
        }else{
            for(int cur = 0; cur < n; cur++){
                // 2. 원소를 선택하는 부분
                selected[depth] = cur;  // depth 단계에서 선택한 값 저장
                back(depth + 1, maxNum); 
            }
        }
    }

### 조합
조합은 순서는 결과에 영향을 주지 않고, 어떤 원소를 선택했냐가 중요한 경우 문제에 적용시킬 수 있습니다.

    static int [] selected = new int[10];
    static void back(int depth, int pre){
        if(depth == m){
            // 1. 선택한 원소로 기반으로 결과를 계산하는 부분
        }else{
            for(int cur = pre + 1; cur < n; cur++){ // * cur의 시작점이 pre + 1
                // 2. 원소를 선택하는 부분
                selected[depth] = cur;  // depth 단계에서 선택한 값 저장
                back(depth + 1, cur); 
            }
        }
    }


### 원소가 기준이 되는 유형
즉, 현재 원소를 몇개 선택할 것이냐입니다.  
부분 집합, 중복 조합이 이 유형에 해당됩니다.

    static int [] selectCnt = new int[10];
    /*
        * @param maxNum idx 원소의 최대 선택 가능 개수
        * 부분집합의 경우 maxNum은 1이 됩니다.
    */
    static void back(int idx, int maxNum, int n){
        if(idx == n){
            // 1. 선택한 원소로 기반으로 결과를 계산하는 부분
        }else{
            // 2. 원소를 선택하는 부분
            for(int num = 0; num < maxNum; num++){  // 해당 원소를 선택하지 않을 수 있기 때문에 0부터 시작
                selectCnt[idx] = num;   // idx 번째 원소를 num개 선택
                back(idx + 1, maxNum); 
            }
        }
    }

	public static void main(String[] args) {
        back(0, 10, 20); // 20개의 원소 중에서 0번째 원소부터 각각의 원소를 최대 10개 선택
	}

## 결과 계산
결과 계산은 크게 두 가지 유형으로 구분할 수 있습니다.

    1. 첫 번째 유형
        - 반드시 현재 경우의 수를 완성한 다음, 해당 경우의 수에 대한 결과를 계산해야하는 경우
        - ex. 캐슬 디펜스 

    2. 두 번째 유형
        - 경우의 수를 완성해가면서, 결과를 계산하며 depth를 진행시킬 수 있는 경우
        - ex. 해밀턴 순환 회로, 배열 돌리기

먼저, 첫 번째 유형에 대해 설명하겠습니다.

캐슬 디펜스의 경우, 3명의 궁수를 모두 격자판에 배치시킨 후, 
해당 배치에 대해 제거 가능한 적의 수를 계산해야합니다.  

즉, 결과를 누적시키며 백트래킹을 진행할 수 없습니다.  
이 경우 주어진 n개 중에서 m개를 모두 선택했을 때, 결과를 계산하면 됩니다.  
이 유형의 경우 아래와 같은 코드 작성이 가능합니다.

    static void backtracking(int depth, int m){
        if(depth == m){    
            // depth가 0부터 시작했다면, depth == m일 때 0 ~ m - 1까지 m개의 원소를 선택한 것이므로, 
            // 이 때 결과를 계산하면 됩니다.

            game(); // 선택한 원소를 기반으로, 결과를 계산
        }else{  // 아직 m개를 선택하지 않은 경우
            // 선택 가능한 원소들 중에서 하나를 선택
            backtracking(depth + 1, m);
        }
    }

	public static void main(String[] args) {
        back(0, 3);
	}

두 번째 유형은 원소를 선택하면서 결과를 계산할 수 있기 때문에, 원소를 모두 선택한 다음 결과를 계산하지 않고, 원소를 하나씩 선택할 때마다, 현재까지의 결과를 계산하는 것입니다.   
이 경우 계산 중복을 피할 수 있기 때문에 시간을 줄일 수 있습니다.

두번째 유형은 다시 두 가지 유형으로 구분할 수 있습니다.

    1. m개를 반드시 선택해야 하는 경우
    2. 최대 m개를 선택할 수 있는 경우

### m개를 반드시 선택해야 하는 경우
    static int minDist = Integer.MAX_VALUE;

    /*
        * @param preDist 시작 노드부터 이전 노드까지의 거리 
    */

    static void backtracking(int depth, int m, int preDist){
        if(depth == m){    
            // depth가 0부터 시작했다면, depth == m일 때 0 ~ m - 1까지 m개의 원소를 선택한 것이므로, 
            // 이 때 결과를 계산하면 됩니다.

            minDist = Math.min(minDist, preDist); // * 핵심
        }else{  // 아직 m개를 선택하지 않은 경우
            // 선택 가능한 원소들 중에서 하나를 선택

            for(int cur = XXX; cur < XXX ; cur++){
                int curDist = 이전 노드와 현재 노드간의 거리
                backtracking(depth + 1, m, preDist + curDist);
            }
        }
    }

    public static void main(String[] args) {
		back(0, 3);
        System.out.println(minDist);    // 최종 출력 변수를 출력
	}

### 최대 m개를 선택할 수 있는 경우 
이 경우, 최대 m개를 선택할 수 있을 뿐, 반드시 m개를 선택해야 하는 것은 아닙니다.  
따라서, 아래와 같이 함수 작성이 가능합니다.

    static void backtracking(int depth, int m, int preDist){
        // 반드시 m개를 선택해야 하는 것은 아니므로, 원소를 선택할 때마다 최종 출력 변수의 값을 업데이트함
        minDist = Math.min(minDist, preDist); // ** 핵심
        
        if(depth < m){  // 아직 m개를 선택하지 않은 경우
            // 선택 가능한 원소들 중에서 하나를 선택

            for(int cur = XXX; cur < XXX ; cur++){
                int curDist = 이전 노드와 현재 노드간의 거리
                backtracking(depth + 1, m, preDist + curDist);
            }
        }
    }

## 백트래킹 최적화
백트래킹에서 최적화는 일명 가지치기라고 할 수 있습니다.  
대표적으로 최소 값을 구할 때, 이미 앞서 계산된 최소 값보다 현재 계산된 값이 더 클 때 더이상 진행하지 않는 방법이 있습니다.

    static int minDist = Integer.MAX_VALUE;

    static void backtracking(int depth, int m, int preDist){
        if(depth == m){    
            // depth가 0부터 시작했다면, depth == m일 때 0 ~ m - 1까지 m개의 원소를 선택한 것이므로, 
            // 이 때 결과를 계산하면 됩니다.

            minDist = Math.min(minDist, curDist);
        }else if(preDist < minDist){ // ** 핵심 
            // 아직 m개를 선택하지 않은 경우
            // 선택 가능한 원소들 중에서 하나를 선택

            for(int cur = XXX; cur < XXX ; cur++){
                int curDist = 이전 노드와 현재 노드간의 거리

                // ** 아래와 같은 방식도 가능
                if(preDist + curDist < minDist)
                    backtracking(depth + 1, m, preDist + curDist);
            }
        }
    }

## 풀이 과정

    1. 모든 경우의 수에 대해 시도해보아야 결과를 알 수 있겠다라는 생각이 들면 일단 백트래킹을 후보로 둠
    2. n의 크기를 살펴봄
        2-1. 백트래킹의 경우 보통 순서를 고려해야 한다면 11이하, 고려하지 않아도 된다면 25이하의 n이 주어짐
	2-2. n이 그 이상이지만, 완탐이 아닌 이상 절대 알 수 없을 것 같다면, 가지치기를 고려
        2-3. n이 50 이상인 경우, 백트래킹일 가능성이 낮음 
	2-4. 특히, n이 100,000이상인 경우, DP/그리디/이분탐색/그래프를 고려
    3. 백트래킹을 할 수 있다면, 위의 백트래킹 유형 중 어떤 유형인지 파악
    4. 유형 파악이 된 이후에는, 가지치기를 통해 최적화가 가능한지 파악
    5. 솔루션 작성 이후에는, 어떠한 케이스가 있을 수 있는지, 정답이 잘 나오는지 파악하기 위해 간단한 테스트케이스부터 복잡한 테스트 케이스까지 직접 만들어보고 입력해서 솔루션을 검증

## ⚠ 주의할 점
최종 출력 변수의 값을 업데이트 할 수 있는 경우의 수가 존재하지 않는 경우,   
Integer.MAX_VALUE 또는 Integer.MIN_VALUE와 같은 쓰레기 값이 출력될 수 있습니다.  
따라서, 최종 출력 변수의 값을 업데이트 할 수 있는 경우의 수가 존재하는지, 이러한 경우, 출력해야 될 값을 문제에서 제시하였는지 등을 확인해야합니다.
