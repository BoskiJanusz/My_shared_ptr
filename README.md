# My shared_ptr implementation

The unique_ptr class, defined in the my namespace, is a smart pointer implementation that provides exclusive ownership semantics for dynamically allocated objects. It follows the RAII (Resource Acquisition Is Initialization) principle and ensures that the allocated memory is properly released when it goes out of scope.

## Features:
### Construction:
- unique_ptr(): Constructs an empty unique_ptr.
- unique_ptr(T* ptr): Constructs a unique_ptr and takes ownership of the given raw pointer ptr.
### Move Semantics:
- unique_ptr(unique_ptr&& obj): Moves ownership from obj to a new unique_ptr.
- unique_ptr& operator=(unique_ptr&& other): Moves ownership from other to the current unique_ptr.
### Deleted Operations:
- unique_ptr(const unique_ptr&): Deleted copy constructor.
- unique_ptr& operator=(const unique_ptr&): Deleted copy assignment operator.
### Accessing the Underlying Object:
- T* operator->(): Returns a pointer to the underlying object.
- T& operator*(): Returns a reference to the underlying object.
### Getting the Raw Pointer:
- T* get() const: Returns the raw pointer held by the unique_ptr.
### Releasing Ownership:
- T* release(): Releases ownership of the underlying object and returns the raw pointer.
### Resetting the unique_ptr:
- void reset(): Deletes the currently owned object and sets the unique_ptr to a null state.
### Destruction:
- ~unique_ptr(): Destructs the unique_ptr and releases the owned object.
