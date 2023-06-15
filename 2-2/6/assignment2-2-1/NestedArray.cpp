#include "NestedArray.h"

// ������ | �ʱ�ȭ
NestedArray::NestedArray()
{
	next = 0;
	prev = 0;
	parent = 0;
	ptr = 0;
	isStr = false;
}

// ���� �迭 ����
NestedArray* NestedArray::setNextArray(NestedArray* ptr)
{
	next = ptr;
	return next;
}

// ���� �迭 �ּ� ��ȯ
NestedArray* NestedArray::getNextArray() const
{
	return next;
}

// ���� �迭 ����
NestedArray* NestedArray::setPreviousArray(NestedArray* ptr)
{
	prev = ptr;
	return prev;
}

// ���� �迭 �ּ� ��ȯ
NestedArray* NestedArray::getPreviousArray() const
{
	return prev;
}

// ���� �迭 ����
NestedArray* NestedArray::setParentArray(NestedArray* ptr)
{
	parent = ptr;
	return parent;
}

// ���� �迭 �ּ� ��ȯ
NestedArray* NestedArray::getParentArray() const
{
	return parent;
}

// ���� �迭 ����
NestedArray* NestedArray::createNextArray()
{
	next = new NestedArray;
	next->setPreviousArray(this);
	next->setParentArray(parent);
	return next;
}

// �迭 ��� ����
NestedArray* NestedArray::createArrayElement()
{
	NestedArray* arr = new NestedArray;
	arr->setParentArray(this);
	ptr = arr;
	return arr;
}

// ���ڿ� ��� ����
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

// ����� ���ڿ� ����
bool NestedArray::isString() const
{
	return isStr;
}

// ��� �ּ� ��ȯ
void* NestedArray::getElement() const
{
	return ptr;
}

// ��� ����
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
