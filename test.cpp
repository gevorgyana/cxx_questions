class A
{
 private:
  struct B
  {
    int a;
  };
  B b;

 public:
  B get(){return b;}
};


int main()
{
  A a;

  // works
  // auto b = a.get();

  // compiler error
  A::B b = a.get();

  return 0;
}
