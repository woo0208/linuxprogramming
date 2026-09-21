# 실습과제 1

<img width="801" height="472" alt="image" src="https://github.com/user-attachments/assets/8be13c0e-84f1-468b-8a06-dea456b19f35" />

# 실습과제 2

<img width="631" height="957" alt="image" src="https://github.com/user-attachments/assets/42c15331-ca89-415e-8c1f-17eba73ec93c" />

# 실습과제 3

<img width="429" height="369" alt="image" src="https://github.com/user-attachments/assets/a8502ebb-9cb9-4973-afa0-b931cb349429" />

# 실습과제 4

# 하드링크와 심볼릭 링크

## 1. 하드링크와 심볼릭 링크의 차이

### 하드링크(Hard Link)

하드링크는 원본 파일과 **같은 inode를 가리키는 새로운 파일 이름**이다.

원본 파일과 하드링크 파일은 이름은 다르지만 실제로는 같은 파일 데이터를 가리킨다.

특징:

- 원본 파일과 하드링크는 같은 inode를 사용한다.
- 한쪽의 파일 내용을 변경하면 다른 쪽에서도 변경된 내용이 보인다.
- 원본 파일을 삭제해도 하드링크가 남아 있다면 데이터는 유지된다.
- 일반적으로 디렉터리에는 하드링크를 만들 수 없다.
- 같은 파일 시스템 안에서만 만들 수 있다.

예:

```bash
touch file1
ln file1 hardfile
```

위 명령어를 실행하면 `file1`과 `hardfile`은 같은 inode를 사용한다.

---

### 심볼릭 링크(Symbolic Link)

심볼릭 링크는 **원본 파일이나 디렉터리의 경로를 가리키는 별도의 파일**이다.

Windows의 바로가기와 비슷한 개념이다.

예:

```bash
touch file1
ln -s file1 symfile
```

`file1`이 원본이고 `symfile`은 `file1`을 가리키는 심볼릭 링크이다.

특징:

- 원본 파일과 다른 inode를 가진다.
- 원본 파일의 경로를 저장하여 참조한다.
- 파일뿐만 아니라 디렉터리에도 만들 수 있다.
- 원본 파일을 삭제하면 심볼릭 링크는 더 이상 정상적으로 사용할 수 없다.
- 다른 파일 시스템에 있는 파일이나 디렉터리도 가리킬 수 있다.

---

## 2. 하드링크와 심볼릭 링크의 차이 정리

| 구분 | 하드링크 | 심볼릭 링크 |
|---|---|---|
| 연결 대상 | 같은 inode | 원본의 경로 |
| inode | 원본과 동일 | 원본과 다름 |
| 원본 삭제 | 데이터 유지 | 링크가 끊어짐 |
| 디렉터리 링크 | 일반적으로 불가능 | 가능 |
| 다른 파일 시스템 | 불가능 | 가능 |
| 생성 명령어 | `ln 원본 링크` | `ln -s 원본 링크` |

쉽게 말하면 다음과 같다.

> **하드링크 = 같은 파일을 다른 이름으로 하나 더 만드는 것**

> **심볼릭 링크 = 원본 파일의 위치를 가리키는 바로가기**

---

## 3. 심볼릭 링크를 확인하는 명령어

가장 대표적인 명령어는 `ls -l`이다.

```bash
ls -l
```

예를 들어 다음과 같은 결과가 출력될 수 있다.

```text
-rw-r--r-- 1 linux linux 0 Sep 21 16:00 file1
lrwxrwxrwx 1 linux linux 5 Sep 21 16:01 symfile -> file1
```

여기서 다음 부분을 확인할 수 있다.

```text
symfile -> file1
```

이는 `symfile`이 `file1`을 가리키는 심볼릭 링크라는 뜻이다.

또한 파일 종류를 나타내는 첫 번째 문자가 `l`이면 심볼릭 링크이다.

```text
lrwxrwxrwx
^
심볼릭 링크
```

일반 파일은 다음과 같이 표시된다.

```text
-rw-r--r--
^
일반 파일
```

디렉터리는 다음과 같이 표시된다.

```text
drwxr-xr-x
^
디렉터리
```

또 다른 확인 명령어로 `readlink`를 사용할 수 있다.

```bash
readlink symfile
```

결과:

```text
file1
```

`readlink`를 사용하면 심볼릭 링크가 가리키는 대상을 확인할 수 있다.

---

## 4. 실제로 심볼릭 링크 만들기

실습을 위해 `linktest` 디렉터리를 생성한다.

```bash
mkdir linktest
cd linktest
```

빈 파일을 만든다.

```bash
touch original.txt
```

`original.txt`를 가리키는 심볼릭 링크를 만든다.

```bash
ln -s original.txt symlink.txt
```

심볼릭 링크를 확인한다.

```bash
ls -l
```

실행 결과 예시:

```text
-rw-r--r-- 1 linux linux 0 Sep 21 16:10 original.txt
lrwxrwxrwx 1 linux linux 13 Sep 21 16:10 symlink.txt -> original.txt
```

`symlink.txt -> original.txt`라고 표시되는 것을 통해 `symlink.txt`가 `original.txt`를 가리키는 심볼릭 링크임을 확인할 수 있다.

따라서 실습 결과 화면을 캡처하여 과제에 첨부하면 된다.

---

## 5. 빈 파일과 빈 디렉터리의 하드링크 수

빈 파일과 빈 디렉터리를 생성한다.

```bash
touch testfile
mkdir testdir
```

파일 속성을 확인한다.

```bash
ls -l
```

예를 들어 다음과 같이 출력될 수 있다.

```text
drwxr-xr-x 2 linux linux 4096 Sep 21 16:20 testdir
-rw-r--r-- 1 linux linux    0 Sep 21 16:20 testfile
```

여기서 파일명 앞에 있는 숫자가 하드링크의 수이다.

```text
testdir  → 2
testfile → 1
```

---

## 6. 파일의 하드링크 수가 1인 이유

일반적인 파일을 생성하면 처음에는 파일 이름 하나만 해당 inode를 가리킨다.

```text
testfile
   ↓
 inode
   ↓
 데이터
```

따라서 기본적인 하드링크 수는 `1`이다.

하드링크를 추가하면 다음과 같이 된다.

```bash
ln testfile hardfile
```

구조는 다음과 같다.

```text
testfile ──┐
           ├──> inode ──> 데이터
hardfile ──┘
```

이제 `testfile`과 `hardfile`이 같은 inode를 가리키므로 하드링크 수가 `2`가 된다.

---

## 7. 디렉터리의 하드링크 수가 2인 이유

디렉터리를 생성하면 기본적으로 `.`과 `..`이라는 특별한 디렉터리 항목이 존재한다.

- `.` : 현재 디렉터리 자신을 의미한다.
- `..` : 부모 디렉터리를 의미한다.

예를 들어 `testdir`을 생성하면 다음과 같은 구조를 가진다.

```text
testdir/
├── .
└── ..
```

`.`은 자기 자신인 `testdir`을 가리키고, 부모 디렉터리에서는 `testdir`을 가리키는 항목이 존재한다.

따라서 빈 디렉터리를 생성했을 때 기본적인 하드링크 수가 `2`가 된다.

```text
디렉터리 → 하드링크 수 2
파일     → 하드링크 수 1
```

---

## 8. 실습 명령어 정리

### 심볼릭 링크 실습

```bash
mkdir linktest
cd linktest
touch original.txt
ln -s original.txt symlink.txt
ls -l
```

### 빈 파일과 빈 디렉터리 실습

```bash
touch testfile
mkdir testdir
ls -l
```

### 하드링크 실습

```bash
ln testfile hardfile
ls -l
```

하드링크를 만든 후 `testfile`과 `hardfile`의 링크 수가 증가하는 것을 확인할 수 있다.
