// msvc++ demands naming parameters, so the next line should
// be like void foo(int name)
void foo(int)
{
  return;
}

// c = gcc -Wall test1.cpp
// cxx = g++ -Wall test1.cpp

int main()
{
  void (*arr[10])(int, int);
  for (int i = 0; i < 10; ++i)
    arr[i] = &foo; // this line introduces an error in cxx and c too!

  // the rest compiles with no warnings!
  void (*arr1[10])();
  for (int i = 0; i < 10; ++i)
    arr[i] = nullptr;

  void (*arr2[10])(int);
  for (int i = 0; i < 10; ++i)
    arr[i] = nullptr;

  return 0;
}
