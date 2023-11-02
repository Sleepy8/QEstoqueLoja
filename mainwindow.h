#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <vector>
#include "produto.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int rowCount;
    std::vector<Produto> produtos;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQueryModel* model = new QSqlQueryModel;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Btn_Enviar_clicked();

    void on_Btn_Delete_clicked();

private:
    Ui::MainWindow *ui;
    void atualizarTableview();
};
#endif // MAINWINDOW_H
