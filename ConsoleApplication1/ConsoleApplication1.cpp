#include <iostream>
#include <conio.h>
#include <limits.h>
#include <algorithm>
#include <string>
#include <random>



using namespace std;
#if defined (_WIN64) || defined (_DEBUG)
__int64 __cdecl clk()
{
    return 0;
}
#else 

__int64 __cdecl clk()
{
    _asm{rdtsc}

}

#endif
// Функция умножения всех элементов массива на k. ТЭМПЛЕЙТЫ
template <typename T>
void array_mult(T* a, const int l, T k)
{
   for (T* p = a, *q=(a+l); p < q; p++)
   {
       *p = (*p) * k;
   }
   
}

template <typename T>
class Smart_Reference
{
private:
    static T*& p()
    {
        static T* ptr = nullptr;
        return ptr;
    }
    static long long& count()
    {
        static long long c = 0;
        return c;
    }
public:
    T& operator = (const T& x)
    {
        *p() = x;
        return *this;
    }
    operator T&()
    {
        return *p();
    }
    Smart_Reference()
    {
        if (count() == 0)
            p() = new T();
        count()++;
    }
    ~Smart_Reference()
    {
        if (count() > 0)
            count()--;
        if (count() == 0)
        {
            delete p();
            p() = nullptr;
        }
    }
};

class Oleg
{
public:
    Oleg()
    {
        Smart_Reference<int> i;
        Smart_Reference<int> j;
        cout << i << " , " << j << "\n";
        i += 2;
        cout << i << " , " << j << "\n";
        j *= 5;
        cout << i << " , " << j << "\n";
        i = i + 2 * j;
        cout << i << " , " << j << "\n";
        cout << "-----------------------------------------------------------------------------\n";
        char* p = nullptr;
        /*cout << p;*/

        // НАСТОЯЩИЕ РАНДОМНЫЕ ЧИСЛА 
        /*std::random_device crypto_random_generator;
        std::uniform_int_distribution<int> int_distribution(0, 9);

        int actual_distribution[10] = { 0,0,0,0,0,0,0,0,0,0 };

        for (int i = 0; i < 10000; i++) {
            int result = int_distribution(crypto_random_generator);
            actual_distribution[result]++;
        }

        for (int i = 0; i < 10; i++) {
            std::cout << actual_distribution[i] << " ";
        }*/

    }
}oleg;
////template<>
////void array_mult(int* a, const int l, int k)
//{
//    _asm
//    {
//        mov ebx, a
//        mov ecx, l
//        mov edx, k
//        push ebp
//    }
//loop:
//    _asm
//    {
//            mov eax, [ebp]
//            mov ebx, [ebp + 4]
//            mul edx
//            mov [ebp], eax
//            mov eax, ebx
//            mul edx
//
//            add ebx, 8
//            sub ecx, 2
//        jg loop
//        pop ebp
//    }
//}






namespace Geometry
{
#if 0
    class Vector
    {
    public:
        double x, y, z;
        Vector() : x(0), y(0), z(0) {}
        Vector(double X, double Y, double Z) : x(X), y(Y), z(Z) {}
        Vector(const Vector& v) : x(v.x), y(v.y), z(v.z) {}
        Vector& operator = (const Vector& v)
        {
            x = v.x; y = v.y; z = v.z;

            return *this;
        }
        Vector operator - () const
        {
            return Vector(-x, -y, -z);
        }

        void print(const char* postsfix = " ") const
        {
            std::cout << "( " << x << " , " << y << " , " << z << " )" << postsfix;
        }

        double norm() const
        {
            return sqrt(x * x + y * y + z * z);
        }


    } v0;

    Vector operator + (const Vector& a, const Vector& b)
    {
        Vector c(a.x + b.x, a.y + b.y, a.z + b.z);
        return c;
    }

    double operator * (const Vector& a, const Vector& b) //dot product
    {
        double res = 0;
        res = a.x * b.x + a.y * b.y + a.z * b.z;
        return res;
    }

    Vector operator - (const Vector& a, const Vector& b)
    {
        return Vector((a.x - b.x), (a.y - b.y), (a.z - b.z));
    }

#endif
    
    template <typename Coord_Type>
    class Vector3D
    {
    public:
        Coord_Type x, y, z;
        Vector3D() : x(0), y(0), z(0) {}
        Vector3D(Coord_Type X, Coord_Type Y, Coord_Type Z) : x(X), y(Y), z(Z) {}
        Vector3D(const Vector3D& v) : x(v.x), y(v.y), z(v.z) {}
        Vector3D& operator = (const Vector3D& v)
        {
            x = v.x; y = v.y; z = v.z;

            return *this;
        }
        Vector3D operator - () const
        {
            return Vector3D(-x, -y, -z);
        }

         Coord_Type operator [] (int k) const
        {
            
            if (k == 0) 
            { 
                return x;
                
            }
            else 
            {
                if (k == 1)
                {
                    return y;
                    
                } else 
                {
                    if (k == 2)
                    {
                        return z;
                    }
                    else
                    {
                        
                    }
                }
            }
        }

        void print(const char* postsfix = " ") const
        {
            std::cout << "( " << x << " , " << y << " , " << z << " )" << postsfix;
        }

        double norm() const
        {
            return sqrt(x * x + y * y + z * z);
        }


    } ;

    template <typename Coord_Type>
    Vector3D<Coord_Type> operator + (const Vector3D<Coord_Type>& a, const Vector3D<Coord_Type>& b)
    {
        Vector3D<Coord_Type> c(a.x + b.x, a.y + b.y, a.z + b.z);
        return c;
    }
    template <typename Coord_Type>
    Coord_Type operator * (const Vector3D<Coord_Type>& a, const Vector3D<Coord_Type>& b) //dot product
    {
        Coord_Type res = 0;
        res = a.x * b.x + a.y * b.y + a.z * b.z;
        return res;
    }
    template <typename Coord_Type>
    Vector3D<Coord_Type> operator - (const Vector3D<Coord_Type>& a, const Vector3D<Coord_Type>& b)
    {
        return Vector3D<Coord_Type>((a.x - b.x), (a.y - b.y), (a.z - b.z));
    }

    typedef Vector3D <double> Vector;
}

class Klient
{   
public:
    Klient(const char* _name):name(_name),id(rand())
    {
        quantity++;
    }
    ~Klient()
    {
        quantity--;
    }
    int id;
    
    static int quantity;
    static int tablo;
    static void peoples_print()
    {
        std::cout << "Количество людей в шаверме = " << quantity << " \n";
    }
     const char*  name; 

};

int Klient::quantity = 0;

int function(int argument) 
{

    Klient& kl3 = *new Klient("Фантомас");
    Klient kl1("Милан");
    Klient kl2("Сергей");
    kl1.peoples_print();
    cout << "\n";
    cout << "Имя первого клиента - " << kl1.name << "  || " << "Номер заказа - " << kl1.id << "\n";
    cout << "Имя второго клиента - " << kl2.name << " || " << "Номер заказа - " << kl2.id << "\n";
    cout << "Имя третьего клиента - " << kl3.name << " || " << "Номер заказа - " << kl3.id << "\n";
    cout << "\n";
    delete &kl3;
    kl1.peoples_print();
    const int na = 1000 * 1000;
    int* a = new int[na];
    memset(a, 0 , sizeof(a[0]) * na);
    __int64 t0 = clk();
    array_mult(a, na, 0);

    __int64 t = clk();
    delete[] a;
    __int64 Dt = t - t0;
    cout << "Время = " << Dt <<" клоков = " <<double (Dt)/(1000*1000*1000) <<" секунд на 1 ГГЦ процессора" <<"\n" <<
    double (Dt)/na << " клоков на сэмпл." << "\n";
    cout << "\n";
    cout << "\n";

    using namespace Geometry;
    Vector v = Vector3D<double>(0, 3, 4);
    Vector u = v;
    u.print("\n");   // Печатаем вектор u
    cout << u.norm() << "\n";
    Vector w = u = Vector(0,0,0);
    u.print("\n");
    Vector sum = v + v;
    sum.print("\n");
    double size = sum.norm();
    cout << size << "\n";
    (-sum).print("\n");
    cout << "Скалярное произведение векторов(sum,v) = " << sum * v << "\n";
    cout << "Разность векторов (sum,v) это вектор - ";
    (sum - v).print("\n");
    using namespace std;
    cout << sum[1]; 
    return 12;
}

int max(int array[], int length)
{
    int M = std::numeric_limits<int>::min();
    for (int i = 0 ; i < length; i = i++) 
    {
        if (M < array[i])
        {
            M = array[i];
        }
    }
    return M;
}

double arithmetic_mean(int array[], int length)
{
    double sum = 0; 
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / length; 
}
double median(int array[], int length)
{
    double mediana = 0;
    std::sort(array, array + length);   // Сортировка массива по возрастанию быстрой сортировкой 
    if (length % 2 == 0)
    {
        mediana = (array[(length-1)/2] + array[(length-1)/2 + 1]) / 2;
    } else 

    {
        mediana = array[(length-1)/2];
    }
    return mediana;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    function(1);
    //std::cout << "Результат функции умножения на 12 = " << i << '\n';
   // std::cout << "Введите количество элементов массива" << '\n';
    //std::cout << "Введите элементы массива через пробел" << '\n';
  //  int n;
    //std::cin >> n;
   // int* a;   // int* a - Создание динамического массива
   // a = new int[n];
//    for (int i = 0; i < n; i++)
   // {
       // std::cin >> a[i];           
  //  }
  //  int M = max(a, n);
  //  double middle  = arithmetic_mean(a, n);
    //std::cout << "Максимум Массива = " << M << '\n' <<"Среднее арефмитическое Массива " << middle << '\n';
   // double med = median(a, n);
   // std::cout << "Медиана Массива= " << med;
    _getch();
}




// Попробовать анролинг на C 
// 