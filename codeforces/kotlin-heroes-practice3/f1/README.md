### 문제

[링크](https://codeforces.com/contest/1298/problem/F1)

1~n 사이의 정수가 중복없이 한 번만 나오는 배열이 주어짐 (순서는 랜덤)

그리고 m 이 주어지는데,

주어진 배열의 [l, r] 구간의 median 이 m 인 모든 경우의 수 구하기

참고: 구간 크기가 짝수이면 중앙의 왼쪽 값이 median 이다.


입력 크기 : 배열 크기 n, 1 <= n <= 200,000


### 풀이

m 이 한 번만 나타나므로, m 의 index 기준으로 왼쪽, 오른쪽에 대해 각각

m 보다 크거나 작은 녀석들의 개수를 구한다.

양쪽으로 해당 개수 합이 서로 0 또는 1 이 되는 경우를 찾으면 된다.

