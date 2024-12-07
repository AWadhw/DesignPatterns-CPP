#include "subject.h"
#include <memory>

#include <iostream>

void WeatherData::registerObserver(IObserver* observer) 
{
    this->obsList.push_back(observer);
    std::cout << "number of observers is: " <<
        obsList.size() << std::endl;
}

void WeatherData::removeObserver(IObserver* observer) const
{
    std::cout << "Lol we do not have a remove method yet \n";
}

void WeatherData::notifyObservers() const
{
    for (auto observer : obsList)
    {
        observer->update();
    }
}

void WeatherData::measurementsChanged()
{
    notifyObservers();
}

void WeatherData::setMeasurements(float temperature, float humidity, float pressure)
{
    this->temperature = temperature;
    this->humidity = humidity;
    this->pressure = pressure;
    measurementsChanged();
}

float WeatherData::getTemperature(){
    //std::cout << this->temperature << std::endl;
    return this->temperature;
}

float WeatherData::getHumidity(){
    //std::cout << this->humidity << std::endl;
    return this->humidity;
}

float WeatherData::getPressure(){
    //std::cout << this->pressure << std::endl;
    return this->pressure;
}

WeatherData::~WeatherData()
{
    std::cout << "Cleaning Up our Subject Class" << std::endl;
}

