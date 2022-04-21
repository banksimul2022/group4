#ifndef TAPAHTUMAT_H
#define TAPAHTUMAT_H
#include <QString>

class Tapahtumat
{
public:
    Tapahtumat();
    QString aika;
    QString tapahtuma;
    QString summa;
    const QString &getAika() const;
    void setAika(const QString &newAika);
    const QString &getTapahtuma() const;
    void setTapahtuma(const QString &newTapahtuma);
    const QString &getSumma() const;
    void setSumma(const QString &newSumma);
};

#endif // TAPAHTUMAT_H
