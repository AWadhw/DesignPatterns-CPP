#pragma once

#include "observer.h"
#include <memory>
#include <vector>

class IObserver;

class ISubject 
{
    public:
        virtual ~ISubject(){};
        virtual void registerObserver(IObserver* observer) = 0;
        virtual void removeObserver(IObserver* observer) const = 0;
        virtual void notifyObservers() const = 0;
};

class WeatherData : public ISubject
{
    public:
        ~WeatherData() override;
        void registerObserver(IObserver* observer) override;
        void removeObserver(IObserver* observer) const override;
        void notifyObservers() const override;

        float getTemperature();
        float getHumidity();
        float getPressure();
        void measurementsChanged();

        void setMeasurements(float temperature, float humidity, float pressure); //hack-job

    private:
        std::vector<IObserver*> obsList;
        float temperature;
        float humidity;
        float pressure;
};
