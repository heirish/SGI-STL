#ifndef __A_H__
#define __A_H__
class A
{
public:
    A();
    A(int i);
    A(const A &other);
    A(A &&other);
    ~A();
    A &operator=(const A &other);
    A &operator=(A &&other);

private:
    int _value;
};
#endif //__A_H__