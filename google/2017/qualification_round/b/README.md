(Problem B. Tidy Numbers)[https://code.google.com/codejam/contest/3264486/dashboard#s=p1]

주어진 입력 N 이하의 정수 중 최대 tidy number 구하기<br>
tidy number 란 구성하는숫자가 non-decreasing 하게 배열된 수를 말함

```
Input
4
132
1000
7
111111111111111110

Output 
Case #1: 129
Case #2: 999
Case #3: 7
Case #4: 99999999999999999
```

<br><br><br><br>

왼쪽부터 검사하여 숫자가 감소되는 지점(i)을 찾고<br>
i 번째부터, 해당 자리 값을 1 감소하여 tidy number 조건을 만족할때까지 i 감소하여 반복<br>
최종 i 를 찾은 후 나머지 자리 값을 모두 9로 채움<br>
첫 번째 자리가 0이 될 수 있음을 유의해야함
