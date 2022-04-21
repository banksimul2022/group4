#include "tapahtumat.h"

Tapahtumat::Tapahtumat()
{

}

const QString &Tapahtumat::getSumma() const
{
    return summa;
}

void Tapahtumat::setSumma(const QString &newSumma)
{
    summa = newSumma;
}

const QString &Tapahtumat::getTapahtuma() const
{
    return tapahtuma;
}

void Tapahtumat::setTapahtuma(const QString &newTapahtuma)
{
    tapahtuma = newTapahtuma;
}

const QString &Tapahtumat::getAika() const
{
    return aika;
}

void Tapahtumat::setAika(const QString &newAika)
{
    aika = newAika;
}
