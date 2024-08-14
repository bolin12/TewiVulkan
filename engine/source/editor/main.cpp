#include "editor/editor.h"
#include "runtime/engine.h"
#include <iostream>



int main(int argc, char** argv)
{


    TewiEngine * engine = new TewiEngine();

    TewiEditor * editor = new TewiEditor();

    engine->startEngine();
    engine->initialize();

    editor->initialize(engine);
    editor->run();
    editor->clear();

    engine->clear();
    engine->closeEngine();



}
