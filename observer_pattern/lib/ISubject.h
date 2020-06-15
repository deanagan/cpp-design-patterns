#pragma once



namespace ObserverPattern
{
class IObserver;

template<typename ObservableType>
class ISubject
{
public:
    virtual void Register(IObserver observer) = 0;
    virtual void Notify(ObservableType& ot) const = 0;

    virtual ~ISubject() = default;
};
}
