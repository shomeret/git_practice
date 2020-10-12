#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H
// || << >> \n "" '' {} []

//Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jun 25, 2020

namespace sdds {
    const int TYPE_MAX_SIZE = 30;
    class Engine {
        char m_type[TYPE_MAX_SIZE+1];
        double m_size;
    public:
        Engine();
        //~Engine();
        //void clearName();
        Engine(const char* name, double size);
        double get() const;
        void display() const;
        //Engine& set(const Engine& engine);
        void setEmpty();

    };


}


#endif
