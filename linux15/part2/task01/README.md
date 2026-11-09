## SmartTV 객체 htv 생성 시 생성자 호출 순서

SmartTV 객체 htv가 생성될 때 생성자는 부모 클래스부터 자식 클래스 순서로 호출된다.

1. **TV 클래스 생성자 호출**
   - WideTV 생성자로부터 전달받은 인수 32가 전달된다.
   - 멤버 변수 size에 32가 저장된다.

2. **WideTV 클래스 생성자 호출**
   - SmartTV 생성자로부터 전달받은 인수 32와 true가 전달된다.
   - TV(size)를 통해 부모 클래스인 TV의 생성자에 32를 전달한다.
   - 멤버 변수 videoIn에 true가 저장된다.

3. **SmartTV 클래스 생성자 호출**
   - 객체 생성 시 전달한 인수 "192.0.0.1"과 32를 전달받는다.
   - WideTV(size, true)를 통해 WideTV 생성자에 32와 true를 전달한다.
   - 멤버 변수 ipAddr에 "192.0.0.1"이 저장된다.

## 생성자 호출 순서 및 인수 전달

SmartTV htv("192.0.0.1", 32);

- TV(int size) → 32 전달
- WideTV(int size, bool videoIn) → 32, true 전달
- SmartTV(string ipAddr, int size) → "192.0.0.1", 32 전달

## 결론

생성자는 부모 클래스부터 자식 클래스 순서인 TV → WideTV → SmartTV 순서로 호출된다.

각 생성자는 초기화 리스트를 통해 부모 클래스의 생성자에 필요한 인수를 전달하며, 최종적으로 htv 객체에는 다음 값이 저장된다.

- size = 32
- videoIn = true
- ipAddr = "192.0.0.1"
