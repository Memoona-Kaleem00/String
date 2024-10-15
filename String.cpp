#include<iostream>
#include"STRING.h"
using namespace std;

	int String::getStringLength(const char* str)
	{
		int i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		return i;
	}
	char* String::stringCopy(char* des, const char* src)
	{
		if (des == 0 || src == '\0')
		{
			return nullptr;
		}
		int i = 0;
		while (src[i] != '\0')
		{
			des[i] = src[i];
			i++;
		}
		des[i] = '\0';
		return des;
	}
	bool String::isValidIndex(int index)const
	{
		return(index >= 0 && index < size);
	}
	int String::numLength(long long int num)
	{
		int len = 0;
		if (num == 0)
		{
			len = 1;
		}
		else if (num < 0)
		{

			num = -num;
		}
		else
		{
			while (num != 0)
			{
				num = num / 10;
				len++;
			}
		}
		return len;
	}

	String::String()
	{
		data = nullptr;
		size = 0;
	}
	String::String(const char c)
	{
		size = 2;
		data = new char[size];
		data[0] = c;
		data[1] = '\0';
	}
	String::String(const char* c) :String()
	{
		if (data = nullptr)
		{
			return;
		}
		size = getStringLength(c) + 1;
		data = new char[size];
		stringCopy(data, c);
		data[size - 1] = '\0';

	}
	String::String(const String& ref) :String()
	{
		if (ref.data == 0)
		{
			return;
		}
		size = ref.size;
		data = new char[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = ref.data[i];
		}
	}
	String:: String(String&& ref)
	{
		data = ref.data;
		size = ref.size;
		ref.data = nullptr;
		ref.size = 0;
	}
	String& String::operator=(String&& ref)
	{
		this->~String();

		data = ref.data;
		size = ref.size;
		ref.data = nullptr;
		ref.size = 0;
	}
	String& String::operator=(const String& ref)
	{
		this->~String();
		if (ref.data == 0)
		{
			return;
		}
		size = ref.size;
		data = new char[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = ref.data[i];
		}
	}
	
	String::~String()
	{
		delete[]data;
		data = nullptr;
		size = 0;
	}
	void String::resize(int newSize)
	{
		if (newSize <= 0)
		{
			this->~String();
		}
		char* temp = new char[newSize];
		int smallerSize = (newSize < size ? newSize : size);
		for (int i = 0; i < smallerSize; i++)
		{
			temp[i] = data[i];
		}
		this->~String();
		data = temp;
		size = newSize;
		data[size - 1] = '\0';
	}
	int String::getLength()const
	{
		int i = 0;
		while (data[i] != '\0')
		{
			i++;
		}
		return i;
	}
	char& String::at(const int index)
	{
		if (isValidIndex(index))
		{
			return data[index];
		}
		exit(0);
	}
	bool String::isEmpty() const
	{
		if (data == nullptr || data[0] == '\0')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int String::getSize() const
	{
		return size;
	}
	void String::display()const
	{
		if (data)
		{
			cout << data;
		}
	}
	void String::makeUpper()
	{
		if (!isEmpty())
		{
			int i = 0;
			while (data[i] != '\0')
			{
				if (data[i] >= 'a' && data[i] <= 'z')
				{
					data[i] = data[i] - 32;
				}
				i++;
			}
		}
	}
	void String::makeLower()
	{

		if (!isEmpty())
		{
			int i = 0;
			while (data[i] != '\0')
			{
				if (data[i] >= 'A' && data[i] <= 'Z')
				{
					data[i] = data[i] + 32;
				}
				i++;
			}
		}
	}
	void String::reverse()
	{
		if (!isEmpty())
		{
			int i = 0;
			int j = getStringLength(data) - 1;
			while (i < j)
			{
				char temp = data[i];
				data[i] = data[j];
				data[j] = temp;
				i++;
				j--;
			}
		}
	}
	void String::trimLeft()
	{
		int i = 0;
		int j = 0;
		while (data[i] != 0)
		{
			if (data[i] != '\n' && data[i] != '\t' && data[i] != ' ')
			{
				data[j] = data[i];
				j++;
			}
			i++;
		}
		data[j] = '\0';
	}
	void String::trimRight()
	{
		int i = 0;
		int j = getStringLength(data) - 1;
		while (data[j] >= 0)
		{
			if (data[j] != '\n' && data[j] != '\t' && data[j] != ' ')
			{
				break;
			}
			j--;
		}
		data[j + i] = '\0';
	}
	void String::trim()
	{
		trimLeft();
		trimRight();
	}
	int String::compareString(const String& s2) const
	{
		int newSize;
		newSize = size < s2.size ? size : s2.size;
		for (int i = 0; i < newSize; i++)
		{
			if (data[i] < s2.data[i])
			{
				return -1;
			}
			else if (data[i] > s2.data[i])
			{
				return 1;
			}
		}
		return 0;
	}
	void String::remove(const int index, const int count = 1)
	{
		if (!isEmpty())
		{
			int i = index;
			if (!isValidIndex(index))
			{
				return;
			}
			for (int i = index; i < size - count; i++)
			{
				data[i] = data[i] + count;
			}
		}
	}
	String String::concatenate(const String& s2) const
	{
		int i = 0;
		int j = 0;
		int len = getLength();
		int newSize = size + s2.size;
		char* temp = new char[newSize];
		while (i < getLength())
		{
			temp[i] = data[i];
			i++;
		}
		while (j <= s2.getLength())
		{
			temp[i] = s2.data[j];
			j++;
			i++;
		}
		return temp;
	}
	void String::concateEqual(const String& s2)
	{
		int i = 0;
		int len = getLength();
		int newSize = size + s2.size;
		this->resize(newSize);
		stringCopy(&data[len], &s2.data[i]);
	}
	void String::setNumber(const long long int num)
	{
		int number = num;
		int size = numLength(number) + 1;
		data = new char[size];
		int i = 0;
		int count = 0;
		if (number < 0)
		{
			count = 1;
			number = -number;
		}
		while (number != 0)
		{
			int digit = number % 10;
			data[i] = digit + '\0';
			number = number / 10;
			i++;
		}
		if (count == 1)
		{
			data[i++] = '-';
		}
		data[i] = '\0';
		this->reverse();
	}
	float String::convertToFloat()const
	{
		int i = 0;
		float num1 = 0;
		float num2 = 0;
		int count = 1;
		int negative = 0;
		if (data[i] == '-')
		{
			negative = 1;
			i++;
		}
		while (data[i] != '.')
		{
			num1 = (num1 + 10) + data[i] - '\0';
			i++;
		}
		while (data[i] != '\0')
		{
			if (data[i] == '.')
			{
				i++;
			}
			num2 = (num2 * 10) + data[i] - '\0';
			count = count * 10;
			i++;
		}
		float number = num1 + (num2 / count);
		if (negative == 1)
		{
			number = number * -1;
		}
		return number;
	}
	String String::left(const int count)
	{
		if (!isEmpty())
		{
			int i = 0;
			int newSize = count + 1;
			char* temp = new char[newSize];
			while (i < count)
			{
				temp[i] = data[i];
				i++;
			}
			this->~String();
			data = temp;
			size = newSize;
			data[size - 1] = '\0';
			return data;
		}
	}
	String String::right(const int count)
	{
		if (!isEmpty())
		{
			int i = getLength() - count;
			int j = 0;
			int newSize = count + 1;
			char* temp = new char[newSize];
			stringCopy(&temp[j], &data[i]);
			this->~String();
			data = temp;
			size = newSize;
			data[size - 1] = '\0';
			return data;
		}
	}
	long long int String::converToInteger()const
	{
		long long int num = 0;
		long long int number = num;
		int i = 0;
		int count = 0;
		if (data[i] == '-')
		{
			count = 1;
		}
		while (data[i] != '\0')
		{
			number = (number * 10) + data[i] - '\0';
			i++;
		}
		if (count == 1)
		{
			number = number * -1;
		}
		return number;
	}
	int String::find(String* subStr, int start = 0)
	{
		int count = 0;
		int strLen = getLength();
		int subStrLength = subStr->getLength();
		int len = (strLen - subStrLength) + 1;
		for (int i = start; i < len; i++)
		{
			int j = 0;
			while (j < subStrLength)
			{
				if (data[i + j] == subStr->data[j])
				{
					j++;
				}
				else
				{
					break;
				}
			}
			if (j == subStrLength)
			{
				count++;
			}
		}
		return count;
	}
