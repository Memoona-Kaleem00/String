class String 
{

	char* data;
	int size;
	int getStringLength(const char* str);
	char* stringCopy(char* des, const char* src);
	bool isValidIndex(int index)const;
	int numLength(long long int num);
public:
	String();
	String(const char c);
	String(const char* c) ;
	String(const String& ref) ;
	String(String&& ref);
	String& operator=(String&& ref);
	String& operator=(const String& ref);
	~String();
	void resize(int newSize);
	int getLength()const;
	char& at(const int index);
	bool isEmpty() const;
	int getSize() const;
	void display()const;
	void makeUpper();
	void makeLower();
	void reverse();
	void trimLeft();
	void trimRight();
	void trim();
	int compareString(const String& s2) const;
	void remove(const int index, const int count = 1);
	String concatenate(const String& s2) const;
	void concateEqual(const String& s2);
	void setNumber(const long long int num);
	float convertToFloat()const;
	String left(const int count);
	String right(const int count);
	long long int converToInteger()const;
	int find(String* subStr, int start = 0);


};
