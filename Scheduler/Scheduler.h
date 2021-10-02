#ifndef H_SCHEDULER
#define H_SCHEDULER

#include <vector>
#include "Interval.h"
#include "IntervalRunnable.h"

template<class T>
class Scheduler {
  private:
    std::vector<Interval<T>> list;
  public:
    Scheduler() : list() {}
    Scheduler(const Scheduler<T>& o) : list(o.list) {}
    Scheduler &operator=(const Scheduler<T>& o) {
      this->list = o.list;
      return this;
    }
    virtual ~Scheduler() {}

    void addObject(T* object, unsigned int intervalDuration);
    void run(IntervalRunnable<T>& runnable);
};

template<class T>
void Scheduler<T>::run(IntervalRunnable<T>& runnable) { // ici la référence est obligatoire car on ne peux pas passer d'arguments par valeur car IntervalRunnable est abstrait
    // on les redémarre tous
    for(typename std::vector<Interval<T>>::iterator it = this->list.begin(); it != this->list.end(); ++it) {
        (*it).start();
    }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

    while(true) {
        for(unsigned int i = 0; i < this->list.size(); ++i) {
            if(this->list[i].isIntervalDone()) { // check and update timer
                runnable.run(this->list[i].getObject()); // start runnabler
            }
        }
    }

#pragma clang diagnostic pop
}

template<class T>
void Scheduler<T>::addObject(T *object, unsigned int intervalDuration) {
    this->list.push_back(Interval<T>(object, intervalDuration));
}

#endif