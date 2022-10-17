// Created by 길민호 on 2022/10/17.

#include <bits/stdc++.h>

using namespace std;

#define KEY first
#define USE_COUNT second

map<string, int> cache;

void use(string key){
    for(auto elem : cache){
        cache[elem.KEY]++;
    }

    cache[key] = 0;
}

void upper(string& str){
    for(int i = 0; i < str.size(); i++){
        str[i] = toupper(str[i]);
    }
}

int solution(int cacheSize, vector<string> cities) {
    int totalTime = 0;

    for(auto city : cities){
        upper(city);

        if(cache.find(city) != cache.end()){   // hit
            totalTime++;
            use(city);
        }else{  // miss한 경우
            totalTime += 5;

            if(cacheSize > 0){
                if(cache.size() < cacheSize){   // 캐시에 비어있는 공간이 있는 경우
                    use(city);
                }else{
                    string LRUKey = "";
                    int maxUseCnt = INT_MIN; // 가장 오래전에 사용한 것
                    for(auto elem : cache){
                        if(maxUseCnt < elem.USE_COUNT){
                            LRUKey = elem.KEY;
                            maxUseCnt = elem.USE_COUNT;
                        }
                    }

                    cache.erase(LRUKey);
                    use(city);
                }
            }
        }
    }

    return totalTime;
}