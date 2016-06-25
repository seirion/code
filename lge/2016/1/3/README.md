### 짝수 단어

영어 소문자로 이루어 진 단어에서 <br>
구간 [a, b] 안에 모든 알파벳이 짝수개 있는 경우가 몇 가지 존재하는 지 찾는 문제 <br>
<br>
예를 들어, ```mississippi``` 안에는 다음과 같은 모두 12 개의 경우가 존재한다.

```ippi, issi, issi, issipp, ississ, ississippi, pp, ss, ss, ssippi, ssissi, ssissipp```

<br>

입력 양식 : 테스트 케이스 T 가 주어지고, 그 다음 T 줄만큼 영어 소문자로 구성된 문자열이 주어짐<br>

입력에 따라 문자열의 길이는 다음과 같다.
```
set 1 : 100 < |s|
set 2 : 500 < |s|
set 3 : 10,000 < |s|
set 4 : 50,000 < |s|
```

입력 예
```
2
appall
mississippi
```

출력 예
```
4
12
```
