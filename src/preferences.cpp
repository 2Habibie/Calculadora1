#include "preferences.h"
#include "ui_preferences.h"

Preferences::Preferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preferences)
{
    ui->setupUi(this);
}

Preferences::~Preferences()
{
    delete ui;
}

void Preferences::on_ahorrarButton_clicked()
{

}

void Preferences::on_okButton_clicked()
{
    QWidget::close();
}

void Preferences::on_comboBox_currentIndexChanged(const QString &language)
{
    emit signalChanged(language);
}
