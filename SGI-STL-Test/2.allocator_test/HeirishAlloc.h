#ifndef __HEIRISH_ALLOCATOR_H__
#define __HEIRISH_ALLOCATOR_H__
#include <new>     //for replacement new.
#include <cstddef> //for ptrdiff_t, size_t
#include <cstdlib> //for exit
#include <climits> //for UINT_MAX
#include <iostream>

namespace Heirish
{
    template <typename T>
    inline T *_allocate(ptrdiff_t size, T *)
    {
        std::set_new_handler(0);
        T* tmp = (T*)::operator new((size_t)(size * sizeof(T)));
        if (tmp == nullptr) {
            std::cerr << "out of memory" << std::endl;
            exit(1);
        }
        return tmp;
    }

    template<typename T>
    inline void _deallocate(T* buffer) {
        ::operator delete(buffer);
    }

    template <typename T1, typename T2>
    inline void _construct(T1*p, const T2& value) {
        new(p) T1(value); //placement new.invoke constructor of T1
    }

    template <typename T>
    inline void _destroy(T *p) {
        p->~T();
    }

    template <typename T>
    class allocator{
        public:
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

        //rebind allocator of type U
        template <typename U>
        struct rebind{
            typedef allocator<U> other;
        };

        pointer allocate(size_type n, const void* hint=0) {
            return _allocate((difference_type)n, (pointer)0);
        }

        void deallocate(pointer p, size_type n) {
            _deallocate(p);
        }

        void construct(pointer p, const T& value) {
            _construct(p, value);
        }

        void destroy(pointer p) {
            _destroy(p);
        }

        pointer address(reference x) {
            return (pointer)&x;
        }
        const_pointer const_address(const_reference x) {
            return (const_pointer)&x;
        }

        size_t max_size() {
            return size_type(UINT_MAX/sizeof(T));
        }
    };
} // namespace Heirisha

#endif //__HEIRISH_ALLOCATOR_H__