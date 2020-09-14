### 문제

[링크](https://codeforces.com/contest/1298/problem/E)

모든 사람의 스킬(정수 값)과 quarrel(다툼)인 쌍들이 주어질 때,

각 사람마다 자신이 멘토가 될 수 있는 수를 출력하다.

멘토가 되는 조건 : 자신의 스킬이 다른 사람보다 높아야 하고 quarrel 이 아니어야 함.

입력 크기 : 사람 수 n, 2 <= n <= 200,000 (링크 참고)


### 방법

1. 점수 기준으로 해당 점수보다 작은 점수들의 개수를 모두 찾는다 -> map 을 사용함

2. quarrel 인 경우, 어차피 자기보다 값이 큰 쪽에 대해서는 mentor 가 될 수 없으니 
자기가 더 큰 값인 경우만 카운트한다.

3. 1 과 2 를 이용하여 적절히 산수.