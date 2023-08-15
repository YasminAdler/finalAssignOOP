//Dean Shalev 209707470
//Yasmin Adler 208462184

#include "controller.hpp"

void Controller::startGame()
{
    for (;;)
    {
        std::pair<Command* , std::vector<std::string>> p = view->viewStart(*mg);
        std::vector<std::string> respons = model->doCommand(p, *mg);
        view->outputRespons(respons);
    }
    
}