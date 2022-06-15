#pragma once

#include "macro.h"

class Caller
{
public:
	int CallFunction();
};

DEFINE_FUNCTION_CALL_CONTEXT( KeyName, friend int Caller::CallFunction(); )
