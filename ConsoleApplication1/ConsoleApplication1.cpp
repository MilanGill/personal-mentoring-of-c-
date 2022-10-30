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
        
        Coord_Type& operator [] (int k) 
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

                }
                else
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
         const Coord_Type& operator [] (int k) const
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

static int M = 0;

void sqr_array2(int a[], int n) {
    for (int i = 0; i < n; i+=4, a[i]/=M)
    {
        a[i] = a[i] + a[i];
        a[i+1] = a[i+1] + a[i+1];
        a[i + 2] = a[i + 2] + a[i + 2];
        a[i + 3] = a[i + 3] + a[i + 3];
    }
}

void sqr_array (int a[], int n) {
    for (int i = 1; i < n; i++, a[i]/=M)
    {
        a[i] = a[i] + a[i];
    }
}
const int l = 1000;
static int a[l];
class Init 
{public:
    Init() { for (int i = 0; i < l; i++) a[i] = 5; }
    
};


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
    array_mult(a, na, 0);
    __int64 t0 = clk();

    sqr_array(a, l);

    __int64 t = clk();
    delete[] a;
    __int64 Dt = t - t0;
    cout << "Время = " << Dt <<" клоков = " <<double (Dt)/(1000*1000*1000) <<" секунд на 1 ГГЦ процессора" <<"\n" <<
    double (Dt)/l << " клоков на сэмпл." << "\n";
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


template <typename T>
class Array_Interface
{public:
    virtual ~Array_Interface() {}
    virtual T& operator [] (int k) = 0;
    virtual const T& operator [] (int k) const = 0;

    virtual int size() = 0;
    virtual void add(const T& element) = 0;
    virtual void insert(int i, const T& element) = 0;
    virtual void remove(int i, int n = 0) = 0;
    virtual void add_array(const Array_Interface<T>& other_array) = 0;
    virtual void insert_array(int i,const Array_Interface<T>& other_array) = 0;
    virtual void on_error(const char * message) = 0;
};

template <typename T>
class Array : public Array_Interface<T>
{
private :
    T* a;
    int n;
    T& safe_element(int k) 
    {
#ifdef _DEBUG 
        if (k < 0) on_error("\n k<0 !!!!!!!!!!!!!!!!!!!!!!!!!!!! \n");
        else if (k >= n) on_error("\n k >= n !!!!!!!!!!!!!!!!!!! \n");
#else

#endif
        return a[k];
    }
public:
    Array() : a(nullptr), n(0) {}
    Array(int n, bool zero = true) : a(nullptr), n(0) {
        if (n <= 0) {
            on_error("You put size <= 0");
            return;
        }
        a = ::new T[n];
        this->n = n;
        if (zero) 
            for (int i = 0; i < n; i++) {
                a[i] = T();
            }
        
    }

    virtual ~Array() {
        if (a) {
            delete[]a;
            a = nullptr;
        }
    }
    virtual T& operator [] (int k) {
        return safe_element(k);
    }
    virtual const T& operator [] (int k) const {
        return ((Array&)(*this)).safe_element(k);
    }
    template <typename T_>
    Array& operator = (const Array_Interface<T_>& other_array) {
        this -> ~Array();
        
        return *this;
    }

    
    virtual int size() {
        return n;
    }
protected:
    virtual void add(const T& element) {
        a[n] = element;
    }
    virtual void insert(int i, const T& element) {
        a[i] = element;
    }
    virtual void remove(int i, int n) {
        for (i; i < n; i++) {
            a[i] = a[i + 1];
        }
    }
    virtual void add_array(const Array_Interface<T>& other_array) {
        for (int i = n; i <= 2 * n; i++) {
            a[i] = other_array[i-n];
        }
    }
    virtual void insert_array(int i, const Array_Interface<T>& other_array) {
        int n2 = sizeof(other_array)/sizeof(other_array[0]);
        for (int j = n ; j < n + n2; j++) {
            a[i] = a[i - n2];
        }
        for (int j = 0 ; j < n2; j++) {
            a[i] = other_array[j];
            i++;
        }
    }
    virtual void on_error(const char* message) {
        cout << message << '\n';
        std::runtime_error err(message);
    }
};

template <typename T>
class Array_ : public Array<T>
{
public:
    virtual ~Array_() {}
    virtual T& operator [] (int k) {}
    virtual const T& operator [] (int k) const {}
};
#if 0
    virtual int size()
    virtual void add(const T& element) {}
    virtual void insert(int i, const T& element) {}
    virtual void remove(int i, int n = 0) {}
    virtual void add_array(const Array_Interface<T>& other_array) {}
    virtual void insert_array(int i, const Array_Interface<T>& other_array) {}
};
#endif

class Test_My_Array {
public:
    Test_My_Array() {
        Array<int> a(100);
        cout << a[99] << '\n';
        const Array<int> b(10);
        cout << b[20];
    }
}Test;



// 1 - примеры |массив, матрица|
// 2 - общее |интерфейсы, виртуальные функции и т.д + виртуальный диструктор|
// 3 - Темплейты?
// 4 - Windows Приложения 


// Домашнее задание : 
// Доделать Array и Array_ (+ проверить как все работает)


// Я написал методы только для обычного массива