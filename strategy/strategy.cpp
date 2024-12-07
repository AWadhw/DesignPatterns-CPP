#include <iostream>
#include <memory>

class FlyBehaviour
{
    public:
        virtual ~FlyBehaviour() = default;
        virtual void fly() const = 0; 
};

class Duck
{
    public:
        explicit Duck(std::unique_ptr<FlyBehaviour> &&flyBehavior = {}) 
            : mp_flyBehaviour(std::move(flyBehavior))
            {
                if (mp_flyBehaviour == nullptr)
                {
                    std::cout << "Can we make this object with a nullptr" << std::endl;
                }
                else 
                {
                    std::cout << "Constructed Normally" << std::endl;
                }
            }

        void setFlyBehaviour(std::unique_ptr<FlyBehaviour> &&flyBehavior)
        {
            mp_flyBehaviour = std::move(flyBehavior);
        }
        
        void flyMyDuck(void)
        {
            if (mp_flyBehaviour == nullptr)
            {
                std::cout << "Fly behaviour is not set" << std::endl;
            }
            else 
            {
                mp_flyBehaviour->fly();   
            }
        }


    private:
        std::unique_ptr<FlyBehaviour> mp_flyBehaviour;
};

class FlyNoWay : public FlyBehaviour
{
    public:
        void fly() const override;

};

class FlyWithWings : public FlyBehaviour
{
    public:
        void fly() const override;
};

void FlyNoWay::fly() const
{
    std::cout << "Dammit, I cannot fly" << std::endl;
}

void FlyWithWings::fly() const
{
    std::cout << "Fly, Eren, Fly!" << std::endl;
}

int main()
{
    std::unique_ptr<FlyBehaviour> duckNoFlyStrategy = std::make_unique<FlyNoWay>();
    std::unique_ptr<FlyBehaviour> duckFlyStrategy = std::make_unique<FlyWithWings>();

    duckFlyStrategy->fly();

    std::unique_ptr<Duck> myRubberDuck = std::make_unique<Duck>(std::move(duckNoFlyStrategy));
    std::unique_ptr<Duck> myEagleDuck = std::make_unique<Duck>(std::move(duckFlyStrategy));

    myRubberDuck->flyMyDuck();
    myEagleDuck->flyMyDuck();
}
