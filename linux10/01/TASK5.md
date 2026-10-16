# #ifndef ~ #endif 전처리 지시자

## 1. #ifndef ~ #endif 지시자를 사용하는 이유

C언어에서 `#ifndef`와 `#endif`는 조건부 컴파일을 수행하기 위한 전처리 지시자이다.

`#ifndef`는 "if not defined"의 약자로, 특정 매크로가 정의되어 있지 않은 경우에만 해당 코드를 컴파일하도록 하는 기능이다.

즉, `#ifdef`가 매크로가 정의되어 있는지 확인하는 지시자라면, `#ifndef`는 매크로가 정의되어 있지 않은지 확인하는 지시자이다.

### 1.1 각 지시자의 역할

1. `#ifndef`
   - 특정 매크로가 정의되어 있지 않은지 검사한다.
   - 매크로가 정의되어 있지 않으면 해당 코드가 컴파일 대상에 포함된다.
   - 매크로가 이미 정의되어 있으면 해당 코드가 컴파일 대상에서 제외된다.

2. `#endif`
   - 조건부 컴파일 영역의 끝을 나타낸다.
   - `#ifndef`로 시작한 조건부 컴파일을 종료한다.

3. `#else`
   - `#ifndef` 조건이 거짓일 때 사용할 코드를 지정한다.
   - 필요하지 않으면 생략할 수 있다.

### 1.2 사용하는 이유

① 헤더 파일이 여러 번 포함되어 발생하는 중복 선언 및 정의 문제를 방지할 수 있다.

② 특정 매크로가 정의되지 않았을 경우에만 기본 설정을 적용할 수 있다.

③ 디버깅 및 개발용 코드를 선택적으로 컴파일할 수 있다.

④ 하드웨어나 운영체제의 설정에 따라 필요한 코드만 선택할 수 있다.

⑤ 동일한 소스코드에서 여러 컴파일 환경을 관리할 수 있다.

특히 C언어에서는 헤더 파일이 여러 번 포함되는 것을 방지하기 위해 `#ifndef`를 자주 사용한다.

이러한 방식을 헤더 가드(Header Guard)라고 한다.

---

## 2. #ifndef ~ #endif 사용 예제

### 2.1 참고 자료

참고 사이트: cppreference - C언어 조건부 컴파일

https://en.cppreference.com/c/preprocessor/conditional

위 사이트에서 설명하는 조건부 컴파일 문법을 참고하여 특정 매크로의 정의 여부에 따라 개발용 메시지를 출력하는 예제를 작성하였다.

### 2.2 예제 소스코드

```c
#include <stdio.h>

#ifndef DEBUG
#define DEBUG
#endif

int main(void)
{
#ifndef RELEASE
    printf("Development build.\n");
#endif

    printf("Program finished.\n");

    return 0;
}
```

### 2.3 컴파일 및 실행

GCC 컴파일러를 사용하여 프로그램을 컴파일하였다.

컴파일 명령어:

    gcc -std=c11 -Wall -Wextra ifndef_example.c -o ifndef_example

실행 결과:

    Development build.
    Program finished.

실제 GCC 컴파일 및 실행 결과, 위와 같이 정상적으로 출력되는 것을 확인하였다.

현재 프로그램에서는 `RELEASE` 매크로가 정의되어 있지 않으므로 `#ifndef RELEASE` 조건이 참이 된다.

따라서 개발용 메시지인 `Development build.`가 출력된다.

---

## 3. 소스코드 상세 설명

### 3.1 헤더파일 포함

```c
#include <stdio.h>
```

- 표준 입출력 헤더파일을 포함한다.
- 화면에 문자열을 출력하는 `printf()` 함수를 사용하기 위해 필요하다.

### 3.2 매크로 정의 여부 확인

```c
#ifndef DEBUG
#define DEBUG
#endif
```

- `#ifndef DEBUG`는 `DEBUG` 매크로가 정의되어 있지 않은지 확인한다.
- `DEBUG`가 정의되지 않았다면 `#define DEBUG`를 통해 매크로를 정의한다.
- 이미 정의되어 있다면 `#define DEBUG` 문장은 처리되지 않는다.
- `#endif`는 조건부 컴파일 영역을 종료한다.

이러한 방식을 사용하면 매크로가 정의되지 않았을 때만 기본 설정을 적용할 수 있다.

### 3.3 main 함수

```c
int main(void)
{
```

- C언어 프로그램의 시작 함수이다.
- 프로그램을 실행하면 `main()` 함수 내부의 코드가 수행된다.
- `void`는 함수가 매개변수를 받지 않는다는 의미이다.

### 3.4 RELEASE 매크로 검사

```c
#ifndef RELEASE
    printf("Development build.\n");
#endif
```

- `#ifndef RELEASE`는 `RELEASE` 매크로가 정의되어 있지 않은지 검사한다.
- 현재 소스코드에는 `RELEASE` 매크로가 정의되어 있지 않다.
- 따라서 조건이 참으로 판단된다.
- `printf()` 문장이 컴파일 대상에 포함된다.
- `Development build.`라는 문자열이 화면에 출력된다.

반대로 `RELEASE` 매크로가 정의되어 있으면 해당 출력문은 컴파일 대상에서 제외된다.

### 3.5 프로그램 종료 메시지

```c
printf("Program finished.\n");
```

- 프로그램이 종료된다는 메시지를 출력한다.
- 조건부 컴파일 영역 밖에 있으므로 `RELEASE` 매크로의 정의 여부와 관계없이 컴파일된다.

### 3.6 프로그램 종료

```c
return 0;
```

- `main()` 함수의 실행을 종료한다.
- 정상 종료를 의미하는 값 0을 운영체제에 반환한다.

---

## 4. RELEASE 매크로를 정의한 경우

`RELEASE` 매크로를 정의하면 프로그램의 실행 결과가 달라진다.

### 4.1 컴파일 옵션 변경

소스코드를 수정하지 않고 GCC의 `-D` 옵션을 이용해 매크로를 정의할 수 있다.

컴파일 명령어:

    gcc -std=c11 -Wall -Wextra -DRELEASE ifndef_example.c -o ifndef_example

실행 결과:

    Program finished.

### 4.2 결과 분석

`-DRELEASE` 옵션은 컴파일 과정에서 `RELEASE` 매크로를 정의하는 역할을 한다.

따라서 다음 조건부 컴파일 영역이 제외된다.

```c
#ifndef RELEASE
    printf("Development build.\n");
#endif
```

`RELEASE` 매크로가 이미 정의되어 있으므로 `#ifndef RELEASE` 조건은 거짓이 된다.

그 결과 개발용 메시지인 `Development build.`는 출력되지 않고, `Program finished.`만 출력된다.

실제 GCC 컴파일 및 실행을 통해 두 설정에서 출력 결과가 달라지는 것을 확인하였다.

---

## 5. #ifndef를 이용한 헤더 파일 중복 포함 방지

`#ifndef`는 헤더 파일이 여러 번 포함되는 것을 방지하기 위해 자주 사용된다.

### 5.1 헤더 파일 예제

파일명: example.h

```c
#ifndef EXAMPLE_H
#define EXAMPLE_H

#define MAX_VALUE 100

void print_value(void);

#endif
```

### 5.2 소스 파일 예제

파일명: main.c

```c
#include <stdio.h>
#include "example.h"
#include "example.h"

void print_value(void)
{
    printf("MAX_VALUE = %d\n", MAX_VALUE);
}

int main(void)
{
    print_value();

    return 0;
}
```

### 5.3 실행 결과

    MAX_VALUE = 100

### 5.4 동작 원리

첫 번째로 `example.h`를 포함하면 다음 조건을 검사한다.

```c
#ifndef EXAMPLE_H
```

처음에는 `EXAMPLE_H`가 정의되어 있지 않으므로 조건이 참이다.

따라서 다음 코드가 처리된다.

```c
#define EXAMPLE_H

#define MAX_VALUE 100

void print_value(void);
```

이후 두 번째로 `example.h`를 포함하면 `EXAMPLE_H`가 이미 정의되어 있다.

따라서 `#ifndef EXAMPLE_H` 조건은 거짓이 되고 헤더 파일 내부의 선언과 정의는 다시 처리되지 않는다.

이처럼 `#ifndef`, `#define`, `#endif`를 사용하여 헤더 파일의 중복 포함을 방지하는 방식을 헤더 가드라고 한다.

헤더 가드는 구조체나 typedef 등의 중복 선언으로 인한 컴파일 오류를 예방하는 데 유용하다.

---

## 6. #ifdef와 #ifndef의 차이점

| 구분 | #ifdef | #ifndef |
|------|--------|---------|
| 의미 | if defined | if not defined |
| 검사 조건 | 매크로가 정의되어 있는가? | 매크로가 정의되어 있지 않은가? |
| 참이 되는 경우 | 매크로가 정의된 경우 | 매크로가 정의되지 않은 경우 |
| 주요 용도 | 특정 기능 활성화 | 기본 설정 적용, 헤더 중복 방지 |
| 종료 지시자 | #endif | #endif |

예를 들어 다음과 같이 사용할 수 있다.

```c
#define DEBUG

#ifdef DEBUG
    printf("DEBUG is defined.\n");
#endif

#ifndef RELEASE
    printf("RELEASE is not defined.\n");
#endif
```

실행 결과:

    DEBUG is defined.
    RELEASE is not defined.

`DEBUG`는 정의되어 있으므로 `#ifdef DEBUG` 조건이 참이다.

반면 `RELEASE`는 정의되어 있지 않으므로 `#ifndef RELEASE` 조건이 참이다.

따라서 두 출력문이 모두 실행된다.

---

## 7. 결론

`#ifndef ~ #endif`는 특정 매크로가 정의되어 있지 않은 경우에만 해당 코드를 컴파일하도록 하는 전처리 지시자이다.

이번 예제에서는 `RELEASE` 매크로가 정의되지 않았을 때 개발용 메시지가 출력되었으며, `RELEASE` 매크로를 정의한 경우에는 해당 메시지가 출력되지 않는 것을 확인하였다.

또한 헤더 파일에 `#ifndef`, `#define`, `#endif`를 사용하면 동일한 헤더 파일이 여러 번 포함되더라도 내부 선언과 정의가 중복 처리되는 것을 방지할 수 있다.

따라서 `#ifndef`는 조건부 컴파일뿐만 아니라 프로그램의 안정성과 유지보수성을 높이는 데 중요한 역할을 한다.
