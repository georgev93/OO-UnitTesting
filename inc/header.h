#ifndef header_h
#define header_h

class MyClass {
  public:
    MyClass(int a, int b) : _a(a), _b(b) {} // NOLINT

    int doComplexOp() const;

    virtual ~MyClass() = default;
    MyClass(MyClass&) = delete;
    MyClass(MyClass&&) = delete;
    MyClass& operator=(MyClass&) = delete;
    MyClass& operator=(MyClass&&) = delete;

  protected:
    int _a;
    int _b;

    virtual int getSum() const;
    virtual int getDiff() const;
};

#endif // header_h

