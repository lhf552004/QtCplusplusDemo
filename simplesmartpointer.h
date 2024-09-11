#ifndef SIMPLESMARTPOINTER_H
#define SIMPLESMARTPOINTER_H


template <typename T>
class SimpleSmartPointer
{
private:
    T* ptr;
public:
    explicit SimpleSmartPointer(T * p = nullptr): ptr(p) {}
    ~SimpleSmartPointer() {
        delete ptr;
    }
    SimpleSmartPointer(const SimpleSmartPointer&) = delete;
    SimpleSmartPointer& operator=(const SimpleSmartPointer&) = delete;
    // Move constructor
    SimpleSmartPointer(SimpleSmartPointer&& other)noexcept : ptr(other.ptr) {
        other.ptr = nullptr; // transfer ownership
    }

    SimpleSmartPointer& operator=(SimpleSmartPointer&& other) {
        if(this != &other) {
            delete ptr; // delet current resource
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // Function to reset the pointer with a new resource
    void reset(T* p = nullptr) {
        if (ptr != p) {
            delete ptr; // Delete the current resource
            ptr = p;    // Take ownership of the new resource
        }
    }

    // Function to get the raw pointer
    T* get() const {
        return ptr;
    }

};

#endif // SIMPLESMARTPOINTER_H
