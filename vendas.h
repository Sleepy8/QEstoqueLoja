#ifndef VENDAS_H
#define VENDAS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QItemSelection>
#include "mainwindow.h"

namespace Ui {
class Vendas;
}

class Vendas : public QWidget
{
    Q_OBJECT

public:
    MainWindow *janelaPrincipal;
    QSqlDatabase db = QSqlDatabase::database();
    explicit Vendas(QWidget *parent = nullptr);
    ~Vendas();
    void atualizarTabelas();

private slots:
    void on_Btn_InserirVenda_clicked();
    void handleSelectionChange(const QItemSelection &selected, const QItemSelection &deselected);

    void on_CBox_Mes_activated(int index);

private:
    QSqlQueryModel *modeloProdVendidos = new QSqlQueryModel;
    QSqlQueryModel *modeloVendas2 = new QSqlQueryModel;
    Ui::Vendas *ui;
};

#endif // VENDAS_H
