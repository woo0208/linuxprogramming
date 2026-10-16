# #if ~ #elif ~ #endif 전처리 지시자

## 1. #if ~ #elif ~ #endif 지시자를 사용하는 이유

C언어에서 `#if`, `#elif`, `#endif`는 조건부 컴파일을 수행하기 위한 전처리 지시자이다.

조건부 컴파일이란 프로그램을 컴파일하기 전에 특정 조건을 검사하고, 조건에 맞는 소스코드만 선택하여 컴파일하는 기능이다.

### 1.1 각 지시자의 역할

1. `#if`
   - 조건부 컴파일의 시작을 나타낸다.
   - 지정한 조건이 참이면 해당 코드가 컴파일 대상에 포함된다.
   - 조건이 거짓이면 해당 코드를 제외하고 다음 조건을 검사한다.

2. `#elif`
   - `else if`와 비슷한 역할을 한다.
   - 앞의 조건이 거짓일 때 새로운 조건을 검사한다.
   - 여러 조건을 순서대로 검사할 때 사용한다.

3. `#else`
   - 앞의 모든 조건이 거짓일 때 실행할 코드를 지정한다.
   - 생략할 수 있다.

4. `#endif`
   - 조건부 컴파일 영역의 끝을 나타낸다.
   - `#if`로 시작한 조건부 컴파일을 종료한다.

### 1.2 사용하는 이유

① 컴파일 환경에 따라 서로 다른 코드를 사용할 수 있다.

② 디버그 모드와 일반 실행 모드를 구분할 수 있다.

③ 특정 하드웨어나 운영체제에 필요한 코드만 컴파일할 수 있다.

④ 불필요한 코드를 컴파일 대상에서 제외할 수 있다.

⑤ 하나의 소스코드로 여러 설정의 프로그램을 관리할 수 있다.

일반적인 `if ~ else if ~ else` 문은 프로그램 실행 중에 조건을 검사하지만, `#if ~ #elif ~ #endif`는 컴파일 이전의 전처리 단계에서 조건을 검사한다는 차이가 있다.

---

## 2. #if ~ #elif ~ #endif 사용 예제

### 2.1 참고 자료

참고 사이트: cppreference - C언어 조건부 컴파일

https://en.cppreference.com/c/preprocessor/conditional

위 사이트에서 설명하는 조건부 컴파일 문법을 참고하여 프로그램의 실행 모드를 선택하는 예제를 작성하였다.

### 2.2 예제 소스코드

```c
#include <stdio.h>

#define MODE 2

int main(void)
{
#if MODE == 1
    printf("Mode 1: Debug mode\n");

#elif MODE == 2
    printf("Mode 2: Normal mode\n");

#elif MODE == 3
    printf("Mode 3: Power saving mode\n");

#else
    printf("Unknown mode\n");

#endif

    return 0;
}
