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

struct MyClassParams {
    int a;
    int b;
    const ArithOps* ops;
};

class MyClass;
class MyClassFactory {
  public:
    MyClass* create(int a, int b, const ArithOps* ops = new ArithOps);
};

class MyClass {
  public:
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

    explicit MyClass(const MyClassParams params)
        : _a(params.a), _b(params.b), _ops(params.ops) {} // NOLINT

    const ArithOps* _ops;
    friend MyClassFactory;
};

