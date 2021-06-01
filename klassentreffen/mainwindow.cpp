#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QInputDialog>
#include <QList>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->createUI(QStringList() << "id"
                                 << "Vorname"
                                 << "Name"
                                 << "Land"
                                 << "Email"
                  );
    connect(ui->neuKlassenmitgliedButtonButton, SIGNAL(clicked()), this, SLOT(getTableData()));
    connect(ui->loeschenKlassenmitgliedButton, SIGNAL(clicked()), this, SLOT(getTableData()));
}



MainWindow::~MainWindow()
{
 delete ui;
}



void MainWindow::createUI(const QStringList &headers){
    //tabelle kopfzeilen aufbauen

    ui->klassenMitgliedTable->setColumnCount(5);
    ui->klassenMitgliedTable->setShowGrid(true);
    ui->klassenMitgliedTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->klassenMitgliedTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->klassenMitgliedTable->setHorizontalHeaderLabels(headers);
    ui->klassenMitgliedTable->horizontalHeader()->setStretchLastSection(true);
    ui->klassenMitgliedTable->verticalHeader()->hide();

    //daten hollen und in der tabelle zeigen
    getTableData();
}

void MainWindow::getTableData(){
    ui->klassenMitgliedTable->clearContents();
    QList<Klassenmitglied *> klassenmitglieder = klassenmitgliedliste->getAll();

    for (int r = 0; r < klassenmitglieder.size(); r++) {
           ui->klassenMitgliedTable->setRowCount(r+1);
           for (int c = 0; c < 6; c++) {
               QTableWidgetItem* item;
               switch(c){
                case 0:
                   item =  new QTableWidgetItem(klassenmitglieder.at(r)->getSelected_id());
                   break;
                case 1:
                   item =  new QTableWidgetItem(klassenmitglieder.at(r)->getVorname());
                   break;
                case 2:
                   item =  new QTableWidgetItem(klassenmitglieder.at(r)->getNachname());
                   break;
                case 3:
                   item =  new QTableWidgetItem(klassenmitglieder.at(r)->getLand());
                   break;
               case 4:
                  item =  new QTableWidgetItem(klassenmitglieder.at(r)->getEmail());
                  break;
               case 5:
                  item =  new QTableWidgetItem(klassenmitglieder.at(r)->getOrt());
                  break;
                default:
                   item = new QTableWidgetItem("FEHLER");
                   break;
               }
             //cout << klassenmitglied.value(c).toString().toStdString();
             item->setFlags(Qt::ItemIsEnabled);
             ui->klassenMitgliedTable->setItem(r, c, item);
           }
         }
}


void MainWindow::on_klassenMitgliedTable_clicked(const QModelIndex &index)
{
    int clickedRow = index.row();
    if(ui->klassenMitgliedTable->model()->index(clickedRow,0).data().toString().length() > 0){

        selected_id = ui->klassenMitgliedTable->model()->index(clickedRow,0).data().toString();
        Klassenmitglied* ausgewaehlteMitglied = klassenmitgliedliste->ausgeben(selected_id);

        ui->nameLine->setText(ausgewaehlteMitglied->getVorname());
        ui->vornameLine->setText(ausgewaehlteMitglied->getNachname());
        ui->landLine->setText(ausgewaehlteMitglied->getLand());
        ui->emailLine->setText(ausgewaehlteMitglied->getEmail());
        ui->ortLine->setText(ausgewaehlteMitglied->getOrt());
        ui->plzLine->setText(ausgewaehlteMitglied->getPlz());
        ui->telCombo->clear();
        ui->telCombo->addItems(ausgewaehlteMitglied->getTel());
    }
}

void MainWindow::on_newTel_clicked()
{
    if(selected_id.length() > 0){
        QString tel = QInputDialog::getText(this, "Neue Telefon", "nummer: ");
        ui->telCombo->addItem(tel);
        ui->telCombo->setCurrentText(tel);
        klassenmitgliedliste->telefonUpdate(tel, selected_id);
    }else{
        QString tel = QInputDialog::getText(this, "Neue Telefon", "nummer: ");
        ui->telCombo->addItem(tel);
        ui->telCombo->setCurrentText(tel);
    }

}

void MainWindow::on_cancelKlassenmitgliedButton_clicked()
{
        //selected_id.clear();
        ui->telCombo->clear();

        ui->nameLine->clear();
        ui->vornameLine->clear();
        ui->landLine->clear();
        ui->emailLine->clear();
        ui->ortLine->clear();
        ui->plzLine->clear();

}

void MainWindow::on_neuKlassenmitgliedButtonButton_clicked()
{
    //neue klassenmitglied erstellen und in der DB speichern
    klassenmitgliedliste->getAll();
    QString id;
    if(klassenmitgliedliste->klassenmitglieder.length() > 0){
        id = QString::number(klassenmitgliedliste->klassenmitglieder.last()->getSelected_id().toInt() + 1);
    }else{
        id = "1";
    }

    QString vorname = ui->nameLine->text();
    QString nachname = ui->vornameLine->text();
    QString land = ui->landLine->text();
    QString email = ui->emailLine->text();
    QString ort = ui->ortLine->text();
    QString plz = ui->plzLine->text();
    QStringList tel;
    for(int i=0; i< ui->telCombo->count(); i++){
        tel << ui->telCombo->itemText(i);
    }
    neuesKlassenmitglied = new Klassenmitglied(id, vorname, nachname, land, email, ort, plz);
    neuesKlassenmitglied->setTel(tel);

    klassenmitgliedliste->einfuegen(neuesKlassenmitglied);
}

void MainWindow::on_loeschenKlassenmitgliedButton_clicked()
{
    klassenmitgliedliste->loeschen(selected_id);
}
