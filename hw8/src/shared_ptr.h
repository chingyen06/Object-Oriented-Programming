#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <stdexcept>
#include <mutex>

template <typename T>
class SharedPtr{
public:
    SharedPtr();

    explicit SharedPtr(T* rawPtr);

    SharedPtr(const SharedPtr<T> &other);

    ~SharedPtr();

    SharedPtr<T>& operator=(const SharedPtr<T> &other);

    T& operator*() const;

    int reference_count() const;

    void reset();

private:
    T* ptr;
    int* ref_count;
    mutable std::mutex mtx; // 保護 ref_count
};

// Default constructor
template <typename T>
SharedPtr<T>::SharedPtr() : ptr(nullptr), ref_count(nullptr) {}

// Construct from raw pointer
template <typename T>
SharedPtr<T>::SharedPtr(T* rawPtr) : ptr(rawPtr) {
    std::lock_guard<std::mutex> lock(mtx);

    if (ptr != nullptr) {
        ref_count = new int(1);
    }
    else {
        ref_count = nullptr;
    }
}

// Copy constructor
template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& other) : ptr(other.ptr), ref_count(other.ref_count) {
    std::lock_guard<std::mutex> lock(other.mtx);
    if (ref_count != nullptr) {
        (*ref_count)++;
    }
}

// Copy assignment operator
template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T> &other) {
    if (this == &other) {
        return *this;
    }
    
    // std::lock_guard<std::mutex> lock_this(this->mtx);
    // reset();
    // std::lock_guard<std::mutex> lock(other.mtx);

    std::scoped_lock(this->mtx, other.mtx);
    reset();

    ptr = other.ptr;
    ref_count = other.ref_count;

    if (ref_count != nullptr) {
        (*ref_count)++;
    }

    return *this;
}

// Destructor
template <typename T>
SharedPtr<T>::~SharedPtr() {
    reset();
}

// Dereference operator
template <typename T>
T& SharedPtr<T>::operator*() const {
    if (ptr == nullptr) {
        throw std::bad_optional_access();
    }

    return *ptr;
}

// Return reference count
template <typename T>
int SharedPtr<T>::reference_count() const {
    std::lock_guard<std::mutex> lock(mtx);

    if (ref_count == nullptr) {
        return 0;
    }

    return *ref_count;
}

// Release ownership
template <typename T>
void SharedPtr<T>::reset() {
    std::lock_guard<std::mutex> lock(mtx);

    if (ref_count != nullptr) {
        (*ref_count)--;

        if (*ref_count == 0) {
            delete ptr;
            delete ref_count;
        }
    }
    ptr = nullptr;
    ref_count = nullptr;
}

#endif // SHARED_PTR_H
