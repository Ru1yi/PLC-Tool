#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Snap7Tool.h"

class Snap7Tool : public QMainWindow
{
    Q_OBJECT

public:
    Snap7Tool(QWidget *parent = nullptr);
    ~Snap7Tool();

private:
    Ui::Snap7ToolClass ui;
};
