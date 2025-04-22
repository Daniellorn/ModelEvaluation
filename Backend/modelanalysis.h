#ifndef MODELANALYSIS_H
#define MODELANALYSIS_H

#include <QObject>
#include <QVariant>
#include <QPointF>
#include <QList>

#include "Csvreader.h"

class ModelAnalysis : public QObject
{
    Q_OBJECT


    Q_PROPERTY(float accuracy READ accuracy NOTIFY accuracyChanged)
    Q_PROPERTY(float specifity READ specifity NOTIFY specifityChanged)
    Q_PROPERTY(float recall READ recall NOTIFY recallChanged)
    Q_PROPERTY(float precision READ precision NOTIFY precisionChanged)
    Q_PROPERTY(float f1 READ f1 NOTIFY f1Changed)

    Q_PROPERTY(float tp READ tp NOTIFY tpChanged)
    Q_PROPERTY(float tn READ tn NOTIFY tnChanged)
    Q_PROPERTY(float fp READ fp NOTIFY fpChanged)
    Q_PROPERTY(float fn READ fn NOTIFY fnChanged)


public:
    explicit ModelAnalysis(QObject* parent = nullptr, const std::vector<DataRow>& data = {});

    float accuracy() const;
    float specifity() const;
    float recall() const;
    float precision() const;
    float f1() const;

    float tp() const;
    float tn() const;
    float fp() const;
    float fn() const;

    void CalculateROCPoints1();

    Q_INVOKABLE void calculate();

    Q_INVOKABLE QVariantList getROCPoints() const;


    void SetData(std::vector<DataRow>& data);

signals:
    void accuracyChanged();
    void specifityChanged();
    void recallChanged();
    void precisionChanged();
    void f1Changed();

    void tpChanged();
    void tnChanged();
    void fpChanged();
    void fnChanged();

    void rocPointsReady();

private:

    void CalculateMatrix();
    void CalculateAccuracy();
    void CalculateSpecifity();
    void CalculateRecall();
    void CalculatePrecision();
    void CalculateF1();

private:
    std::vector<DataRow> m_FileData;

    QList<QPointF> m_ROCPoints;


    float m_TP;
    float m_TN;
    float m_FP;
    float m_FN;

    float m_accuracy;
    float m_specifity;
    float m_recall;
    float m_precision;
    float m_F1;
};

#endif // MODELANALYSIS_H
