#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
//#include <QTranslator>

#include "preferences.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calcularButton_clicked();
    void on_actionSalir_triggered();
    void on_pushButton_clicked();
    void on_actionPreferencias_triggered();
    void on_signalChanged(const QString &language);

private:
    Ui::MainWindow *ui;
    Preferences *preferences;
};
#endif // MAINWINDOW_H
