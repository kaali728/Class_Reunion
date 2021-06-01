#include "klassenmitgliedliste.h"
#include <iostream>

bool KlassenmitgliedListe::instanceFlag = false;
KlassenmitgliedListe* KlassenmitgliedListe::uniqueInstance = NULL;
QtKlassenmitgliedDAO* KlassenmitgliedListe::dao = new QtKlassenmitgliedDAO();
QList<Klassenmitglied *> KlassenmitgliedListe::klassenmitglieder = QList<Klassenmitglied *>();

KlassenmitgliedListe::KlassenmitgliedListe(){}

KlassenmitgliedListe* KlassenmitgliedListe::instance(){
    if(instanceFlag){
        uniqueInstance = new KlassenmitgliedListe();
        instanceFlag = true;
        return uniqueInstance;
    }else{
        return uniqueInstance;
    }
}

Klassenmitglied *KlassenmitgliedListe::ausgeben(QString &id)
{
    QSqlQuery klassenmitglied = dao->auswaehlen(id);
    QStringList tel;
    Klassenmitglied *k;

    while(klassenmitglied.next()){
        QString id = klassenmitglied.value(0).toString();
        QString vorname = klassenmitglied.value(1).toString();
        QString nachname = klassenmitglied.value(2).toString();
        QString land = klassenmitglied.value(3).toString();
        QString email = klassenmitglied.value(4).toString();
        QString ort = klassenmitglied.value(5).toString();
        QString plz = klassenmitglied.value(6).toString();
        k = new Klassenmitglied(id, vorname, nachname, land, email, ort, plz);
        tel << klassenmitglied.value(7).toString();
    }

        k->setTel(tel);

    return k;
}

bool KlassenmitgliedListe::einfuegen(Klassenmitglied *c)
{
    klassenmitglieder.append(c);
    dao->einfuegen(*c);

    return false;
}

bool KlassenmitgliedListe::loeschen(QString &id)
{
    dao->loeschen(id);
    return false;
}

bool KlassenmitgliedListe::telefonUpdate(QString &nummer, QString &id){
 bool res = dao->telefonUpdate(nummer, id);
 return res;
}

QList<Klassenmitglied> *KlassenmitgliedListe::suchen(QString &search)
{
    return NULL;
}

QList<Klassenmitglied *> KlassenmitgliedListe::getAll()
{
    klassenmitglieder = QList<Klassenmitglied *>();
    QSqlQuery klassenmitgliederquery  = dao->getAll();
    while(klassenmitgliederquery.next()){
        QString id = klassenmitgliederquery.value(0).toString();
        QString vorname = klassenmitgliederquery.value(1).toString();
        QString nachname = klassenmitgliederquery.value(2).toString();
        QString land = klassenmitgliederquery.value(3).toString();
        QString email = klassenmitgliederquery.value(4).toString();
        QString ort = klassenmitgliederquery.value(5).toString();
        QString plz = klassenmitgliederquery.value(6).toString();

        Klassenmitglied *k = new Klassenmitglied(id, vorname, nachname, land, email, ort, plz);
        klassenmitglieder << k;
    }
    return  klassenmitglieder;
}
