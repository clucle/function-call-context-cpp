#include "Caller.h"
#include "Callee.h"

int Caller::CallFunction()
{
	Callee callee;
	return callee.FunctionName( KeyNameCallContext() );
}