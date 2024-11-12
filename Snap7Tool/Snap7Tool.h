#pragma once

#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <QDateTime>

#include "ui_Snap7Tool.h"
#include "PlcControl/PlcControl.h"

class Snap7Tool : public QMainWindow
{
    Q_OBJECT

public:
    Snap7Tool(QWidget *parent = nullptr);
    ~Snap7Tool();

private slots:
    void on_pushButton_ReadInt_clicked();
    void on_pushButton_ReadString_clicked();
    void on_pushButton_WriteInt_clicked();
    void on_pushButton_WriteString_clicked();

private:
    Ui::Snap7ToolClass ui;
};
