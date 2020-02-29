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


/**
same behaviour with clang std=14 and clang std=17
 */

int main()
{
  A a;
  // works
  /* auto b = a.get(); */
  // type id of b is A::B

  // compiler error - we do not know type if of b
  A::B b = a.get();
  return 0;
}
