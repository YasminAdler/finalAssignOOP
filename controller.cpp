#include "controller.hpp"

void Controller::startGame()
{
    // Command *funcToExecute;
    for (;;)
    {
        // std::vector<std::string> v = view->viewStart(*mg);
        std::pair<Command* , std::vector<std::string>> p = view->viewStart(*mg);

        model->doCommand(p, *mg);
        // funcToExecute = view->viewStart();
    }
    
}