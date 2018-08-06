#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

using namespace sf;

class State;
typedef std::shared_ptr<State> StatePtr;

class State : public Drawable {
public:
    friend class StateManager;
    enum StateCond {
        STATE_GOOD,
        ADD_STATE,
        REPLACE_STATE,
        REMOVE_STATE
    };

    State();
    virtual ~State();
    virtual void update() = 0;
    virtual void init(int & progress);

    virtual void enterState();
    virtual void leaveState();
protected:
    void stayState();
    void addState(StatePtr state);
    void removeState();
    void replaceState(StatePtr state);
private:
    void setStateCond(StateCond cond, StatePtr next = nullptr);

    StateCond stateCond;
    std::shared_ptr<State> nextState;
};

