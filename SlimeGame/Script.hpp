#pragma once
#include <functional>

class Script {
public:
    Script(std::function<void()>);
    virtual ~Script();
    virtual void update() = 0;

    void setRepeatable(bool repeat);
    bool isRepeatable() const;
protected:
    void execute();
private:
    bool repeatable;
    bool executed;
    std::function<void()> func;
};

