//
// Created by TheRolf on 01/10/2021.
//

#ifndef YELLOWSUBMARINE_INTERVALRUNNABLE_H
#define YELLOWSUBMARINE_INTERVALRUNNABLE_H

template<class T>
class IntervalRunnable {
public:
    virtual void run(T*) = 0;
};


#endif //YELLOWSUBMARINE_INTERVALRUNNABLE_H
