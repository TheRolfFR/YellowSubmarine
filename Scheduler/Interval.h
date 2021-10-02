#ifndef YELLOWSUBMARINE_INTERVAL_H
#define YELLOWSUBMARINE_INTERVAL_H

#include <time.h>

template<class T>
class Interval {

private:
    unsigned int duration; /// ms duration
    clock_t t;
    T* object;
public:
    Interval() {}
    Interval (const Interval<T>& o) : duration(o.duration), object(o.object), t(o.t) {}
    Interval(T *object, unsigned int duration) : duration(duration), object(object), t() {}
    Interval &operator=(const Interval<T>& o) {
        duration = o.duration;
        t = o.t;
        object = o.object;
        return *this;
    }
    virtual ~Interval() {}
    bool isIntervalDone();
    T* getObject() { return this->object; }

    void start();
    void restart();
};

template<class T>
bool Interval<T>::isIntervalDone() {
    clock_t interval = (clock() - this->t) * 1000 / CLOCKS_PER_SEC;

    bool isDone = interval > this->duration;

    // reset clock

    if(isDone) {
        this->t = clock();
    }

    return isDone;
}

template<class T>
void Interval<T>::start() {
    this->t = clock();
}

template<class T>
void Interval<T>::restart() {
    this->start();
}


#endif //YELLOWSUBMARINE_INTERVAL_H
