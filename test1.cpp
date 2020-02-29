void foo(int)
{
  return;
}

int main()
{
  // g++ -Wall test1.cpp yields this "invalid conversion from
  // ‘void (*)(int)’ to ‘void (*)(int, int)’";
  // gcc -Wall test1.cpp yields the same message
  void (*arr[10])(int, int);
  for (int i = 0; i < 10; ++i)
    arr[i] = &foo;

  // this compiles anyway though in both c and c++
  void (*arr[10])();
  for (int i = 0; i < 10; ++i)
    arr[i] = nullptr;

  return 0;
}
