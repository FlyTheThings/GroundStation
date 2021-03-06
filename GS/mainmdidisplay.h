#ifndef MAINMDIDISPLAY_H
#define MAINMDIDISPLAY_H

#include <QMainWindow>
#include "qttabtest.h"
#include "missionplanningwindow.h"
#include "ui_mainmdidisplay.h"

#include <assert.h>

//FOR NOW...
#include "mapplanning.h"

#include "maprecap.h"

//TODO Getters and setters. C'mon...

namespace Ui {

    class MainMDIDisplay;

}

class MainMDIDisplay : public QMainWindow {

    Q_OBJECT

public:

    explicit MainMDIDisplay(QWidget *parent = 0);

    void addWindow( QWidget * );

    void addWindow( QWidget * , QString );

    ~MainMDIDisplay();

    QtTabTest * getQttWidget() const;

    void setQttWidget( QtTabTest * );

    void clearMapExecution();

    void clearMapRecap();

    //TODO Make this a switch to execution function
    void changePlanningToExecutionWindow();

    void switchToPlanningWindow();

    void switchToRecapWindow();

private slots:

    void destroy();

    void beginMapExecution();

    void clickedFinishButton_MainDisplay();

    void clickedCancelButton_MainDisplay();

    void clickedBackToPlanningButton_MainDisplay();

    void clickedBackButton_MainDisplay();

private:

    Ui::MainMDIDisplay *ui;

    QtTabTest * qttWidget;

    /* Figure out a way so that we only have one MapPlanning object instead of a pointer to one
        in qttWidget and here. */

    MapPlanning * tempMapPlanningUIWidget;

    QWebView * MapPlanningMapUIWidget;

    MissionPlanningWindow * missionPlanningWindowUIWidget;

    MapExecution * tempMapExecutionUIWidget;

    MapRecap * tempMapRecapUIWidget ;

    QWidget * mapExecutionStatusUIWidget;

    QVBoxLayout * MapExecutionStatusVBoxLayout;

    /* Buttons */

    //TODO Put all the buttons/other UI elements for the GUI here to organize everything in one spot

    QPushButton * backToPlanningButton ;

    /* Tabs */

    QWidget * MapRecapUI_TableTab , * MapRecapUI_GraphTab ;

};

#endif // MAINMDIDISPLAY_H
