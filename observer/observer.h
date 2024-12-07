#pragma once
#include "subject.h"
#include <memory>

class WeatherData;

class IObserver
{
    public:
        //virtual ~IObserver();
        virtual void update() = 0;
};

class IDisplayElement
{
    public:
        virtual void display() = 0;
};
 
class RaincouverDisplay : public IObserver, public IDisplayElement
{
    public:
        RaincouverDisplay(std::shared_ptr<WeatherData> &weatherData);
        void update() override;
        void display() override;

    private:
        std::shared_ptr<WeatherData> weatherData;
        float humidity;
        float temperature;
        float pressure;
};

class MinimalDisplay : public IObserver, public IDisplayElement
{
    public:
        MinimalDisplay(std::shared_ptr<WeatherData> &weatherData);
        void update() override;
        void display() override;

    private:
        std::shared_ptr<WeatherData> weatherData;
        float humidity;
        float temperature;
        float pressure;
};
