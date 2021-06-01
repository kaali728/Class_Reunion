#include "qtklassenmitglieddao.h"
#include <iostream>


using std::cerr; using std::endl; using std::cout;

QtKlassenmitgliedDAO::QtKlassenmitgliedDAO(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//alika//Documents//hochschule//4.semester//SE//klassentreffen//db//klassentreffen.db");
    if (!db.open()) cerr << "Cannot open database!" << endl;
}

QtKlassenmitgliedDAO::~QtKlassenmitgliedDAO(){

}

bool QtKlassenmitgliedDAO::aktualisieren(Klassenmitglied &k){
    return false;
}

QSqlQuery QtKlassenmitgliedDAO::auswaehlen(QString &n){
    QSqlQuery query;
    query.prepare("SELECT * FROM Klassenmitglied left join telefonnummer using (klassenmitgliedID) where klassenmitgliedID='"+n+"'");
    if (!query.exec()) qDebug() << "not working"; // Eventuell Fehlermeldung anzeigen.
    return query;
}


bool QtKlassenmitgliedDAO::einfuegen(Klassenmitglied &k){
    QSqlQuery query;
    query.prepare("insert into Klassenmitglied (klassenmitgliedID, vorname, nameSz, land, email, ort, plz) values ('"+k.getSelected_id()+"', '"+k.getVorname()+"', '"+k.getNachname()+"', '"+k.getLand()+"', '"+k.getEmail()+"', '"+k.getOrt()+"', '"+k.getPlz()+"')");
    if (!query.exec()){
        qDebug() << "not working"; // Eventuell Fehlermeldung anzeigen.
        return false;
    }
    QStringList tel = k.getTel();
    for(int i=0; i<k.getTel().size(); i++){
        query.prepare("insert into telefonnummer (telefonnummer, klassenmitgliedID) values ('"+tel.at(i)+"', '"+k.getSelected_id()+"')");
        if (!query.exec()){
            qDebug() << "not working"; // Eventuell Fehlermeldung anzeigen.
            return false;
        }
    }
    return true;
}

bool  QtKlassenmitgliedDAO::telefonUpdate(QString &nummer, QString &id){
    QSqlQuery query;
    query.prepare("insert into telefonnummer (telefonnummer, klassenmitgliedID) values ('"+nummer+"', '"+id+"')");
    if (!query.exec()){
        qDebug() << "not working"; // Eventuell Fehlermeldung anzeigen.
        return false;
    }
    return true;
}

bool QtKlassenmitgliedDAO::loeschen(QString &id){
    QSqlQuery query;
    query.prepare("delete from Klassenmitglied where klassenmitgliedID='"+id+"'");
    if (!query.exec()){
        qDebug() << "not working"; // Eventuell Fehlermeldung anzeigen.
        return false;
    }
    query.prepare("delete from telefonnummer where klassenmitgliedID='"+id+"'");
    if (!query.exec()){
        qDebug() << "not working"; // Eventuell Fehlermeldung anzeigen.
        return false;
    }

    return true;
}

bool QtKlassenmitgliedDAO::suchen(Klassenmitglied &k){
    return false;
}

QSqlQuery QtKlassenmitgliedDAO::getAll(){
    QSqlQuery query;
    query.prepare("SELECT * FROM Klassenmitglied;");
    if (!query.exec()) qDebug() << "not working"; // Eventuell Fehlermeldung anzeigen.

    return query;
}

bool QtKlassenmitgliedDAO::loginCheck(QString &email, QString &password){
    QSqlQuery query;
    query.prepare("SELECT * FROM Organisator;");
    if (!query.exec()) qDebug() << "not working"; // Eventuell Fehlermeldung anzeigen.
    return false;
}

