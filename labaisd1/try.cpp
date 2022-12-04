#include "try.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>

class Vector {
private:
    size_t size = 0;
    double* value = nullptr;
public:

    size_t GetSize() const{
        return size;
    }

    Vector(size_t SIZE, double* VALUE) : size(SIZE), value(new double[SIZE]) {
        memcpy(value, VALUE, sizeof(double) * size);
    }

    Vector(size_t SIZE) : size(SIZE), value(new double[SIZE]) {
        memset(value, 0, sizeof(double) * size);
    }
    
    Vector(const Vector& v) : size(v.size), value(new double[v.size]) {
        memcpy(value, v.value, sizeof(double) * size);
    }

    ~Vector() {
        delete[] value;
    }

    void swap(Vector& v) {
        std::swap(size, v.size);
        std::swap(value, v.value);
    }

    Vector& operator =(Vector a) {   //кидаю сразу копию, чтоб не создавать ее лишний раз
        swap(a);
        return *this;
    }

    Vector& operator +=(const Vector& v) {
        if (size != v.size) throw 1;
        for (int i = 0; i < size; i++) {
            value[i] += v.value[i];
        }
        return *this;
    }

    Vector& operator -=(const Vector& v) {
        if (size != v.size) throw 1;
        for (int i = 0; i < size; i++) {
            value[i] -= v.value[i];
        }
        return *this;
    }

    Vector& operator *=(double scalar) {
        for (int i = 0; i < size; i++) {
            value[i] *= scalar;
        }
        return *this;
    }

    Vector& operator /=(double scalar) {
        if (scalar == 0.0) throw 1;
        for (int i = 0; i < size; i++) {
            value[i] /= scalar;
        }
        return *this;
    }


    //• оператор [] для чтения/записи элемента вектора по указанному индексу;
    double& operator[](size_t index) {
        if (index >= size) throw 1;
        return value[index];
    }

    const double& operator[](size_t index) const {
        if (index >= size) throw 1;
        return value[index];
    }


    Vector operator*(double scalar) {
        Vector copy(size, value);
        copy *= scalar;
        return copy;
    }
};

//• операторы сложения и вычитания векторов;
Vector operator+(const Vector& v1, const Vector& v2) {
    if (v1.GetSize() != v2.GetSize()) throw 1;
    Vector copy = v1;
    copy += v2;
    return copy;
}

Vector operator-(const Vector& v1, const Vector& v2) {
    if (v1.GetSize() != v2.GetSize()) throw 1;
    Vector copy = v1;
    copy -= v2;
    return copy;
}

//• оператор умножения, выполняющий скалярное произведение векторов;
double operator*(const Vector& v1, const Vector& v2) {
    if (v1.GetSize() != v2.GetSize()) throw 1;
    double result = 0;
    for (int i = 0; i < v1.GetSize(); i++) {
        result+= v1[i]* v2[i];
    }
    return result;
}

//• оператор умножения вектора на скаляр(обеспечить коммутативность);
Vector operator*(const Vector& v, double scalar) {
    Vector copy = v;
    copy *= scalar;
    return copy;
}

Vector operator*(double scalar, const Vector& v) {
    Vector copy = v;
    copy *= scalar;
    return copy;
}

//• оператор деления вектора на скаляр.
Vector operator/(const Vector& v, double scalar) {
    Vector copy = v;
    copy /= scalar;
    return copy;
}

std::ostream& operator <<(std::ostream& out, const Vector& v) {
    out << "(";
    for (int i = 0; i < v.GetSize(); i++) {
        out << v[i];
        if (i != v.GetSize() - 1) out << ", ";
    }
    out << ")" << "\n";
    return out;
}

bool is_equal(double x, double y) {
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
    // epsilon возвращает разницу между 1 и наименьшим значением больше 1, которое этот тип данных может представлять
}


bool operator ==(const Vector& v1, const Vector& v2) {
    if (v1.GetSize() != v2.GetSize()) throw 1;
    for (int i = 0; i < v1.GetSize(); i++) {
        if (!is_equal(v1[i], v2[i])) return false;
    }
    return true;
}

bool operator !=(const Vector& v1, const Vector& v2) {
    return!(v1 == v2);
}

//Задача: Посчитать площадь треугольника, две стороны которого заданы радиус - векторами a и b.
double vector_len(const Vector& v) {
    double len = 0.0;
    for (int i = 0; i < v.GetSize(); i++) {
        len += pow(v[i], 2);
    }
    return sqrt(len);
}

double get_square(const Vector& v1, const Vector& v2) {
    double cos_alfa = (v1 * v2) /((vector_len(v1) * vector_len(v2)));
    double sin_alfa = sqrt(1 - pow(cos_alfa, 2));
    double square = vector_len(v1) * vector_len(v2) * sin_alfa / 2;
    return square;
}

int main()
{

    double* d = new double[4];
    double* c = new double[4];
    for (int i = 0; i < 4; i++) {
        d[i] = 6.23 * i;
        c[i] = 2.44 * i;

    }

    double a[2] = { 1,1};
    double b[2] = { 0,1};
    Vector v1(2, a);
    Vector v2(2, b);
    //if (v1 != v2) {
    //    std::cout << "true\n";
    //}
    //else {
    //    std::cout << "false\n";
    //}
    std::cout << v1;
    std::cout << v2;

    std::cout << get_square(v1, v2) << std::endl;;



    //std::cout << v1*2;
    //std::cout << 2 * v1;


    //try {
    //    Vector v3 = v1 + v2;
    //    std::cout << v3;
    //}
    //catch (...) {
    //    std::cout << "error" << std::endl;
    //}

}
