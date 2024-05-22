#include <iostream>
#include "Serializer.hpp"

int main() {
    // Create and initialize a Data object
    Data originalData;
    originalData.id = 42;
    originalData.name = "Test Name";

    std::cout << "Original Data:" << std::endl;
    std::cout << "ID: " << originalData.id << ", Name: " << originalData.name << std::endl;

    uintptr_t raw = Serializer::serialize(&originalData);

    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "ID: " << deserializedData->id << ", Name: " << deserializedData->name << std::endl;

    return 0;
}