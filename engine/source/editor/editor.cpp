
#include <cassert>
#include "editor.h"

#include "runtime/engine.h"

void TewiEditor::initialize(TewiEngine* engine_runtime)
{
    m_engine_runtime = engine_runtime;
}





void TewiEditor::run()
{
    assert(m_engine_runtime);

    float delta_time;
    while(true)
    {
        delta_time = m_engine_runtime->calculateDeltaTime();
    }

}

