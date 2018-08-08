#pragma once
#include <list>
#include <memory>
#include "Script.hpp"
class ScriptManager {
public:
    ScriptManager();
    ~ScriptManager();

    void udpate();
    void addScript(std::shared_ptr<Script> scr);
private:
    std::list<std::shared_ptr<Script> > scripts;
};
