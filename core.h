

#include "precision.h" 

namespace cyclone {

    class Vector3 {
    public:
        // Values inside of each vector (A 3d Vector duh)  
        real x;
        real y;
        real z;

    private:
        // Used for memory optimization  
        real pad;
    
    public:

        // Constructor (Empty)
        Vector3() : x(0), y(0), z(0) {}

        // Constructor (Assigned values)
        Vector3(real x, real y, real z) : x(x), y(y), z(z) {}


        // Inverts the Vector 
        void invert() 
        {
            x = -x; 
            y = -y; 
            z = -z;
        }

        //---------------------------------------------------------------

        // Magnitude of the vector
        real magnitude() const
        {
            return real_sqrt(x*x + y*y + z*z);
        }

        // Square magnitude of the vector (Since it doesn't take the Sqrt)
        real squareMagnitude() const
        {
            return x*x + y*y + z*z;
        }

        // Calculates the unit vector
        void normalize()
        {
            real l = magnitude();
            if (l > 0){
            (*this) *= ((real)1)/l;
            }
        }

        // Adds a vector that was previously multiplied by a scalar
        void addScaledVector(const Vector3& v, real scale)
        {
            x += v.x * scale ;
            y += v.y * scale ;
            z += v.z * scale ;

        }

        //---------------------------------------------------------------
        //HADAMARD PRODUCT/COMPONENT-WISE PRODUCT 

        // Changes vector:
        void componentProductUpdate(const Vector3 &vector) //why does the book change the style of referencing? IDK
        {
            x *= vector.x; 
            y *= vector.y;
            z *= vector.z;
        }

        // Returns new vector:
        Vector3 componentProduct(const Vector3 &vector) const 
        {
            return Vector3(x * vector.x, y * vector.y, z * vector.z);
        }

        //---------------------------------------------------------------
        // SCALES THE VECTOR BY A VALUE

        //Changes vector:
        void operator *= (const real value)
        {
        x *= value;
        y *= value;
        z *= value;
        }

        // Returns new vector:
        Vector3 operator*(const real value) const
        {
        return Vector3(x*value, y*value, z*value);
        }

        //---------------------------------------------------------------
        //ADDS THE VECTOR WITH ANOTHER

        // Changes vector:
        void operator += (const Vector3& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
        }

        // Returns new vector:
        Vector3 operator+(const Vector3& v) const
        {
        return Vector3(x+v.x, y+v.y, z+v.z);
        }

        //---------------------------------------------------------------
        //SUBSTRACT THE VECTOR BY A VALUE:

        // Changes vector:
        void operator -= (const Vector3& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
        }

        // Returns new vector:
        Vector3 operator-(const Vector3& v) const
        {
        return Vector3(x-v.x, y-v.y, z-v.z);
        }

        //---------------------------------------------------------------
        //DOT PRODUCT/SCALAR PRODUCT (Returns a Scalar not a VECTOR):

        real scalarProduct(const Vector3& vector) const
        {
            return (x * vector.x, y * vector.y, z * vector.z);
        }

        real operator *(const Vector3 &vector) const
        {
        return x*vector.x + y*vector.y + z*vector.z;
        }
        
        //---------------------------------------------------------------

    };
}