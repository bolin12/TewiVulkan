#pragma once


class TewiEngine;

class TewiEditor
{
public:


    
    void initialize(TewiEngine * engine_runtime);

    void clear();

    void run();

protected:

    TewiEngine* m_engine_runtime{nullptr};

};
