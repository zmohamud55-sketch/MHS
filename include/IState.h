
#include/IState.h
```cpp
#ifndef ISTATE_H
#define ISTATE_H

#include <string>

class IState {
public:
    virtual ~IState() {}

    // name of the state
    virtual std::string name() const = 0;

    // called when state becomes active
    virtual void onEnter() const = 0;
};

#endif
