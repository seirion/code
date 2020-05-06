IDE 에서 파일 입력을 받고 싶을 때, 이런 식으로도 하지만
```
./a.out < input.txt
```

이렇게 실행 명령을 줄 수 없을 때, 코드에서 파일을 표준 입력으로 돌릴 수 있다.
```cpp
int main() {
  std::ifstream in("ABSOLUTE_PATH");
  std::cin.rdbuf(in.rdbuf());
 
 
  int input << cin; // 표준 입력으로 받을 수 있음
}
```
