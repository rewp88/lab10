#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class PlagiarismChecker;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_checkButton_clicked();
    void on_openFileButton_clicked();
private:
std::unique_ptr<Ui::MainWindow> ui;
std::unique_ptr<PlagiarismChecker> checker;

};
#endif // MAINWINDOW_H
