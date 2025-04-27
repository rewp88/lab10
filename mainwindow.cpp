#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PlagiarismChecker.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(std::make_unique <Ui::MainWindow>()),
    checker(std::make_unique<PlagiarismChecker>())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_checkButton_clicked()
{
    QString inputText = ui->textEdit->toPlainText();
    if (inputText.trimmed().isEmpty())
    {
        QMessageBox::warning(this, tr("Ошибка"), tr("Введите текст для проверки!"));
        return;
    }

    auto results = checker->checkPlagiarism(inputText.toStdString());
    QString resultText;
    for (const auto &result : results)
    {
        resultText.append(QString::fromStdString(result.first)).append(": ");
        resultText.append(QString::number(result.second * 100, 'f', 2)).append("%\n");
    }
    ui->resultText->setPlainText(resultText);
}

void MainWindow::on_openFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть текстовый файл"), "", tr("Текстовые файлы (*.txt);;Все файлы (*.*)"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Ошибка"), tr("Невозможно открыть файл!"));
            return;
        }
        QTextStream in(&file);
        QString text = in.readAll();
        file.close();
        ui->textEdit->setPlainText(text);
    }
}
