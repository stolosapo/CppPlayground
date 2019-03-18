#include "TestState.h"

TestState::TestState() : name("<empty>")
{

}

TestState::~TestState()
{

}

string TestState::getName()
{
	return name;
}

void TestState::setName(string name)
{
	this->name = name; 
}