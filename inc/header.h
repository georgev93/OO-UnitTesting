class ArithOps {
  public:
    ArithOps() = default;
    virtual ~ArithOps() = default;
    ArithOps(const ArithOps&) = default;
    ArithOps(ArithOps&&) = default;
    ArithOps& operator=(const ArithOps&) = default;
    ArithOps& operator=(ArithOps&&) = default;

    virtual int getSum(int a, int b) const;
    virtual int getDiff(int a, int b) const;
};

class MyClass {
  public:
    MyClass(int a, int b, const ArithOps* ops = new ArithOps)
        : _a(a), _b(b), _ops(ops) {} // NOLINT

    MyClass(const MyClass&) = delete;
    MyClass(MyClass&&) = delete;
    MyClass& operator=(const MyClass&) = delete;
    MyClass& operator=(MyClass&&) = delete;
    ~MyClass() {
        delete this->_ops;
    }

    int doComplexOp() const;

  private:
    int _a;
    int _b;

    const ArithOps* _ops;
};

