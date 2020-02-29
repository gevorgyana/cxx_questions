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
