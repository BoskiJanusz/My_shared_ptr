# My shared_ptr implementation

The shared_ptr class is an implementation of a smart pointer with shared ownership semantics. It follows the RAII (Resource Acquisition Is Initialization) principle and ensures that the allocated memory is properly released when it goes out of scope.

# Features
### Construction:
- shared_ptr(): Creates an empty shared_ptr object with no associated pointer.
- shared_ptr(T* ptr): Creates a shared_ptr object and takes ownership of the given raw pointer ptr.
- shared_ptr(const shared_ptr& obj): Creates a shared_ptr object as a clone of an existing shared_ptr object, sharing ownership of the underlying pointer.
- shared_ptr(shared_ptr&& obj): Creates a shared_ptr object by moving the ownership from an r-value shared_ptr object.
### Assignment:
- shared_ptr& operator=(const shared_ptr& obj): Assigns a new value to the shared_ptr object, sharing ownership with another shared_ptr object.
- shared_ptr& operator=(shared_ptr&& obj): Assigns a new value to the shared_ptr object by moving the ownership from an r-value shared_ptr object.
### Access:
- operator bool() const: Checks if the shared_ptr object holds a valid pointer.
- T* operator->() const: Returns a pointer to the object managed by the shared_ptr.
- T& operator*() const: Returns a reference to the object managed by the shared_ptr.
- T* get() const: Returns the raw pointer managed by the shared_ptr.
### Memory management:
- void reset(): Releases ownership of the managed object and deallocates its memory if it was the last owner.
- long use_count() const: Returns the number of shared_ptr objects sharing ownership of the managed object.
- ~shared_ptr(): Destructor that automatically releases the ownership and deallocates the memory if it was the last owner.
