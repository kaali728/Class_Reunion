#ifndef KLASSENMITGLIEDDAO_H
#define KLASSENMITGLIEDDAO_H

#include "klassenmitglied.h"
#include <QString>
#include <list>
#include <QtSql>

using namespace std;

class KlassenmitgliedDAO
{
public:
    //KlassenmitgliedDAO();
    virtual ~KlassenmitgliedDAO(){};

    virtual bool aktualisieren(Klassenmitglied &k) = 0;
    virtual QSqlQuery auswaehlen(QString &n) = 0; //geändert von übung2
    virtual bool einfuegen(Klassenmitglied &k) = 0;
    virtual bool telefonUpdate(QString &nummer, QString &id) = 0;
    virtual bool loeschen(QString &id) = 0; //es macht keine sinn ein komplette Object übergeben, es reicht auch mit ne id
    virtual bool suchen(Klassenmitglied &k) = 0;
    virtual bool loginCheck(QString &email, QString &password) = 0;

};

#endif // KLASSENMITGLIEDDAO_H
