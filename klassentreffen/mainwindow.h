#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <klassenmitgliedliste.h>


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
    void on_klassenMitgliedTable_clicked(const QModelIndex &index);

    void on_newTel_clicked();

    void on_cancelKlassenmitgliedButton_clicked();

    void on_neuKlassenmitgliedButtonButton_clicked();

    void getTableData();

    void on_loeschenKlassenmitgliedButton_clicked();

private:
    Ui::MainWindow *ui;
    KlassenmitgliedListe *klassenmitgliedliste = KlassenmitgliedListe::instance();
    Klassenmitglied *neuesKlassenmitglied;
    QString selected_id;

private:
    void createUI(const QStringList &headers);

};
#endif // MAINWINDOW_H
