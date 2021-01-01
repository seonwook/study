#include <iostream>

class Car
{
private:
    int gasolineGauge;
public:
    Car() : gasolineGauge(10)
    {
        std::cout<<"Car() : "<<gasolineGauge<<std::endl;
    }
    Car(int Gas) : gasolineGauge(Gas)
    {
        std::cout<<"Car(int Gas) : "<<gasolineGauge<<std::endl;
    }
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar() : electricGauge(10)
    {
        std::cout<<"HybridCar() : "<<electricGauge<<std::endl;
    }
    HybridCar(int electric) : electricGauge(electric)
    {
        std::cout<<"HybridCar(int Gas, int electric) : "<<electricGauge<<std::endl;
    }
    HybridCar(int Gas, int electric) 
        : Car(Gas), electricGauge(electric)
    {
        std::cout<<"HybridCar(int Gas, int electric) : "<<electricGauge<<std::endl;
    }
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar() : waterGauge(10)
    {
        std::cout<<"HybridWaterCar() : "<<waterGauge<<std::endl;
    }
    HybridWaterCar(int water) : waterGauge(water)
    {
        std::cout<<"HybridWaterCar(int n) : "<<waterGauge<<std::endl;
    }
    HybridWaterCar(int electric, int water) : HybridCar(electric),waterGauge(water)
    {
        std::cout<<"HybridWaterCar(int electric, int water) : "<<waterGauge<<std::endl;
    }
    HybridWaterCar(int gas,int electric, int water) : HybridCar(gas,electric),waterGauge(water)
    {
        std::cout<<"HybridWaterCar(int electric, int water) : "<<waterGauge<<std::endl;
    }
    void ShowCurrentGauge()
    {
        std::cout<<"잔여 가솔린 : "<<GetGasGauge()<<std::endl;
        std::cout<<"잔여 전기량 : "<<GetElecGauge()<<std::endl;
        std::cout<<"잔여 워터량 : "<<waterGauge<<std::endl<<std::endl;
    }
};

int main(void)
{
    HybridWaterCar car1;
    car1.ShowCurrentGauge();
    HybridWaterCar car2(20);
    car2.ShowCurrentGauge();
    HybridWaterCar car3(20,30);
    car3.ShowCurrentGauge();
    HybridWaterCar car4(20,30,40);
    car4.ShowCurrentGauge();
    return 0;
}