#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef unsigned long uintptr_t;

struct Data {
    int id;
    std::string name;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& object);
        Serializer& operator=(const Serializer& object);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};




#endif