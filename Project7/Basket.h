#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include <iostream>
// [] {} << >> <> \n "" '' ||

//Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jul 7, 2020

namespace sdds{
    struct Fruit{
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket{
        Fruit* m_fruits;
        int m_cnt;
        double m_price;
    public:
        Basket();
        ~Basket();
        Basket(Fruit fruit[], int, double);
        Basket(const Basket&);
        Basket& operator=(const Basket&);
        void setPrice(double price);
        explicit operator bool() const;
        Basket& operator+=(Fruit fruit);
        void setEmpty();
        void clearPtr();
        friend std::ostream& operator<<(std::ostream& os, const Basket& basket);
    };


}








#endif
