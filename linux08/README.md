## 1. 셸 변수와 환경변수의 차이점

셸 변수(Shell Variable)는 현재 실행 중인 셸에서만 사용할 수 있는 변수이다. 기본적으로 자식 프로세스에는 전달되지 않는다.

환경변수(Environment Variable)는 현재 셸뿐만 아니라 해당 셸에서 실행되는 자식 프로세스에도 전달되는 변수이다.

셸 변수에 `export` 명령을 사용하면 환경변수로 만들 수 있다.

예:

```bash
MYVAR="hello"
```

위와 같이 선언하면 셸 변수이다.

```bash
export MYVAR="hello"
```

위와 같이 `export`를 사용하면 환경변수가 된다.

---

## 2. 환경변수 PS1, PATH, SHELL, LANG 출력 및 기능

다음 명령어를 사용하여 환경변수를 확인할 수 있다.

```bash
echo "PS1=$PS1"
echo "PATH=$PATH"
echo "SHELL=$SHELL"
echo "LANG=$LANG"
```

### 실행 결과

<img width="952" height="361" alt="image" src="https://github.com/user-attachments/assets/d2b62087-03ac-4dbf-9d11-7e45bcd16078" />

실행 결과는 컴퓨터 환경에 따라 다르게 나타날 수 있다.

### 각 환경변수의 기능

| 환경변수 | 기능 |
|---|---|
| `PS1` | 셸에서 사용자가 명령어를 입력할 때 표시되는 프롬프트의 모양을 지정한다. |
| `PATH` | 명령어를 실행할 때 실행 파일을 검색하는 디렉터리들의 목록이다. |
| `SHELL` | 사용자가 기본적으로 사용하는 셸의 경로를 나타낸다. |
| `LANG` | 시스템에서 사용하는 기본 언어 및 로케일을 설정한다. |

---

## 3. 셸이 명령어 파일의 위치를 찾는 방법

셸에서 사용자가 `ls`와 같이 명령어의 경로를 지정하지 않고 입력하면 셸은 `PATH` 환경변수에 등록된 디렉터리를 순서대로 검색한다.

예를 들어 `PATH`가 다음과 같다고 가정한다.

```text
/usr/local/bin:/usr/bin:/bin
```

이 경우 셸은 다음과 같은 순서로 명령어 파일을 찾는다.

```text
/usr/local/bin/ls
/usr/bin/ls
/bin/ls
```

실제 명령어의 위치는 `which` 명령어를 이용하여 확인할 수 있다.

```bash
which ls
```

실행 결과의 예:

```text
/usr/bin/ls
```

따라서 셸은 `PATH`에 등록된 디렉터리를 왼쪽에서 오른쪽 순서로 검색하여 실행 가능한 명령어 파일을 찾는다.

---

## 4. 셸 스크립트란?

셸 스크립트(Shell Script)는 셸에서 실행할 여러 명령어를 하나의 파일에 작성해 놓은 것이다.

여러 명령어를 매번 직접 입력하지 않고 스크립트 파일을 실행함으로써 여러 작업을 자동으로 수행할 수 있다.

예를 들어 `test.sh` 파일을 만들고 다음과 같이 작성할 수 있다.

```bash
#!/bin/bash

echo "Hello"
echo "Shell Script"
```

위와 같이 작성한 파일이 셸 스크립트이다.

---

## 5. 셸 스크립트의 실행 방법 3가지

### 방법 1. bash 명령어를 이용하여 실행

```bash
bash test.sh
```

Bash 셸이 `test.sh` 파일의 내용을 읽어 실행한다.

### 방법 2. source 명령어를 이용하여 실행

```bash
source test.sh
```

또는 다음과 같이 실행할 수도 있다.

```bash
. test.sh
```

`source` 명령어는 현재 실행 중인 셸에서 스크립트의 명령어를 실행한다.

### 방법 3. 실행 권한을 부여한 후 직접 실행

먼저 실행 권한을 부여한다.

```bash
chmod +x test.sh
```

그 후 다음과 같이 실행한다.

```bash
./test.sh
```

### 세 가지 방법 정리

| 방법 | 명령어 | 특징 |
|---|---|---|
| Bash 이용 | `bash test.sh` | Bash가 스크립트를 실행한다. |
| Source 이용 | `source test.sh` | 현재 셸에서 스크립트를 실행한다. |
| 직접 실행 | `chmod +x test.sh` → `./test.sh` | 실행 권한을 부여한 후 직접 실행한다. |

---

## 6. .bashrc에 MYVER 환경변수 설정

먼저 다음 명령어를 사용하여 `.bashrc` 파일을 연다.

```bash
nano ~/.bashrc
```

파일의 가장 아래에 다음 내용을 추가한다.

```bash
export MYVER="ubuntu 26.04"
```

저장하고 `nano`를 종료한다.

- `Ctrl + O` : 저장
- `Enter` : 파일명 확인
- `Ctrl + X` : 종료

그다음 변경된 `.bashrc` 파일을 현재 셸에 적용한다.

```bash
source ~/.bashrc
```

이제 `echo` 명령어를 사용하여 `MYVER`의 값을 확인한다.

```bash
echo $MYVER
```

정상적으로 설정되었다면 다음과 같이 출력된다.

```text
ubuntu 26.04
```

### 실행 결과 캡처

<img width="957" height="311" alt="image" src="https://github.com/user-attachments/assets/5d91bef9-5468-42cb-a058-ad41aee453b4" />

---

## 7. 환경변수에 경로를 추가할 때 $PATH='$PATH:~/bin'처럼 작성하면 어떻게 되는가?

다음과 같이 작성하면:

```bash
PATH='$PATH:~/bin'
```

작은따옴표 `' '` 안에 있는 `$PATH`는 변수로 해석되지 않는다.

따라서 기존 `PATH`의 값이 사용되는 것이 아니라 `$PATH:~/bin`이라는 문자열 자체가 `PATH`에 저장된다.

즉, 기존의 `PATH` 경로들이 사라질 수 있으므로 올바른 방법이 아니다.

기존 `PATH`에 `~/bin`을 추가하려면 다음과 같이 작성하는 것이 올바르다.

```bash
export PATH="$PATH:~/bin"
```

큰따옴표 `" "`를 사용하면 `$PATH`가 기존 PATH 환경변수의 실제 값으로 치환된다.

예를 들어 기존 PATH가 다음과 같다면:

```text
/usr/local/bin:/usr/bin:/bin
```

다음 명령어를 실행한다.

```bash
export PATH="$PATH:~/bin"
```

실행 후에는 다음과 같이 `~/bin`이 추가된다.

```text
/usr/local/bin:/usr/bin:/bin:~/bin
```

따라서 환경변수에 기존 경로를 유지하면서 새로운 경로를 추가하려면 다음과 같이 작성해야 한다.

```bash
export PATH="$PATH:~/bin"
```

---
