 #include "String.h"
 #include <iostream>
 #include <cassert>
using namespace std;

void test_constructors_and_print()
{
    String s("Hello World");
    String s1("Hello");  
    String s2( s1 );
	String s3;
    cout << "Testing constructors: " << endl;
	cout << s << "\n" << s1 << "\n" << s2 << endl;
	cout << "Empty String: " << s3 << endl;

}

void test_assignment()
{
	cout << "Testing ASSIGNMENTS: " << endl;
	String s("Hello World");
	String s1 = s;
	String s2;
	String s3 = s2;
	cout << "s: " << s << endl;
	cout << "s1(s1): " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3(s2): " << s3 << endl; 
}

void test_size_and_print()
{
    cout << "Testing size: " << endl;
    String s("Hello World");
    cout << "s: " << s << " size: " << s.size() << endl;
    String s1("My name is Nan");
    cout << "s1: " << s1 << " size: " << s1.size() << endl;
	String s2;
	cout << "s2: " << s2 << " size: " << s2.size() << endl;
}



void test_index_and_print()
{
    cout << "Testing index: " << endl;
    String s("Hello World");
    cout << "Hello World[0]: " << s[0] << endl;
	cout << "Hello World[6]: " << s[6] << endl;
	cout << "Hello World[20]: " << s[20] << endl;
}

void test_indexOf_and_print()
{
    cout << "Testing index of: " << endl;
    String s("Hello World");
    cout << s << " H's index: " << s.indexOf('H') << endl;
    cout << s << " W's index: " << s.indexOf('W') << endl;
    cout << s << " D's index: " << s.indexOf('D') << endl;

}

void test_concatenation()
{
	String s("Hello");
    String s1("World");
    String s2 = s + s1;
    String s3("How are you");
    String s4 = s2 + s3;
    cout << "Testing concatenation: " << endl;
    cout <<  "Concatenation of s and s1 -> s2: " << s2 << " s: " << s << " s1: " << s1 << endl;
    cout << "Concatenation of s2 and s3 -> s4: " << s4 << " s2: " << s2 << " s3: " << s3 << endl;
	cout << "s: " << s  << " s1: " << s1 << '\n' << "s+=s1" << endl;
    s += s1;
    cout << "s: " << s << " s1: " << s1 << endl;
	cout << "s: " << s << " s3: " << s3 << '\n' << "s+=s3" << endl;
	s += s3;
	cout << "s: " << s << " s1: " << s1 << " s3: "<< s3 << endl;

}

void test_reverse_and_print()
{
    cout << "Testing reverse: " << endl;
    String s0("Hello World");
    cout << "s0's reverse: " << s0.reverse() << "s0: " << s0 << endl;
    String s1("He11O, Wor1d");
    cout << "s1's reverse: " << s1.reverse() << "s1: " << s1 << endl;
}

void test_relationals()
{
    cout << "Testing == operator: " << endl;
    String s("Hello");
    String s1("Hello");
    String s2("Hello ");
    String s3("Hello ");
    String s4("Hello");
    String s5("easy and simple");
    assert(s==s1);
    cout << "pass the first assert" << endl;
    assert(s2==s3);
    cout << "pass the second assert" << endl;
	cout << "Testing < operator: " << endl;
    assert(s4 < s2);
    cout << "pass the fourth assert" << endl;
    assert(s1 < s5);
    cout << "pass the fifth assert" << endl;

}


int main()
{
	test_constructors_and_print();
	test_assignment();
	test_index_and_print();
	test_size_and_print();
	test_reverse_and_print();
	test_indexOf_and_print();
	test_relationals();
	test_concatenation();
	return 0;
}


