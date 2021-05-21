#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QTranslator>

namespace Ui {
class Preferences;
}

class Preferences : public QDialog
{
    Q_OBJECT

public:
    explicit Preferences(QWidget *parent = nullptr);
    ~Preferences();

signals:
    void signalChanged(const QString &language);

private slots:
    void on_ahorrarButton_clicked();
    void on_okButton_clicked();
    void on_comboBox_currentIndexChanged(const QString &language);

private:
    Ui::Preferences *ui;
};

#endif // PREFERENCES_H
