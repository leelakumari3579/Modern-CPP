/*
    rule of 0: if you dont have special reason dont change compiler specification(dont change constructors, 0 member functions , etc)
    rule of 3: if you change destructor have to change copy constructor and copy assignment apropriately.
    rule of 5:(during optimizations) if you use 3rd rule have to change move constructor and move assignment.
*/

class Vehicle
{
private:
    int *_readingsArray;
    int _vehicleId;
    int _size;

public:
    Vehicle() = default;
    Vehicle(int *readings, int id, int size) : _vehicleId(id)
    {
        _readingsArray = new int[size];
        _size = size;
        for (int i = 0; i < size; i++)
        {
            _readingsArray[i] = readings[i];
        }
    }

    Vehicle(const Vehicle &rhs)
    {
        // new object's reading size=old object's reading size
        this->_size = rhs._size;
        this->_vehicleId = rhs._vehicleId;
        // this->_readingsArray=rhs._readingsArray; //shollow copy
        this->_readingsArray = new int[rhs._size]; 

        for (int i = 0; i < _size; i++)
        {
            this->_readingsArray[i] = rhs._readingsArray[i];
        } // deep copy
    }
    Vehicle &operator=(const Vehicle &rhs)
    {
        this->_size = rhs._size;
        this->_vehicleId = rhs._vehicleId;
        this->_readingsArray = new int[rhs._size];

        for (int i = 0; i < _size; i++)
        {
            this->_readingsArray[i] = rhs._readingsArray[i];
        }
        return *this;
    }
    ~Vehicle()
    {
        delete [] _readingsArray;
    }
};

int main()
{
}