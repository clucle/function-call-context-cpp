#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief	Ư�� �Լ������� ��� ������ Context �� �����Ѵ�
///
/// - �����
/// Caller ���� DEFINE_FUNCTION_CALL_CONTEXT �� ����ؼ� Ư�� �Լ������� Context �� ���� ����
/// Callee ���� �ش� Context �� ���ڰ����� �Ѱܾ� �ϵ��� ����
/// 
/// - ����
/// Caller.h
/// `````````````````````````````````````````````````````````````````````````````````
/// class Caller
/// {
/// public:
/// int CallFunction();
/// };
///
/// // - Context ���� - //
/// DEFINE_FUNCTION_CALL_CONTEXT( KeyName, friend int Caller::CallFunction(); )
/// `````````````````````````````````````````````````````````````````````````````````
/// 
/// Caller.cpp
/// `````````````````````````````````````````````````````````````````````````````````
/// int Caller::CallFunction()
/// {
/// 	Callee callee;
/// // - KeyNameCallContext �� �� �Լ������� ���� ���� - //
/// 	return callee.FunctionName( KeyNameCallContext() );
/// }
/// `````````````````````````````````````````````````````````````````````````````````
/// 
/// Callee.h
/// `````````````````````````````````````````````````````````````````````````````````
/// class KeyNameCallContext;
/// 
/// class Callee
/// {
/// public:
/// // - Context �� ���ڷ� �޾ƾ� �Լ� Call ���� - //
/// 	int FunctionName( KeyNameCallContext&& );
/// };
/// `````````````````````````````````````````````````````````````````````````````````
/// 
/// Callee.cpp
/// `````````````````````````````````````````````````````````````````````````````````
/// int Callee::FunctionName( KeyNameCallContext&& )
/// {
/// 	return 0;
/// }
/// 
/// `````````````````````````````````````````````````````````````````````````````````
/// 
/// @param	name Ű �̸�
/// @param  Context �� ���� �� �ִ� �Լ�
////////////////////////////////////////////////////////////////////////////////////////////////////
#define DEFINE_FUNCTION_CALL_CONTEXT( keyName, friendString ) \
class keyName##CallContext                           \
{                                              \
public:                                        \
	friendString                               \
                                               \
private:                                       \
	keyName##CallContext() = default;                \
	~keyName##CallContext() = default;               \
};                                             \
