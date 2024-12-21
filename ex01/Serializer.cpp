#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(const Serializer &src) {
    *this = src;
}

Serializer::~Serializer() {
}

Serializer &Serializer::operator=(const Serializer &src) {
    if (this != &src)
        return *this;
    return *this;
}

//reinterpret_cast is used for low-level casting and can convert any
// pointer type to any other pointer type, even if the types are unrelated. 
//It can also cast between pointer types and integral types.

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}