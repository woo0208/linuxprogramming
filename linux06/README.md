# Linux 명령어 실습 답변

## 1. `find` 명령어로 `.bashrc` 파일의 위치 검색

현재 디렉터리부터 `.bashrc` 파일을 검색한다.

```bash
find . -name ".bashrc"
```

시스템 전체에서 검색하려면:

```bash
find / -name ".bashrc" 2>/dev/null
```

- `.` : 현재 디렉터리부터 검색
- `/` : 루트 디렉터리부터 검색
- `-name ".bashrc"` : 파일 이름이 `.bashrc`인 파일 검색
- `2>/dev/null` : 권한 오류 등의 메시지를 숨김

## 2. 다음 두 명령어의 차이

```bash
find . -name '*.txt'
find . -name *.txt
```

첫 번째 명령어는 `*.txt`를 작은따옴표로 감싸기 때문에 셸이 `*`를 해석하지 않고 `find`에 그대로 전달한다.

```bash
find . -name '*.txt'
```

따라서 현재 디렉터리와 하위 디렉터리에서 `.txt`로 끝나는 파일을 정상적으로 검색할 수 있다.

두 번째 명령어는 실행 전에 셸이 `*.txt`를 먼저 해석한다.

```bash
find . -name *.txt
```

예를 들어 현재 디렉터리에 `a.txt`, `b.txt`가 있다면 다음과 비슷하게 변경될 수 있다.

```bash
find . -name a.txt b.txt
```

따라서 원하는 결과가 나오지 않거나 오류가 발생할 수 있다.

**결론:** `find`에서 `*`와 같은 와일드카드를 사용할 때는 작은따옴표나 큰따옴표로 묶는 것이 안전하다.

## 3. `--help` 옵션을 사용하여 명령어 사용법 출력

`--help` 옵션을 사용하면 명령어의 사용법과 옵션을 확인할 수 있다.

```bash
cp --help
```

또는

```bash
find --help
```

예:

```bash
ls --help
```

## 4. `man` 명령어로 명령어 사용법 출력

`man` 명령어를 사용하면 해당 명령어의 매뉴얼 페이지를 확인할 수 있다.

```bash
man ls
```

또는

```bash
man find
```

매뉴얼 화면에서 방향키나 `Page Up`, `Page Down`으로 내용을 확인할 수 있으며, `q`를 누르면 종료한다.

## 5. `cd`, `ls`, `cp`, `rm`, `ifconfig` 명령어의 실행파일 경로 조사

`which` 또는 `command -v` 명령어를 이용하여 실행파일의 위치를 확인할 수 있다.

```bash
which cd
which ls
which cp
which rm
which ifconfig
```

또는:

```bash
command -v cd
command -v ls
command -v cp
command -v rm
command -v ifconfig
```

일반적인 Linux 환경에서의 위치는 다음과 같다.

| 명령어 | 실행파일 위치 |
|---|---|
| `cd` | 셸 내장 명령어이므로 별도의 실행파일이 없음 |
| `ls` | `/usr/bin/ls` |
| `cp` | `/usr/bin/cp` |
| `rm` | `/usr/bin/rm` |
| `ifconfig` | `/usr/sbin/ifconfig` 또는 `/sbin/ifconfig` |

`cd`는 실행파일이 아니라 셸의 내장 명령어이므로 다음과 같이 확인할 수 있다.

```bash
type cd
```

출력 예:

```text
cd is a shell builtin
```

따라서 `cd`의 경우에는 일반적인 실행파일 경로가 존재하지 않는다.

※ `ifconfig`는 최신 Linux 배포판에서는 기본적으로 설치되어 있지 않을 수 있으며, `ip` 명령어를 사용하는 경우가 많다.
