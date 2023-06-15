#include "NestedArray.h"

// 생성자 | 초기화
NestedArray::NestedArray()
{
	next = 0;
	prev = 0;
	parent = 0;
	ptr = 0;
	isStr = false;
}

// 다음 배열 설정
NestedArray* NestedArray::setNextArray(NestedArray* ptr)
{
	next = ptr;
	return next;
}

// 다음 배열 주소 반환
NestedArray* NestedArray::getNextArray() const
{
	return next;
}

// 이전 배열 설정
NestedArray* NestedArray::setPreviousArray(NestedArray* ptr)
{
	prev = ptr;
	return prev;
}

// 이전 배열 주소 반환
NestedArray* NestedArray::getPreviousArray() const
{
	return prev;
}

// 상위 배열 설정
NestedArray* NestedArray::setParentArray(NestedArray* ptr)
{
	parent = ptr;
	return parent;
}

// 상위 배열 주소 반환
NestedArray* NestedArray::getParentArray() const
{
	return parent;
}

// 다음 배열 생성
NestedArray* NestedArray::createNextArray()
{
	next = new NestedArray;
	next->setPreviousArray(this);
	next->setParentArray(parent);
	return next;
}

// 배열 요소 생성
NestedArray* NestedArray::createArrayElement()
{
	NestedArray* arr = new NestedArray;
	arr->setParentArray(this);
	ptr = arr;
	return arr;
}

// 문자열 요소 생성
char* NestedArray::createStringElement(char* string, int length)
{
	char* str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = string[i];
	}
	str[length] = 0;
	isStr = true;
	ptr = str;
	return str;
}

// 요소의 문자열 여부
bool NestedArray::isString() const
{
	return isStr;
}

// 요소 주소 반환
void* NestedArray::getElement() const
{
	return ptr;
}

// 요소 제거
void NestedArray::deleteElement()
{
	if (isStr)	delete[] (char*)ptr;
	else if (ptr)
	{
		((NestedArray*)ptr)->deleteElement();
		delete (NestedArray*)ptr;
	}
	ptr = 0;
	return;
}
