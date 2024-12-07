#include "observer.h"
#include <iostream>
#include <memory>

RaincouverDisplay::RaincouverDisplay(std::shared_ptr<WeatherData> &weatherData)
    :weatherData(weatherData)
{
    std::cout << "Raincouver Display Constructred" << std::endl;
    weatherData->registerObserver(this);
}

void RaincouverDisplay::update()
{
    this->temperature = weatherData->getTemperature();
    this->humidity = weatherData->getHumidity();
    display();
}

void RaincouverDisplay::display()
{
    std::cout << "In Raincouver it always rains!\n with Temps, Humidity:" << this->temperature << " " << 
        this->humidity  <<  std::endl;
}

MinimalDisplay::MinimalDisplay(std::shared_ptr<WeatherData> &weatherData)
    :weatherData(weatherData)
{
    std::cout << "Minimal Display Created" << std::endl;
    weatherData->registerObserver(this);
}

void MinimalDisplay::update()
{
    this->temperature = weatherData->getTemperature();
    this->humidity = weatherData->getHumidity();
    this->pressure = weatherData->getPressure();
    display();
}

void MinimalDisplay::display()
{
    std::cout << "Keeping it minimal:\n"
        << this->humidity << std::endl
        << this->temperature << std::endl
        << this->pressure << std::endl;
}
