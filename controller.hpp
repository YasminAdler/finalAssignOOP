#pragma once
#include "model.hpp"
#include "view.hpp"

class Controller
{
private:
    MazeGame* mg;
    Model* model;
    View* view;

public:
    Controller(Model& model_ , View& view_, MazeGame& mg_) : model(&model_) , view(&view_), mg(&mg_) {}
    void startGame();
};
