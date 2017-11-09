 #include "String.h"
 #include <cassert>
void test_constructors_and_print()
{
    String s("Hello World");
    String s1("Hello");  
    String s2( s1 ); 
    cout << "Testing constructors: " << "\n" <<  s << "\n" << s1 << "\n" << s2 << endl;
}

void test_assignment_and_print()
{
    cout << "Testing assignments: " << endl;
    String s("Hello World");
    String s1 = s;
    cout << "s1 " << s1 << endl; 
    String s2("My name is Nan");
    cout << "s2 " << s2 << endl;
    s2 = s1; 
    cout << "s2 got assigned to s1 " << endl;
    cout << "s2 " << s2 << endl;
}
    
void test_index_and_print()
{
    cout << "Testing index: " << endl;
    String s("Hello World");
    cout << "Hello World: index 0: " << s[0] << endl;
    String s1 = s;
    cout << "index 10: " << s[10] << endl;
    
}

void test_size_and_print()
{
    cout << "Testing size: " << endl;
    String s("Hello World");
    cout << "s: " << s << " size: " << s.size() << endl;
    String s1("My name is Nan");
    cout << "s1: " << s1 << " size: " << s1.size() <<endl;
}

void test_reverse_and_print()
{
    cout << "Testing reverse: " << endl;
    String s("Hello World");
    cout << s << "'s reverse: " << s.reverse() << endl;
    String s1("He11O, Wor1d");
    cout << s1 << "'s reverse: " << s1.reverse() << endl;
}

void test_indexOf_and_print()
{
    cout << "Testing index of: " << endl;
    String s("HelloWorld");
    cout << s << "'s H's index: " << s.indexOf('H') << endl;
    cout << s << "'s W's index: " << s.indexOf('W') << endl;
    cout << s << "'s D's index: " << s.indexOf('D') << endl;
    const String s1("llo");   
    const String s2("Wor");
    const String s3("ldd");
    cout << s << "'s llo's index: " << s.indexOf( s1 ) << endl;
    cout << s << "'s Wor's index: " << s.indexOf( s2 ) << endl;
    cout << s << "'s ldd's index: " << s.indexOf( s3 ) << endl;

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
    cout << "Testing != operator: " << endl;
    assert(s1 != s3);
    cout<< "pass the third assert" << endl;
    assert(s3 != s4);
    cout << "pass the fourth assert" << endl;

    cout << "Testing > operator: " << endl;
    assert(s2 > s1);
    cout << "pass the fifth assert" << endl;
    assert(s5 > s3);
    cout << "pass the sixth assert" << endl;
 
    cout << "Testing >= operator: " << endl;
    assert(s2 >= s3);
    cout << "pass the seventh assert" << endl;
    assert(s5 >= s3);
    cout << "pass the eighth assert" << endl;
 
    cout << "Testing < operator: " << endl;
    assert(s4 < s2);
    cout << "pass the ninth assert" << endl;
    assert(s1 < s5);
    cout << "pass the tenth assert" << endl;
 
    cout << "Testing <= operator: " << endl;
    assert(s4 <= s3);
    cout << "pass the eleventh assert" << endl;
    assert(s1 <= s5);
    cout << "pass the twelvth assert" << endl;
       
}

void test_concatenation()
{
    String s("Hello");
    String s1(" World");
    String s2 = s + s1;
    String s3(" How are you");
    String s4 = s2 + s3;
    cout << "Testing concatenation: " << endl;
    cout << "s: " << s << " s1: " << s1 << ". Concatenation: " << s2 << endl;
    cout << "s: " << s << " s1: " << s1 << ". Concatenation of s and s1-> s2: " << s2 << ". s3: " << s3 << ". Concatenation of s2 and s3 ->: " << s4 << endl;
    cout << "s: " << s  << "s: " << s << endl;
    s += s1;
    cout << "s: " << s << endl;
}

void test_reverse()
{
    String s("Hello");
    String s1("he11o, worLD.");
    cout << "Testing reverse: " << endl;
    cout << "s: " << s << ". Reverse: " << s.reverse() << endl;
    cout << "s1: " << s1 << ". Reverse: " << s1.reverse() << endl;
}

int main()
{
    test_constructors_and_print();
    test_assignment_and_print();
    test_index_and_print();
    test_size_and_print();
    test_reverse_and_print();
    test_indexOf_and_print();
    test_concatenation();
    test_relationals();
    test_reverse();
    return 0;
}


