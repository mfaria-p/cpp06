#include "Serializer.hpp"

//When you print a uintptr_t value, you are printing a number that represents the address
// of the pointer. This number is the integer representation of the memory address where 
//the data is stored.

//uintptr_t is an unsigned integer type that can hold a pointer value but cannot be used to
// directly access the value the pointer points to. It is useful for pointer arithmetic and
// low-level operations where pointers need to be treated as integers


//Serialization is the process of converting an object or data structure into a format 
//that can be easily stored or transmitted (in this case, uintptr_t) and then reconstructed 
//later. Deserialization is the reverse process, where the serialized data is converted 
//back into its original object or data structure.

int main() {
    Data data;
    data.num = 42;
    data.str = "example";

    // Serialize the data
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized data: " << raw << std::endl;

    // Deserialize the data
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized data (string): " << deserializedData->str << std::endl;
    std::cout << "Deserialized data (int): " << deserializedData->num << std::endl;

    // The return value of deserialize() compares equal to the original pointer
    if (deserializedData == &data) {
        std::cout << "Deserialization successful: pointers match" << std::endl;
    } else {
        std::cout << "Deserialization failed: pointers do not match" << std::endl;
    }

    return 0;
}