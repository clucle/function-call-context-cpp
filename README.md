## 특정 함수에서만 생성 가능한 Context 를 생성한다

Caller 에서 DEFINE_FUNCTION_CALL_CONTEXT 를 사용해서 특정 함수에서만 Context 를 생성 가능

Callee 에서 해당 Context 를 인자값으로 넘겨야 하도록 선언

### 예시

 - Caller.h
```c++
class Caller
{
public:
	int CallFunction();
};

// - Context 생성 - //
DEFINE_FUNCTION_CALL_CONTEXT( KeyName, friend int Caller::CallFunction(); )
```

 - Caller.cpp
```c++
int Caller::CallFunction()
{
	Callee callee;
// - KeyNameCallContext 는 이 함수에서만 생성 가능 - //
	return callee.FunctionName( KeyNameCallContext() );
}
```

Callee.h
```c++
class KeyNameCallContext;

class Callee
{
public:
// - Context 를 인자로 받아야 함수 Call 가능 - //
	int FunctionName( KeyNameCallContext&& );
};
```

Callee.cpp
```c++
int Callee::FunctionName( KeyNameCallContext&& )
{
	return 0;
}

```
