#include <iostream>
#include <memory>
#include "observer.h"
#include "subject.h"

int main()
{
    std::cout << "In the main program" << std::endl;

    std::shared_ptr<WeatherData> weatherDataSubj = std::make_shared<WeatherData>();

    std::shared_ptr<RaincouverDisplay> couverDisplay = std::make_shared<RaincouverDisplay>(weatherDataSubj);
    std::shared_ptr<MinimalDisplay> minDisplay = std::make_shared<MinimalDisplay>(weatherDataSubj);

    weatherDataSubj->getTemperature();
    weatherDataSubj->setMeasurements(23.1, 700, 2);

}
