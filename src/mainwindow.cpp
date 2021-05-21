#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    preferences = new Preferences(this);

    connect(preferences, SIGNAL(signalChanged(const QString&)), this, SLOT(on_signalChanged(const QString&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calcularButton_clicked()
{
    const double n1 = ui->doubleSpinBoxNumero1->value();
    const double n2 = ui->doubleSpinBoxNumero2->value();
    double res = 0.0;

    switch (ui->comboBoxOperacion->currentIndex())
    {
    case 0:  // Suma
        res = n1 + n2;
        break;
    case 1:  // Restar
        res = n1 - n2;
        break;
    case 2:  // Multiplicación
        res = n1 * n2;
        break;
    case 3:  // División
        res = n1 / n2;
        break;
    }

    QMessageBox::information(this, tr("Resultado"), tr("El resultado es: %1").arg(res));
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    on_actionSalir_triggered();
}

void MainWindow::on_actionPreferencias_triggered()
{
    preferences->show();
}

void MainWindow::on_signalChanged(const QString &language)
{
    QTranslator T;
    bool result=0;

    if (language == "Portugués")
    {
        qDebug() << "[" << __func__ << "] language changed to:" << language;
        result = T.load("://languages/portugues.qm");
    }
    else if (language == "Inglés")
    {
        qDebug() << "[" << __func__ << "] language changed to:" << language;
        T.load("://languages/ingles.qm");
        result = T.load("://languages/portugues.qm");
    }

    if (language != "Español")
    {
        qDebug() << "[" << __func__ << "]:" << result;
        if(!result)
        {
            qWarning("*** Failed translator.load(\"%s\")", language);
            return;
        }

        qDebug() << "[" << __func__ << "] installing a new translator:" << language;
        qApp->installTranslator(&T);
    }
}
