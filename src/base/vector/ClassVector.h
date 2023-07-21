#pragma once

#include <array>
#include <iostream>

#define X 0
#define Y 1
#define Z 2

namespace cg {

#define DIM2 2
#define DIM3 3

    template<class coordinate_type, size_t dimension>
    class Vector {
        static_assert(std::is_arithmetic<coordinate_type>(), "Vector class can only store Integer or Floaring point values");
        static_assert(dimension >= DIM2, "Vector dimension atleast should be 2D");

        std::array<coodinate_type, dimension> coords;

        public:
            Vector() {}

            Vector(std::array<coordinate_type, dimension> _coords):coords(_coords) {}

            Vector(coodinate_type _x, coodinate_type _y, coodinate_type _z):coords({_x, _y, _z}) {}

            Vector(coodinate_type _x, coodinate_type _y):coords({_x, _y}) {}

            bool operator==(const Vector<coordinate_type, dimension>&);

            bool operator!=(const Vector<coordinate_type, dimension>&);

            Vector<coordinate_type, dimension> operator+(const Vector<coordinate_type, dimension>&) const;

            Vector<coordinate_type, dimension> operator-(const Vector<coordinate_type, dimension>&) const;

            bool operator <(const Vector<coordinate_type, dimension>&);

            bool operator >(const Vector<coordinate_type, dimension>&);

            coordinate_type operator[](int) const;

            void assign(int dim, coordinate_type value);


    };

    template<class coordinate_type, size_t dimension>
    inline bool Vector<coordinate_type, dimension>::operator==(const Vector<coordinate_type, dimension>& _other){
        for (size_t i = 0; i < dimension; i++){
            if (!isEqual1D(coords[i], _other.coords[i])){
                return false;
            }
        }
        return true;
    }


    template<class coordinate_type, size_t dimension>
    inline bool Vector<coordinate_type, dimension>::operator!=(const Vector<coordinate_type, dimension>& _other){
        return !(*this==_other);
    }


    template<class coordinate_type, size_t dimension>
    inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator+(const Vector<coordinate_type, dimension>& _other){
        std::array<coordinate_type, dimension> temp_array;
        
        for (size_t i = 0; i < dimemsnion; i++){
            temp_array[i] = coords[i] + _other.coords[i]
        }

        return Vector<coordinate_type, dimension>(temp_array);
    }


    template<class coordinate_type, size_t dimension>
    inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator-(const Vector<coordinate_type, dimension>& _other){
        std::array<coordinate_type, dimension> temp_array;
        
        for (size_t i = 0; i < dimemsnion; i++){
            temp_array[i] = coords[i] - _other.coords[i]
        }

        return Vector<coordinate_type, dimension>(temp_array);
    }


    template<class coordinate_type, size_t dimension>
    inline bool Vector<coordinate_type, dimension>::operator <(const Vector<coordinate_type, dimension>& _other){
        for (size_t i = 0; i < dimension; i++){
            if (coords[i] > _other.coords[i]){
                return false;
            }
        }
        return true;
    }


    template<class coordinate_type, size_t dimension>
    inline bool Vector<coordinate_type, dimension>::operator >(const Vector<coordinate_type, dimension>& _other){
        for (size_t i = 0; i < dimension; i++){
            if (coords[i] < _other.coords[i]){
                return false;
            }
        }
        return true;
    }


    template<class coordinate_type, size_t dimension>
    inline void Vector<coordinate_type, dimension>::assign(int dim, coordinate_type value){
        if (_index >= coords.size()){
            std::cout << "Index out of bounds";
        }
        else {
            coords[dim] = value;
        }
    }
}