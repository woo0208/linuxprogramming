# 리눅스 명령어 및 셸 조사

## 1. 리눅스 명령어란 무엇인가? 실제 명령어의 정체는 무엇인가?

리눅스 명령어(Command)는 사용자가 운영체제에 특정 작업을 수행하도록 요청하기 위해 사용하는 텍스트 형태의 명령이다.

예를 들어 다음과 같이 입력할 수 있다.

    ls -l /home

여기서 `ls`는 명령어이고, `-l`은 옵션이며, `/home`은 명령어에 전달하는 인자이다.

실제 명령어는 크게 다음과 같이 구분할 수 있다.

### ① 외부 명령어

실행 파일 형태로 존재하는 프로그램이다.

예:

    /usr/bin/ls
    /usr/bin/cat
    /usr/bin/cp
    /usr/bin/mkdir

사용자가 `ls`를 입력하면 셸은 `PATH` 환경변수에 등록된 디렉터리를 검색하여 `ls` 프로그램을 찾고 실행한다.

예:

    $ which ls
    /usr/bin/ls

### ② 셸 내장 명령어

셸 프로그램 자체에 포함되어 있는 명령어이다.

예:

    cd
    pwd
    echo
    export
    alias

특히 `cd`는 현재 실행 중인 셸의 작업 디렉터리를 변경해야 하기 때문에 셸 내부에서 처리된다.

### ③ alias

기존 명령어에 다른 이름을 지정하여 사용할 수 있다.

    alias ll='ls -al'

이후 `ll`을 입력하면 `ls -al`이 실행된다.

### ④ 셸 함수

여러 명령을 함수로 묶어서 하나의 명령처럼 사용할 수도 있다.

    hello() {
        echo "Hello Linux"
    }

따라서 리눅스에서 말하는 "명령어"는 하나의 종류만을 의미하는 것이 아니라, 외부 실행 프로그램, 셸 내장 명령어, alias, 셸 함수 등을 포함한다.


# 2. 리눅스에서 많이 사용되는 명령어 10개

| 명령어 | 기능 |
|---|---|
| `ls` | 파일과 디렉터리 목록 확인 |
| `cd` | 디렉터리 이동 |
| `pwd` | 현재 작업 디렉터리 확인 |
| `mkdir` | 디렉터리 생성 |
| `rm` | 파일 또는 디렉터리 삭제 |
| `cp` | 파일 또는 디렉터리 복사 |
| `mv` | 파일 이동 또는 이름 변경 |
| `cat` | 파일 내용 출력 |
| `grep` | 문자열 검색 |
| `find` | 파일 및 디렉터리 검색 |


## 2.1 ls

현재 디렉터리에 있는 파일과 디렉터리 목록을 보여준다.

    ls



## 2.2 cd

현재 작업 디렉터리를 변경한다.

    cd Documents

상위 디렉터리로 이동하려면 다음과 같이 사용한다.

    cd ..

홈 디렉터리로 이동하려면 다음과 같이 사용할 수 있다.

    cd ~



## 2.3 pwd

현재 작업 중인 디렉터리의 경로를 출력한다.

    pwd



## 2.4 mkdir

새로운 디렉터리를 생성한다.

    mkdir test




## 2.5 rm

파일 또는 디렉터리를 삭제한다.

파일 삭제:

    rm test.txt

디렉터리 삭제:

    rm -r test

`rm -rf`는 강제로 디렉터리와 그 안의 파일을 삭제하기 때문에 주의해서 사용해야 한다.

    rm -rf test

실수로 중요한 파일을 삭제할 수 있으므로 연습할 때는 별도의 테스트 폴더에서 실행하는 것이 좋다.


## 2.6 cp

파일이나 디렉터리를 복사한다.

    cp hello.txt copy.txt



## 2.7 mv

파일을 다른 위치로 이동하거나 파일 이름을 변경한다.

이름 변경:

    mv old.txt new.txt

다른 디렉터리로 이동:

    mv new.txt Documents/



## 2.8 cat

파일의 내용을 터미널에 출력한다.

    cat hello.txt


## 2.9 grep

파일이나 명령어의 출력에서 특정 문자열을 검색한다.

    grep "Linux" students.txt

예:

    $ cat students.txt
    Kim Linux
    Lee Windows
    Park Linux

    $ grep "Linux" students.txt
    Kim Linux
    Park Linux


## 2.10 find

파일이나 디렉터리를 검색한다.

현재 디렉터리에서 `.txt` 파일을 검색:

    find . -name "*.txt"

예:

    $ find . -name "*.txt"
    ./hello.txt
    ./students.txt

<img width="641" height="633" alt="image" src="https://github.com/user-attachments/assets/d48486f7-fd47-47c8-8e27-6c15f25acb02" />

# 3. 셸(Shell)과 커널(Kernel)

리눅스에서 셸과 커널은 서로 다른 역할을 담당한다.

전체적인 관계는 다음과 같다.

    사용자
      ↓
    터미널
      ↓
    셸
      ↓
    시스템 호출
      ↓
    커널
      ↓
    하드웨어


## 3.1 커널(Kernel)

커널은 운영체제의 핵심 부분이다.

주요 역할은 다음과 같다.

- CPU 관리
- 메모리 관리
- 프로세스 관리
- 파일 시스템 관리
- 하드웨어 및 장치 관리
- 네트워크 기능 관리
- 시스템 호출 제공

사용자 프로그램은 커널을 통해 하드웨어와 운영체제의 주요 기능을 이용한다.

예를 들어 프로그램이 파일을 읽거나 저장하려면 커널의 파일 시스템 기능을 이용한다.


## 3.2 셸(Shell)

셸은 사용자와 운영체제 사이에서 사용자의 명령을 해석하고 실행하는 프로그램이다.

대표적인 셸은 다음과 같다.

- sh
- bash
- zsh
- fish
- ksh

사용자가 다음과 같이 입력한다고 가정한다.

    ls

셸은 `ls`라는 명령을 해석하고 해당 프로그램을 찾아 실행한다.

셸은 단순히 명령어를 실행하는 것뿐만 아니라 다음과 같은 기능도 제공한다.

- 변수
- 환경 변수
- 파이프
- 리다이렉션
- 조건문
- 반복문
- 함수
- alias
- 셸 스크립트


## 3.3 셸과 커널의 차이

| 구분 | 셸 | 커널 |
|---|---|---|
| 역할 | 사용자 명령 해석 및 실행 | 운영체제의 핵심 기능 관리 |
| 예 | bash, zsh, sh | Linux Kernel |
| 주요 기능 | 명령어 실행, 파이프, 리다이렉션, 스크립트 | CPU, 메모리, 프로세스, 장치 관리 |
| 사용자와의 관계 | 사용자가 직접 사용 | 일반적으로 직접 사용하지 않음 |

즉, **셸은 커널과 같은 것이 아니다.**

셸은 사용자가 커널의 기능을 간접적으로 이용할 수 있도록 도와주는 인터페이스라고 할 수 있다.


# 4. 프롬프트 문자열에서 `~`의 의미

리눅스 터미널에서 다음과 같은 프롬프트를 볼 수 있다.

    user@computer:~$

여기에서 `~`는 일반적으로 **현재 사용자의 홈 디렉터리(Home Directory)** 를 의미한다.

예를 들어 사용자의 홈 디렉터리가 다음과 같다고 가정한다.

    /home/user

그러면 다음 두 표현은 같은 위치를 의미한다.

    ~
    /home/user

따라서 다음 명령은 홈 디렉터리로 이동한다.

    cd ~

또한 다음과 같이 사용할 수도 있다.

    cd ~/Documents

이는 다음 경로로 이동하는 것과 같은 의미이다.

    cd /home/user/Documents

`~`는 셸의 **tilde expansion(틸드 확장)** 기능과 관련이 있다.

예:

    $ echo ~
    /home/user

즉, `~`가 실제로 `/home/user`라는 경로로 확장된다.

다른 사용자의 홈 디렉터리는 다음과 같이 표현할 수 있다.

    ~john

이는 일반적으로 `john` 사용자의 홈 디렉터리를 의미한다.


# 5. sh, bash, zsh 셸의 차이

## 5.1 sh

`sh`는 전통적인 Unix 셸인 Bourne shell에서 유래한 이름이다.

주요 특징:

- Unix 계열의 전통적인 셸
- 기본적인 명령 실행 기능 제공
- 변수, 조건문, 반복문, 함수 등을 지원
- 비교적 단순한 구조
- POSIX 호환 스크립트 작성에 많이 사용

현대 Linux에서는 `/bin/sh`가 실제로 Bash를 가리키는 경우도 있고 Dash 등 다른 POSIX 계열 셸을 가리키는 경우도 있다.

따라서 `sh`와 `bash`가 항상 동일한 프로그램인 것은 아니다.


## 5.2 bash

Bash는 `Bourne Again SHell`의 약자이다.

Bourne shell을 기반으로 기능을 확장한 셸이며 Linux에서 매우 널리 사용된다.

주요 특징:

- 명령어 히스토리
- 명령어 자동 완성
- alias
- 환경 변수
- 셸 함수
- 파이프
- 리다이렉션
- 조건문
- 반복문
- 셸 스크립트

예:

    for i in 1 2 3
    do
        echo $i
    done

Bash는 시스템 관리 및 자동화용 셸 스크립트를 작성할 때 많이 사용된다.


## 5.3 zsh

Zsh는 `Z Shell`의 약자이다.

Bash와 비슷한 기능을 제공하면서 특히 대화형 사용 환경을 강화한 셸이다.

주요 특징:

- 강력한 자동 완성
- 명령어 수정
- 고급 파일명 패턴 검색
- 다양한 프롬프트 설정
- 플러그인
- 테마
- 사용자 환경 설정 기능

특히 개발자들이 터미널 환경을 자신에게 맞게 구성할 때 많이 사용한다.


## 5.4 sh, bash, zsh 비교

| 특징 | sh | bash | zsh |
|---|---|---|---|
| 기본 목적 | 전통적인 Unix/POSIX 셸 | 범용 셸 | 강력한 대화형 셸 |
| 호환성 | POSIX 중심 | 높은 호환성 | Bash와 완전히 동일하지 않음 |
| 스크립트 | 기본 기능 | 강력함 | 강력함 |
| 자동 완성 | 기본적 | 지원 | 매우 강력함 |
| 사용자 설정 | 적음 | 많음 | 매우 많음 |
| 플러그인 | 제한적 | 다양함 | 매우 다양함 |

정리하면 다음과 같다.

- `sh` : 이식성과 POSIX 호환성이 중요한 스크립트에 적합
- `bash` : Linux에서 범용적으로 사용하기 좋음
- `zsh` : 강력한 자동 완성과 사용자 설정을 원하는 경우 적합


# 6. 셸 스크립트

셸 스크립트(Shell Script)는 셸에서 실행할 명령어들을 파일에 작성하여 여러 작업을 자동으로 실행하는 프로그램이다.

예를 들어 다음 명령을 매번 직접 입력한다고 가정한다.

    mkdir backup
    cp file.txt backup/
    date
    echo "Backup complete"

이러한 작업을 셸 스크립트로 만들 수 있다.

예를 들어 `backup.sh` 파일을 만들고 다음 내용을 작성한다.

    #!/bin/bash

    mkdir -p backup
    cp file.txt backup/
    date
    echo "Backup complete"

실행 권한을 부여한다.

    chmod +x backup.sh

그리고 다음과 같이 실행한다.

    ./backup.sh


## 6.1 Shebang

셸 스크립트의 첫 줄에 다음과 같이 작성할 수 있다.

    #!/bin/bash

이를 일반적으로 **Shebang**이라고 한다.

스크립트를 어떤 인터프리터를 사용하여 실행할지 지정하는 역할을 한다.

예:

    #!/bin/bash

Bash를 사용하여 실행한다.

또는:

    #!/bin/sh

`sh`를 사용하여 실행한다.


## 6.2 변수

셸 스크립트에서는 변수를 사용할 수 있다.

    name="Linux"
    echo "Hello $name"

실행 결과:

    Hello Linux


## 6.3 조건문

조건에 따라 다른 명령을 실행할 수 있다.

    if [ -f "test.txt" ]; then
        echo "파일이 존재합니다."
    else
        echo "파일이 없습니다."
    fi


## 6.4 반복문

반복문을 이용하여 여러 파일을 한 번에 처리할 수 있다.

    for file in *.txt
    do
        echo "$file"
    done


## 6.5 셸 스크립트의 장점

셸 스크립트를 이용하면 반복적인 작업을 자동화할 수 있다.

주요 활용 분야:

- 파일 백업
- 로그 분석
- 여러 파일의 일괄 처리
- 서버 관리
- 프로그램 실행 자동화
- 시스템 모니터링
- 개발 및 배포 자동화

따라서 셸 스크립트는 Linux 시스템 관리와 자동화에 매우 유용하다.


# 7. Windows에서 사용하는 CLI 방식의 셸 종류

Windows에도 명령줄(Command Line Interface)을 이용하는 여러 환경이 있다.


## 7.1 Command Prompt

Command Prompt는 Windows의 전통적인 명령줄 환경이다.

실행 프로그램:

    cmd.exe

대표적인 명령어:

    dir
    cd
    copy
    move
    del
    mkdir

예:

    C:\Users\User>dir

`dir`을 이용하여 파일과 디렉터리 목록을 확인할 수 있다.


## 7.2 PowerShell

PowerShell은 Microsoft에서 개발한 명령줄 셸이자 스크립팅 환경이다.

대표적인 명령:

    Get-Process
    Get-ChildItem
    Get-Service

예:

    Get-Process

현재 실행 중인 프로세스 정보를 확인할 수 있다.

PowerShell의 중요한 특징은 명령어 사이에서 단순한 텍스트뿐만 아니라 **객체(Object)를 파이프라인을 통해 전달**할 수 있다는 점이다.

예:

    Get-Process | Where-Object CPU -gt 100


## 7.3 Windows Terminal

Windows Terminal은 셸 자체라기보다는 여러 CLI 환경을 실행할 수 있는 **터미널 애플리케이션**이다.

Windows Terminal에서 다음과 같은 환경을 실행할 수 있다.

- Command Prompt
- PowerShell
- WSL
- Azure Cloud Shell 등

따라서 Windows Terminal과 PowerShell은 같은 것이 아니다.

Windows Terminal은 터미널 프로그램이고, PowerShell은 그 안에서 실행되는 셸 중 하나이다.


## 7.4 WSL

WSL(Windows Subsystem for Linux)은 Windows에서 Linux 환경을 사용할 수 있도록 하는 기능이다.

WSL을 이용하면 Windows에서 Linux 배포판을 실행하고 Linux의 셸과 명령어를 사용할 수 있다.

예:

    bash

또는 설치되어 있다면:

    zsh

따라서 Windows에서도 WSL을 이용하여 Linux 명령어와 셸 환경을 사용할 수 있다.


# 8. 결론

리눅스 명령어는 사용자가 운영체제에 작업을 요청하기 위한 수단이며, 실제로는 외부 프로그램, 셸 내장 명령어, alias, 함수 등 여러 형태가 존재한다.

셸은 사용자의 명령을 해석하고 실행하는 프로그램이며, 커널은 CPU, 메모리, 프로세스, 파일 시스템, 장치 등을 관리하는 운영체제의 핵심이다.

프롬프트에서 `~`는 일반적으로 사용자의 홈 디렉터리를 의미한다.

`sh`, `bash`, `zsh`는 모두 Unix/Linux 계열에서 사용하는 셸이지만 기능과 목적에 차이가 있다. `sh`는 POSIX 호환성과 이식성이 중요할 때 유용하고, `bash`는 Linux에서 범용적으로 많이 사용되며, `zsh`는 강력한 자동 완성과 사용자 설정 기능이 특징이다.

셸 스크립트는 여러 명령어를 파일에 작성하여 반복적인 작업을 자동화하는 방법이다. Windows에서는 Command Prompt와 PowerShell이 대표적인 CLI 셸이며, Windows Terminal을 통해 이러한 셸을 사용할 수 있다. 또한 WSL을 이용하면 Windows에서도 Linux 셸과 명령어를 사용할 수 있다.
