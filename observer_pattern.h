#ifndef OBSERVER_PATTERN_H
#define OBSERVER_PATTERN_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find

// Observer interface
class Observer {
public:
    virtual void update(float price) = 0; // Pure virtual function
    virtual ~Observer() = default;
};

// Subject class
class Subject {
private:
    std::vector<Observer*> observers; // List of observers

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(float price) {
        for (auto observer : observers) {
            observer->update(price); // Notify each observer
        }
    }
};

// Concrete Subject class
class Stock : public Subject {
private:
    std::string name;
    float price;

public:
    Stock(const std::string& name, float price) : name(name), price(price) {}

    void setPrice(float newPrice) {
        price = newPrice;
        notify(price); // Notify observers of the price change
    }

    std::string getName() const { return name; }
};

// Concrete Observer class
class StockObserver : public Observer {
private:
    std::string observerName;

public:
    StockObserver(const std::string& name) : observerName(name) {}

    void update(float price) override {
        std::cout << "Observer " << observerName << " notified: New stock price is $" << price << std::endl;
    }
};

#endif // OBSERVER_PATTERN_H
