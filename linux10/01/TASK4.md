# #ifdef ~ #endif 전처리 지시자

## 1. #ifdef ~ #endif 지시자를 사용하는 이유

C언어에서 `#ifdef`와 `#endif`는 조건부 컴파일을 수행하기 위한 전처리 지시자이다.

조건부 컴파일이란 프로그램을 컴파일하기 전에 특정 조건에 따라 소스코드의 일부를 컴파일 대상에 포함하거나 제외하는 기능이다.

`#ifdef`는 특정 매크로가 정의되어 있는지 검사하고, 정의되어 있을 경우에만 해당 코드를 컴파일하도록 한다.

### 1.1 각 지시자의 역할

1. `#ifdef`
   - `if defined`의 의미를 가진다.
   - 특정 매크로가 정의되어 있는지 확인한다.
   - 매크로가 정의되어 있으면 해당 코드가 컴파일 대상에 포함된다.
   - 정의되어 있지 않으면 해당 코드가 컴파일 대상에서 제외된다.

2. `#endif`
   - 조건부 컴파일 영역의 끝을 나타낸다.
   - `#ifdef`로 시작한 조건부 컴파일을 종료한다.

3. `#else`
   - 매크로가 정의되지 않았을 때 사용할 코드를 지정한다.
   - 필요하지 않으면 생략할 수 있다.

### 1.2 사용하는 이유

① 디버깅 기능을 선택적으로 활성화할 수 있다.

② 특정 하드웨어나 운영체제에서만 필요한 코드를 컴파일할 수 있다.

③ 프로그램의 테스트 코드와 일반 실행 코드를 구분할 수 있다.

④ 불필요한 코드가 최종 실행파일에 포함되지 않도록 할 수 있다.

⑤ 동일한 소스코드에서 여러 컴파일 설정을 관리할 수 있다.

특히 임베디드 시스템에서는 하드웨어 종류나 개발 환경에 따라 서로 다른 코드를 컴파일해야 하는 경우가 많으므로 유용하게 사용된다.

---

## 2. #ifdef ~ #endif 사용 예제

### 2.1 참고 자료

참고 사이트: cppreference - C언어 조건부 컴파일

https://en.cppreference.com/c/preprocessor/conditional

위 사이트에서 설명하는 `#ifdef`의 조건부 컴파일 문법을 참고하여 디버그 모드 활성화 예제를 작성하였다.

### 2.2 예제 소스코드

```c
#include <stdio.h>

#define DEBUG

int main(void)
{
    printf("Program started.\n");

#ifdef DEBUG
    printf("Debug mode is enabled.\n");
    printf("Debug: value = %d\n", 100);
#endif

    printf("Program finished.\n");

    return 0;
}
```

### 2.3 컴파일 및 실행

GCC 컴파일러를 사용하여 프로그램을 컴파일하였다.

컴파일 명령어:

    gcc -std=c11 -Wall -Wextra ifdef_example.c -o ifdef_example

실행 결과:

    Program started.
    Debug mode is enabled.
    Debug: value = 100
    Program finished.

`DEBUG` 매크로가 정의되어 있으므로 `#ifdef DEBUG`와 `#endif` 사이에 있는 코드가 컴파일되어 정상적으로 출력된다.

---

## 3. 소스코드 상세 설명

### 3.1 헤더파일 포함

```c
#include <stdio.h>
```

- 표준 입출력 헤더파일을 포함한다.
- 화면에 문자열을 출력하기 위한 `printf()` 함수를 사용할 수 있도록 한다.

### 3.2 매크로 정의

```c
#define DEBUG
```

- `#define`은 매크로를 정의하는 전처리 지시자이다.
- `DEBUG`라는 매크로를 정의한다.
- 여기서는 숫자나 문자열을 지정하지 않고 매크로 이름만 정의하였다.
- `#ifdef`는 매크로의 값이 아니라 정의 여부를 확인하므로 이와 같이 사용할 수 있다.

### 3.3 프로그램 시작 출력

```c
printf("Program started.\n");
```

- 프로그램이 시작되었다는 메시지를 출력한다.
- `\n`은 줄바꿈을 의미한다.
- 조건부 컴파일 영역 밖에 있으므로 `DEBUG`의 정의 여부와 관계없이 컴파일된다.

### 3.4 조건부 컴파일 시작

```c
#ifdef DEBUG
```

- `DEBUG`라는 매크로가 정의되어 있는지 확인한다.
- 매크로가 정의되어 있으면 이후 코드를 컴파일 대상에 포함한다.
- 정의되어 있지 않으면 `#endif`까지의 코드를 제외한다.

현재 프로그램에서는 `#define DEBUG`가 존재하므로 조건이 참이다.

### 3.5 디버그 메시지 출력

```c
printf("Debug mode is enabled.\n");
printf("Debug: value = %d\n", 100);
```

- 첫 번째 `printf()` 함수는 디버그 모드가 활성화되었다는 메시지를 출력한다.
- 두 번째 `printf()` 함수는 정수 100을 출력한다.
- `%d`는 정수를 출력하는 서식 지정자이다.
- 두 문장은 `#ifdef DEBUG` 영역 내부에 있으므로 `DEBUG` 매크로가 정의된 경우에만 컴파일된다.

### 3.6 조건부 컴파일 종료

```c
#endif
```

- `#ifdef`로 시작한 조건부 컴파일 영역을 종료한다.
- 이후 코드는 다시 일반적인 컴파일 대상이 된다.

### 3.7 프로그램 종료 메시지

```c
printf("Program finished.\n");
```

- 프로그램이 종료된다는 메시지를 출력한다.
- 조건부 컴파일 영역 밖에 있으므로 `DEBUG` 매크로의 정의 여부에 영향을 받지 않는다.

### 3.8 프로그램 종료

```c
return 0;
```

- `main()` 함수의 실행을 종료한다.
- 정상 종료를 나타내는 값 0을 운영체제에 반환한다.

---

## 4. DEBUG 매크로를 제거한 경우

다음과 같이 `#define DEBUG`를 주석 처리하면 결과가 달라진다.

### 4.1 수정한 소스코드

```c
#include <stdio.h>

// #define DEBUG

int main(void)
{
    printf("Program started.\n");

#ifdef DEBUG
    printf("Debug mode is enabled.\n");
    printf("Debug: value = %d\n", 100);
#endif

    printf("Program finished.\n");

    return 0;
}
```

### 4.2 실행 결과

    Program started.
    Program finished.

### 4.3 결과 분석

`#define DEBUG`가 주석 처리되었으므로 `DEBUG` 매크로는 정의되지 않는다.

따라서 전처리기는 `#ifdef DEBUG` 조건을 거짓으로 판단한다.

그 결과 다음 두 문장이 컴파일 대상에서 제외된다.

```c
printf("Debug mode is enabled.\n");
printf("Debug: value = %d\n", 100);
```

프로그램 시작 및 종료 메시지는 조건부 컴파일 영역 밖에 있으므로 정상적으로 출력된다.

---

## 5. #ifdef와 #if의 차이점

| 구분 | #ifdef | #if |
|------|--------|-----|
| 검사 대상 | 매크로 정의 여부 | 전처리 상수 표현식의 값 |
| 주요 목적 | 특정 기능의 포함 여부 결정 | 조건식에 따른 코드 선택 |
| 사용 예제 | #ifdef DEBUG | #if MODE == 1 |
| 검사 방법 | 매크로가 정의되었는지 확인 | 조건식이 0인지 아닌지 확인 |
| 종료 지시자 | #endif | #endif |

예를 들어 다음과 같이 작성할 수 있다.

```c
#define DEBUG 0

#ifdef DEBUG
    printf("Debug mode\n");
#endif
```

이 경우 `DEBUG`의 값은 0이지만 매크로 자체가 정의되어 있으므로 해당 출력문이 컴파일된다.

반면 다음과 같은 코드는 다르다.

```c
#define DEBUG 0

#if DEBUG
    printf("Debug mode\n");
#endif
```

`#if DEBUG`는 매크로의 값을 검사하므로 값이 0이면 조건이 거짓이다.

따라서 출력문은 컴파일 대상에서 제외된다.

즉, `#ifdef`는 매크로의 정의 여부를 확인하고, `#if`는 조건식의 값을 검사한다는 차이가 있다.

---

## 6. 결론

`#ifdef ~ #endif`는 특정 매크로가 정의되어 있는지 확인하여 필요한 코드만 컴파일하는 전처리 지시자이다.

이번 예제에서는 `DEBUG` 매크로를 정의했을 때 디버그 메시지가 출력되었으며, 해당 매크로를 제거했을 때 디버그 메시지가 출력되지 않는 것을 확인하였다.

따라서 `#ifdef`는 프로그램 개발 과정에서 디버깅 기능을 활성화하거나 비활성화할 때 유용하다.

또한 임베디드 시스템에서 하드웨어 환경에 따라 필요한 코드만 선택적으로 컴파일하는 데에도 활용할 수 있다.
