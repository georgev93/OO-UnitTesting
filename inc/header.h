class MyClass {
  public:
    MyClass(int a, int b) : _a(a), _b(b) {} // NOLINT

    int doComplexOp() const;

  private:
    int _a;
    int _b;

  int getSum() const;
  int getDiff() const;
};

