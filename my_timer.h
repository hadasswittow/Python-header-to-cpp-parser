//
// Created by hadasswittow on 8/15/19.
//

#ifndef EXE3C__LANGUAGE_MY_TIMER_H
#define EXE3C__LANGUAGE_MY_TIMER_H

#include "my_time.h"
#include "msg_printer.h"


class Timer {
public:
    Timer(const Time _target, MsgPrinter* printer);
    void tick();// increments clock in 1 second
    void tick(unsigned int seconds); // increments that number of seconds
    void tick(const string str);// with the string “M”, “m”, “Min”, “min”, “Minute” or “minute” increments in one minute, and with the string “H”, “h”, “Hour”, “hour” increments in one hour, other string will throw an error
    void tick(const string str,const unsigned int amount);// increments clock in that amount of minutes/hours
    Time* getClock();
private:
        Time target;
        Time clock;
        MsgPrinter* pprinter;
};
inline void Timer::tick(){// increments clock in 1 second
    clock+=1;
    if(clock>=target)
        pprinter->print();
}
inline void Timer::tick(unsigned int seconds) { // increments that number of seconds
    clock+=seconds;
    if(clock>=target)
        pprinter->print();
}
inline void Timer::tick(const string str) {// with the string “M”, “m”, “Min”, “min”, “Minute” or “minute” increments in one minute, and with the string “H”, “h”, “Hour”, “hour” increments in one hour, other string will throw an error
    if(str.compare("M")==0||str.compare("m")==0||str.compare("Min")==0||str.compare("Minute")==0||str.compare("minute")==0||str.compare("min")==0){
        clock+=60;
    }else if(str.compare("H")==0||str.compare("h")==0||str.compare("Hour")==0||str.compare("hour")==0){
        clock+=(60*60);
    }else{
        throw std::invalid_argument("this is not a legal string for adding time to clock!");
    }
    if(clock>=target)
        pprinter->print();
}
inline void Timer::tick(const string str,const unsigned int amount) {// increments clock in that amount of minutes/hours
    if(str.compare("M")==0||str.compare("m")==0||str.compare("Min")==0||str.compare("Minute")==0||str.compare("minute")==0||str.compare("min")==0){
        clock+=(60*amount);
    }else if(str.compare("H")==0||str.compare("h")==0||str.compare("Hour")==0||str.compare("hour")==0){
        clock+=(amount*60*60);
    }else{
        throw std::invalid_argument("this is not a legal string for adding time to clock!");
    }
    if(clock>=target)
        pprinter->print();
}
void run_timer_1();
void run_timer_2();
void run_timer_3();
void run_timer_4();
#endif //EXE3C__LANGUAGE_MY_TIMER_H
