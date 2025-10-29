

#include "precision.h" 

namespace cyclone {

    class Vector3 {
    public:
        real x;
        real y;
        real z;

    private:
        real pad;
    
    public:
        Vector3() : x(0), y(0), z(0) {}
        Vector3(real x, real y, real z) : x(x), y(y), z(z) {}

        
        void invert() {
            x = -x; 
            y = -y; 
            z = -z;
        }
        real magnitude() const{
            return real_sqrt(x*x + y*y + z*z);
        }

        real squareMagnitude() const{
            return x*x + y*y + z*z;
        }
        void normalize(){
            real l = magnitude();
            if (l > 0){
            (*this) *= ((real)1)/l;
            }
        }
       void operator *= (const real value){
        x *= value;
        y *= value;
        z *= value;
        }

        Vector3 operator*(const real value) const{
        return Vector3(x*value, y*value, z*value);
        }

    };
}