# `ls` 명령어의 4가지 옵션

`ls`는 현재 디렉터리에 있는 파일과 디렉터리의 목록을 보여주는 명령어입니다.

## 1. `ls -a` — 숨김 파일까지 모두 표시

- `-a`는 **all**의 약자입니다.
- 이름이 `.`으로 시작하는 **숨김 파일과 디렉터리까지 표시**합니다.
- `.`은 현재 디렉터리, `..`은 상위 디렉터리를 의미합니다.

    ls -a

<img width="848" height="56" alt="image" src="https://github.com/user-attachments/assets/478fb02d-7806-4ddb-a566-f00161a0806e" />



## 2. `ls -l` — 자세한 정보로 표시

- `-l`은 **long format**의 약자입니다.
- 파일 이름뿐만 아니라 **권한, 소유자, 그룹, 크기, 수정 시간** 등의 상세 정보를 보여줍니다.

    ls -l
<img width="521" height="181" alt="image" src="https://github.com/user-attachments/assets/437b4269-ceec-4e85-8022-5e4a1e114e6a" />


| 부분 | 의미 |
|---|---|
| `-rw-r--r--` | 파일 종류 및 권한 |
| `1` | 하드 링크 수 |
| `linux` | 소유자 |
| `linux` | 그룹 |
| `0` | 파일 크기 (bytes) |
| `Sep 14 09:19` | 마지막 수정 시간 |
| `file1` | 파일 이름 |

따라서 `ls -l`은 **파일의 상세 정보를 확인할 때** 사용합니다.


## 3. `ls -F` — 파일 종류를 기호로 표시

- `-F`는 파일 종류에 따라 **특수 기호를 파일 이름 뒤에 붙여주는 옵션**입니다.

주요 기호:

- `/` → 디렉터리
- `@` → 심볼릭 링크
- `*` → 실행 가능한 파일
- `|` → FIFO
- 아무것도 없음 → 일반 파일

    ls -F
  
<img width="602" height="40" alt="image" src="https://github.com/user-attachments/assets/3ef4ec7c-bed7-4c1e-a1f5-3cfb55aac0c7" />


## 4. `ls --help` — 도움말 표시

`--help`는 `ls` 명령어의 **사용법과 옵션 목록을 보여주는 옵션**입니다.

    ls --help


<img width="795" height="733" alt="image" src="https://github.com/user-attachments/assets/0e59b9d3-aa71-4fff-81d5-462e16784374" />



# 한눈에 정리

| 옵션 | 의미 | 기능 |
|---|---|---|
| `-a` | all | 숨김 파일까지 표시 |
| `-l` | long | 파일의 상세 정보 표시 |
| `-F` | classify | 파일 종류를 나타내는 기호 추가 |
| `--help` | help | 명령어 사용법과 옵션 설명 표시 |

