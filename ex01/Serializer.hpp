#ifndef EX01_SERIALIZER_HPP
#define EX01_SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h> // For uintptr_t

//uintptr_t is an unsigned integer type that can hold a pointer value but 
//cannot be used to directly access the value the pointer points to. It is 
//useful for pointer arithmetic and low-level operations where pointers 
//need to be treated as integers


class Serializer {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    
    private:
        Serializer(); // Default constructor
        Serializer(const Serializer &src); // Copy constructor
        ~Serializer(); // Destructor
        Serializer &operator=(const Serializer &src); // Assignment operator

};

#endif //EX01_SERIALIZER_HPP