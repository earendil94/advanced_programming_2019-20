#include<iostream>
#include<memory>

template<typename T>
//
class Vector
{
    std::size_t _size{};
    std::size_t _capacity{};
    std::unique_ptr<T[]> elem{};

    void check_and_increase_capacity(){

        if (_capacity == 0)
            reserve(8);
        if (_size == _capacity)
            reserve(2*_size);

    }




public:

    //This const states that i can't modify 
    auto size() const noexcept { return _size; }
    auto capacity() const noexcept { return _capacity; }

    //Forwarding reference: it is basically equivalent to writing the other twos
    // template<typename OT>
    // void push_back(OT&& x){
    //     check_and_increase_capacity();
    //     elem[_size] = std::forward<OT>(x);
    //     ++_size;
    // }

    T& operator[](std::size_t i){
        //preconditions: elem != nullptr and i < _size
        return elem[i];
    }

    //The first const returns a const T. The second const actually checks that your arguments dont change in the 
    //function body
    const T& operator[](std::size_t i) const noexcept {
        //preconditions: elem != nullptr and i < _size
        return elem[i];
    }



    Vector() = default;

    //custom ctor: this is probably used only in order to make other stuff and not push_backed i guess?
    explicit Vector(const std::size_t& lenght) :
        _capacity{lenght},
        _size{lenght},
        elem{new T[lenght]{} }
        {} //Remember: we initialized before the {} since we already constructed the private variables of Vector


    void push_back(const T& x){
        check_and_increase_capacity(); //If the array is big enough to accept it
        elem[_size] = x;
        ++_size;
    }

    //since c++11 we can do this
    void push_back(T&& x){
        check_and_increase_capacity(); 
        elem[_size] = std::move(x);
        ++_size;
    }

    //This is a variadic template! It is a template with some parameter
    template<typename... Types>
    void emplace_back(Types&&... args){
        
        check_and_increase_capacity();
        elem[_size] = T{std::forward<Types>(args)...}; //Pack expansion
        _size++;    
    }

    void reserve(const std::size_t new_size){

        if(_capacity < new_size){

            T* new_array = new T[new_size];
            for (std::size_t i = 0; i <_size; ++i){
                
                std::move(elem);
            }

            elem.reset(new_array);
            _capacity = new_size;
        
        }
    }


};

template<typename T>
std::ostream& operator <<(std::ostream & os, Vector<T> &v){
        os << "size " << v.size() << "\n"
            << "capacity" << v.capacity() << "\n";
        for(std::size_t i=0; i<v.size(); ++i)
            os << v[i] << "\t";

        return os;
}

int main(){

    Vector<int> v;
    int x = 8;
    v.push_back(x);

    //Suppose we have a class date
    v.emplace_back(4,5,6);
    //is like calling v.push_back(Date{4,5,6})
    std::cout << v << std::endl;

    return 0;
}