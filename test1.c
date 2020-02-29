/**
   https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_54.html

A point that sometimes causes confusion is that gcc will actually compile C++ source code when it detects a C++ file extension, but cannot then link the resulting object files. To avoid this problem, use g++ consistently for C++ programs and gcc for C programs.
 */

// if i name the file in .c, gcc demands that i name the parameter
void foo(int name)
{
  return;
}

// c = gcc -Wall test1.cpp
// cxx = g++ -Wall test1.cpp

int main()
{
  void (*arr[10])(int, int);
  for (int i = 0; i < 10; ++i)
    arr[i] = &foo; // this line introduces an error in cxx, not c!

  // the rest compiles with no warnings!
  void (*arr1[10])();
  for (int i = 0; i < 10; ++i)
    arr[i] = &foo; // this line if good in c, not cxx!

  void (*arr2[10])(int);
  for (int i = 0; i < 10; ++i)
    arr[i] = &foo; // same as above - compiles with c, not in cxx

  arr[0] = 0;

  return 0;
}


/**
   #stictly_typed;
 */
