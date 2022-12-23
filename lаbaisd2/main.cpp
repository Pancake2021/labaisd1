#include <iostream>
#include "Header.h"
#include <cmath>
#include <complex>
#include <typeinfo>
//


template<typename T>
void GetValueFromUser(std::complex<T>& value)
{
    T real = 0;
    T imag = 0;
    std::cout << "Пожалуйста, введите действительную часть комплексного числа" << std::endl;
    std::cin>>real;
    std::cout << "Пожалуйста, введите мнимую часть комплексного числа" << std::endl;
    std::cin>>imag;
    value.real(real);
    value.imag(imag);
}

template <typename T>
bool IsValueInRange(const T& value, const T& left_border, const T& right_border)
{
    return (value >= left_border && value <= right_border);
}

template <typename T>
void GetValueFromUserInRange(T& value, const T& left_border, const T& right_border, const char* condition = "")
{
    std::cout << condition;
    while (true)
    {
        std::cin>>value;
        if (IsValueInRange(value, left_border, right_border))
        {
            return;
        }
        else
        {
            std::cout << "The value is not in range, try again" << std::endl;
        }
    }
}

template <typename Type_Vectors>
void MenuWorkingWithVector(Vector<Type_Vectors>& vector)
{
    bool working_with_vector = true;
    while (working_with_vector)
    {
        
        std::cout << vector << std::endl;
        std::cout << "Теперь вы редактируете вектор, введите:" << std::endl;
        std::cout << "0 - Изменение элемента по индексу\n1 - Добавление элементов в вектор" << std::endl;
        std::cout << "2 - Деление вектора на число\n3 - умножение вектора на число" << std::endl;
        std::cout << "4 - Удаление элемента по индексу" <<std::endl;
        std::cout << "5 - Вставка элемента по индексу" << std::endl;
        std::cout << "6 - Вывод элемента по индексу\n7 - Завершение работы с вектором" << std::endl;
        int editing_vector = 0;
        GetValueFromUserInRange(editing_vector, (int)0, (int)7, "Введите нужный вам пункт ");
        switch (editing_vector)
        {
            case (0):
            {
                if (vector.GetSize())
                {
                    try {
                        std::cout << "Enter a index of element to edit" << std::endl;
                        int index = 0;
                        std::cin>>index;
                    
                        std::cout << "Enter a new value for the element" << std::endl;
                        Type_Vectors value = 0;
                        std::cin>>value;
                        vector[index] = value;
                    }
                    catch (std::out_of_range& ex)
                    {
                        std::cout << ex.what() << " Try again" << std::endl;
                        
                    }
                }
                break;
            }
            case (1):
            {
                Type_Vectors number;
                std::cout<<"Enter the element: ";
                std::cin>>number;
                vector.PushBack(number);
                break;
            }
            case (2):
            {
                std::cout << "Enter a scalar" << std::endl;
                int scalar = 0;
                std::cin>>scalar;
                try
                {
                    vector /= scalar;
                }
                catch (const char* ex)
                {
                    std::cout << ex << " Try again" << std::endl;
                    
                }
                break;
            }
            case (3):
            {
                std::cout << "Enter a scalar" << std::endl;
                int scalar = 0;
                std::cin>>scalar;
                vector *= scalar;
                std::cout<<vector<<std::endl;
                
                break;
                break;
            }
            case (4):
            {
                if (vector.GetSize())
                {
                    
                    std::cout << "Enter the index of element to delete" << std::endl;
                    int index = 0;
                    std::cin>>index;
                    try
                    {
                        vector.Erase(index);
                    }
                    catch (std::out_of_range& ex)
                    {
                        std::cout << ex.what() << " Try again" << std::endl;
                        
                    }
                }
                else
                {
                    std::cout << "There are no elements to delete" << std::endl;
                }
                    
                break;
            }
            
                /*
                Vector<Type_Vectors> vector2;
                Type_Vectors intermediate_result;
                Type_Vectors result_1;
                if (typeid(intermediate_result) != typeid(int)) {
                    for (int i = 0; i<vector.GetSize(); i++) {
                        vector2.PushBack(1);
                    }
                    
                    for (int i = 0; i<vector.GetSize(); i++) {
                        
                        //intermediate_result = -(vector.operator[](i) * vector2.operator[](i));
                        intermediate_result = -(vector[i] * vector2[i]);
                        result_1 = intermediate_result / vector.operator[](0);
                    }
                    
                    vector2.Insert(result_1, 0);
                    vector2.Erase(vector2.GetSize()-1);
                    
                    Type_Vectors sqr;
                    for (int i = 0; i<vector2.GetSize(); i++) {
                        float inc;
                        //inc += vector2.operator[](i)*vector2.operator[](i);
                        inc += vector2[i]*vector2[i];
                        sqr = sqrt(inc);
                        
                    }
                    Vector<Type_Vectors> vector3;
                    for (int i = 0; i<vector2.GetSize(); i++) {
                        //vector3.PushBack(vector2.operator[](i)/sqr);
                        vector3.PushBack(vector2[i]/sqr);
                    }
                    std::cout<<"Perpendicular vector: ";
                    std::cout<<vector3<<std::endl;
                    std::cout<<"\n\n\n";
                    
                }
                else{
                    std::cout<<"the perpendicular is not calculated"<<std::endl;
                }
                
                break;
                 */
            
           
            case (5):
            {
                try {
                    std::cout<<"Enter the element: ";
                    Type_Vectors InsertNumber;
                    std::cin>>InsertNumber;
                    std::cout<<"Enter the index: ";
                    int InsertIndex;
                    std::cin>>InsertIndex;
                    vector.Insert(InsertNumber, InsertIndex);
                } catch (std::out_of_range& ex) {
                    std::cout << ex.what() << " Try again" << std::endl;
                }
                break;
                
                
            }
            case (6):
            {
                try {
                    std::cout<<"Enter the index: ";
                    int index;
                    std::cin>>index;
                    //std::cout<<vector.operator[](index)]<<std::endl;
                    std::cout<<vector[index]<<std::endl;
                    
                } catch (std::out_of_range& ex) {
                    std::cout << ex.what() << " Try again" << std::endl;
                }
                break;
            }
            case (7)://finish working
            {
                working_with_vector = false;
                break;
            }
                
        }
    }
}

template <typename Type_Vectors>
void MenuWorkingWithVector(Vector<std::complex<Type_Vectors>>& vector)
{
    bool working_with_vector = true;
    while (working_with_vector)
    {
        std::cout << vector << std::endl;
        std::cout << "Теперь вы редактируете вектор, введите:" << std::endl;
        std::cout << "0 - Изменение элемента по индексу\n1 - Добавление элементов в вектор" << std::endl;
        std::cout << "2 - Деление вектора на число\n3 - умножение вектора на число" << std::endl;
        std::cout << "4 - Удаление элемента по индексу" <<std::endl;
        std::cout << "5 - Вставка элемента по индексу" << std::endl;
        std::cout << "6 - Вывод элемента по индексу\n7 - Завершение работы с вектором" << std::endl;
        int editing_vector = 0;
        GetValueFromUserInRange(editing_vector, (int)0, (int)7, "Введите нужный вам пункт ");
        switch (editing_vector)
        {
            case (0):
            {
                if (vector.GetSize())
                {
                    try {
                        std::cout << "Enter a index of element to edit" << std::endl;
                        int index = 0;
                        std::cin>>index;
                    
                        std::cout << "Enter a new value for the element" << std::endl;
                        std::complex<Type_Vectors> value((Type_Vectors)0, (Type_Vectors)0);
                        GetValueFromUser(value);
                        vector[index] = value;
                    }
                    catch (std::out_of_range& ex)
                    {
                        std::cout << ex.what() << " Try again" << std::endl;
                        
                    }
                }
                break;
            }
            case (1):
            {
                std::complex<Type_Vectors> number((Type_Vectors)0, (Type_Vectors)0);
                std::cout<<"Enter the element: ";
                GetValueFromUser(number);
                vector.PushBack(number);
                break;
            }
            case (2):
            {
                std::cout << "Enter a scalar" << std::endl;
                std::complex<Type_Vectors> scalar((Type_Vectors)0, (Type_Vectors)0);
                GetValueFromUser(scalar);
                try
                {
                    vector /= scalar;
                }
                catch (const char* ex)
                {
                    std::cout << ex << " Try again" << std::endl;
                    
                }
                break;
            }
            case (3):
            {
                std::cout << "Enter a scalar" << std::endl;
                std::complex<Type_Vectors> scalar((Type_Vectors)0, (Type_Vectors)0);
                GetValueFromUser(scalar);
                vector *= scalar;
                std::cout<<vector<<std::endl;
                
                break;
                break;
            }
            case (4):
            {
                if (vector.GetSize())
                {
                    
                    std::cout << "Enter the index of element to delete" << std::endl;
                    int index = 0;
                    std::cin>>index;
                    try
                    {
                        vector.Erase(index);
                    }
                    catch (std::out_of_range& ex)
                    {
                        std::cout << ex.what() << " Try again" << std::endl;
                        
                    }
                }
                else
                {
                    std::cout << "There are no elements to delete" << std::endl;
                }
                    
                break;
            }
                
            case (5):
            {
                try {
                    std::cout<<"Enter the element: ";
                    std::complex<Type_Vectors> InsertNumber((Type_Vectors)0, (Type_Vectors)0);
                    GetValueFromUser(InsertNumber);
                    std::cout<<"Enter the index: ";
                    int InsertIndex;
                    std::cin>>InsertIndex;
                    vector.Insert(InsertNumber, InsertIndex);
                } catch (std::out_of_range& ex) {
                    std::cout << ex.what() << " Try again" << std::endl;
                }
                break;
                
                
            }
            case (6):
            {
                try {
                    std::cout<<"Enter the index: ";
                    int index;
                    std::cin>>index;
                   
                    //std::cout<<vector.operator[](index)<<std::endl;
                    std::cout<<vector[index]<<std::endl;
                    
                } catch (std::out_of_range& ex) {
                    std::cout << ex.what() << " Try again" << std::endl;
                }
                break;
            }
            case (7)://finish working
            {
                working_with_vector = false;
                break;
            }
                
        }
    }
}

template <typename Type_Vectors>
void Menu(Type_Vectors)
{
    bool function_is_working = true;
    Vector<Type_Vectors> first_vector;
    Vector<Type_Vectors> second_vector;
    while (function_is_working)
    {
        std::cout << "First vector:" << first_vector << std::endl;
        std::cout << "\nSecond vector:" << second_vector << std::endl;
        std::cout << "Enter:\n0 - для работы и редактирования с одним вектором" << std::endl;
        std::cout << "1 - для суммирования двух векторов\n2 -чтобы вычесть второй вектор из первого" << std::endl;
        std::cout << "3 - для вычисления скалярного произведения двух векторов\n "<< std::endl;
        std::cout << "4 - Вчислить площадь между двумя векторами\n" << std::endl;
        std::cout << "5 - очистите два вектора" << std::endl;
        std::cout << "6 - Выведите, равны ли два вектора или нет\n7 - сделайте первый вектор равным второму\n";
        std::cout << "8 - закончите работу с векторами" << std::endl;
        int action = 0;
        GetValueFromUserInRange(action, (int)0, (int)8, "\nВвеберете нужный вам пункт");
        switch (action)
        {
        case (0):
        {
            int order_number = 0;
            GetValueFromUserInRange(order_number, (int)1, (int)2, "Enter the order number of vector you wanted to edit");
            
            if (order_number == 1)
            {
                MenuWorkingWithVector(first_vector);
            }
            else
            {
                MenuWorkingWithVector(second_vector);
            }
            break;
        }
        case (1):
        {
            try
            {
                Vector<Type_Vectors> sum = first_vector + second_vector;
                std::cout << sum;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case (2):
        {
            try
            {
                Vector<Type_Vectors> subtraction = first_vector - second_vector;
                std::cout << subtraction;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case (3):
        {
            try
            {
                Type_Vectors scalar_product = first_vector.DotProduct(second_vector);
                std::cout << scalar_product << std::endl;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
            case (4):
            {
                Type_Vectors scalar_product = first_vector.DotProduct(second_vector);
                std::cout << "scalar" << " " <<scalar_product << std::endl;
                                
                Type_Vectors kvad1 = first_vector.duct(first_vector);
                                
                std::cout << "the first squares" <<  " " <<kvad1 << std::endl;
                Type_Vectors kvad2 = second_vector.duct(second_vector);
                                
                std::cout << "second squares" << " " << kvad2 << std::endl;
                Type_Vectors krvad = (scalar_product)/((sqrt(kvad1) * sqrt(kvad2)));
                std::cout << "cosine" <<  " " <<krvad << std::endl;
                Type_Vectors sin = sqrt (1 - (krvad*krvad));
                                
                std::cout << "sin"  << " " << sin << std::endl;
                Type_Vectors s = 0.5 * sin * sqrt(kvad1) * sqrt(kvad2);
                std::cout << "Square" << s << std::endl;
                break;
            }
        case (5):
        {
            first_vector.Clear();
            second_vector.Clear();
            break;
        }
        case (6):
        {
            first_vector == second_vector ? std::cout << "Vectors are equal" << std::endl :
                std::cout << "Vectors are different" << std::endl;
            
            break;
        }
        case (7):
        {
            first_vector = second_vector;
            break;
        }
        case (8):
        {
            function_is_working = false;
            break;
        }

        }
        
    }
}

template <typename Type_Vectors>
void Menu(std::complex<Type_Vectors>)
{
    bool function_is_working = true;
    Vector<std::complex<Type_Vectors>> first_vector;
    Vector<std::complex<Type_Vectors>> second_vector;
    while (function_is_working)
    {
        std::cout << "First vector:" << first_vector << std::endl;
        std::cout << "\nSecond vector:" << second_vector << std::endl;
        std::cout << "Enter:\n0 - для работы и редактирования с одним вектором" << std::endl;
        std::cout << "1 - для суммирования двух векторов\n2 -чтобы вычесть второй вектор из первого" << std::endl;
        std::cout << "3 - для вычисления скалярного произведения двух векторов\n "<< std::endl;
        std::cout << "4 - Вчислить площадь между двумя векторами\n" << std::endl;
        std::cout << "5 - очистите два вектора" << std::endl;
        std::cout << "6 - Выведите, равны ли два вектора или нет\n7 - сделайте первый вектор равным второму\n";
        std::cout << "8 - закончите работу с векторами" << std::endl;
        int action = 0;
        GetValueFromUserInRange(action, (int)0, (int)8, "\nВвеберете нужный вам пункт");
        switch (action)
        {
        case 0:
        {
            int order_number = 0;
            GetValueFromUserInRange(order_number, (int)1, (int)2, "Enter the order number of vector you wanted to edit");
            
            if (order_number == 1)
            {
                MenuWorkingWithVector(first_vector);
            }
            else
            {
                MenuWorkingWithVector(second_vector);
            }
            break;
        }
        case 1:
        {
            try
            {
                Vector<std::complex<Type_Vectors>> sum = first_vector + second_vector;
                std::cout << sum;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case 2:
        {
            try
            {
                Vector<std::complex<Type_Vectors>> subtraction = first_vector - second_vector;
                std::cout << subtraction;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case 3:
        {
            try
            {
                std::complex<Type_Vectors> scalar_product = first_vector.DotProduct(second_vector);
                std::cout << scalar_product << std::endl;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case 4:
            {
                
                std::complex<Type_Vectors> scalar_product((Type_Vectors)0, (Type_Vectors)0);
                std::complex<Type_Vectors> kvad1((Type_Vectors)0, (Type_Vectors)0);
                std::complex<Type_Vectors> kvad2((Type_Vectors)0, (Type_Vectors)0);
                std::complex<Type_Vectors> prom((Type_Vectors)0, (Type_Vectors)0);
                std::complex<Type_Vectors> prom2((Type_Vectors)0, (Type_Vectors)0);
                std::complex<Type_Vectors> sin((Type_Vectors)0);
                
                std::complex<Type_Vectors> s((Type_Vectors)0, (Type_Vectors)0);
                std::complex<Type_Vectors> promres((Type_Vectors)0, (Type_Vectors)0);
                
                scalar_product = first_vector.DotProduct(second_vector);
                std::cout << "скалярное" << scalar_product << std::endl;
                
                
                kvad1 = first_vector.DotProduct(first_vector);
                                
                std::cout << "the first squares" <<  " " <<kvad1 << std::endl;
                kvad2 = second_vector.DotProduct(second_vector);
                
                prom = (scalar_product)/((sqrt(kvad1) * sqrt(kvad2)));
                prom2 = prom;
                
                promres = (prom.real()*prom2.real() - prom.imag()*prom2.imag()) + (prom.real()*prom2.imag() - prom.imag()*prom2.real());
                //std::cout<<promres << std::endl;
                double cos_alfa = multiple(first_vector,second_vector) / (first_vector.GetSize() * second_vector.GetSize());
                double sin_alfa = std::sqrt(1 - std::pow(cos_alfa, 2));
                //sin = std::sqrt (1 - (promres.real()));
                std::cout << "синус" << sin_alfa<< std::endl;
                std::cout << "cos" << cos_alfa<< std::endl;
                
                double square = first_vector.GetSize() * second_vector.GetSize() * sin_alfa / 2;
                
                std::cout << "S" << square<< std::endl;
                                
              //  std::cout << "sin"  << " " << sin << std::endl;
                //s = 0.5 * sin.real() * sqrt(kvad1) * sqrt(kvad2);
                //std::cout << "Square" << s << std::endl;
                
//                std::complex  <double> kvad2 = second_vector.DotProduct(second_vector);
//
//                std::complex  <double> prom = (scalar_product)/((sqrt(kvad1) * sqrt(kvad2)));
//                std::cout << "пром" << prom << std::endl;
//
//                std::cout << "пром"  << std::endl;
//                std::cout << "пром"  << std::endl;
//
                break;
        }
        case 5:
        {
            first_vector.Clear();
            second_vector.Clear();
            break;
        }
        case 6:
        {
            first_vector == second_vector ? std::cout << "Vectors are equal" << std::endl :
                std::cout << "Vectors are different" << std::endl;
            
            break;
        }
        case 7:
        {
            first_vector = second_vector;
            break;
        }
        case 8:
        {
            function_is_working = false;
            break;
        }

        }
        
    }
}




int main()
{
    bool working_with_vectors = true;
    while (working_with_vectors)
    {
        std::cout << "Enter:\n0 - to work <int>" << std::endl;
        std::cout << "1 - to work <float>" << std::endl;
        std::cout << "2 - to work r<double>" << std::endl;
        std::cout << "3 - to work <std::complex<float>>" << std::endl;
        std::cout << "4 - to work <std::complex<double>>" << std::endl;
        std::cout << "5 - to finish working with program" << std::endl;
        int option = 0;
        GetValueFromUserInRange(option, 0, 5);
        switch (option)
        {
            case 0:
            {
                Menu(0);
                std::cout << "int" << std::endl;
                break;
            }
            case 1:
            {
                Menu((float)0.0);
                std::cout << "float" << std::endl;
                break;
            }
            case 2:
            {
                Menu(0.0);
                std::cout << "double" << std::endl;
                break;
            }
            case 3:
            {
                Menu(std::complex<float>(0, 0));
                std::cout << "std::complex<float>" << std::endl;
                break;
            }
            case 4:
            {

                Menu(std::complex<double>(0, 0));
                std::cout << "std::complex<double>" << std::endl;
                break;
            }
            case 5:
            {
                working_with_vectors = false;
                break;
            }
        }
    }
}


