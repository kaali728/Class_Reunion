#ifndef KLASSENMITGLIEDLISTE_H
#define KLASSENMITGLIEDLISTE_H

#include <QList>
#include <QStringList>
#include "klassenmitglied.h"
#include "qtklassenmitglieddao.h"

class KlassenmitgliedListe
{
private:
        static bool instanceFlag;
        static KlassenmitgliedListe *uniqueInstance;

protected:
        KlassenmitgliedListe();
public:
     static KlassenmitgliedListe* instance();
    ~KlassenmitgliedListe(){
         instanceFlag = false;
     }
    Klassenmitglied* ausgeben(QString &id);
    bool einfuegen(Klassenmitglied* c);
    bool telefonUpdate(QString &nummer, QString &id);
    bool loeschen(QString &id);
    QList<Klassenmitglied>* suchen(QString &search);
    QList<Klassenmitglied *> getAll();
    static QtKlassenmitgliedDAO *dao;
    static QList<Klassenmitglied *> klassenmitglieder;
};

#endif // KLASSENMITGLIEDLISTE_H
