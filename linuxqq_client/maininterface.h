#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QWidget>

namespace Ui {
class MainInterface;
}

class MainInterface : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainInterface(QWidget *parent = 0);
    ~MainInterface();
    void refresh_users();



protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pbExit_clicked();
    void m_refresh_users(void)
    {
        refresh_users();
    }

private:
    Ui::MainInterface *ui;



private slots:

};

#endif // MAININTERFACE_H
