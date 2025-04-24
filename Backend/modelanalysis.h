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

    Q_PROPERTY(float accuracy2 READ accuracy2 NOTIFY accuracy2Changed)
    Q_PROPERTY(float specifity2 READ specifity2 NOTIFY specifity2Changed)
    Q_PROPERTY(float recall2 READ recall2 NOTIFY recall2Changed)
    Q_PROPERTY(float precision2 READ precision2 NOTIFY precision2Changed)
    Q_PROPERTY(float f12 READ f12 NOTIFY f12Changed)

    Q_PROPERTY(float tp READ tp NOTIFY tpChanged)
    Q_PROPERTY(float tn READ tn NOTIFY tnChanged)
    Q_PROPERTY(float fp READ fp NOTIFY fpChanged)
    Q_PROPERTY(float fn READ fn NOTIFY fnChanged)

    Q_PROPERTY(float tp2 READ tp2 NOTIFY tp2Changed)
    Q_PROPERTY(float tn2 READ tn2 NOTIFY tn2Changed)
    Q_PROPERTY(float fp2 READ fp2 NOTIFY fp2Changed)
    Q_PROPERTY(float fn2 READ fn2 NOTIFY fn2Changed)

    Q_PROPERTY(float auc READ auc NOTIFY aucChanged)
    Q_PROPERTY(float auc2 READ auc2 NOTIFY auc2Changed)


public:
    explicit ModelAnalysis(QObject* parent = nullptr, const std::vector<DataRow>& data = {});

    float accuracy() const;
    float specifity() const;
    float recall() const;
    float precision() const;
    float f1() const;

    float accuracy2() const;
    float specifity2() const;
    float recall2() const;
    float precision2() const;
    float f12() const;

    float tp() const;
    float tn() const;
    float fp() const;
    float fn() const;

    float tp2() const;
    float tn2() const;
    float fp2() const;
    float fn2() const;

    float auc() const;
    float auc2() const;

    void CalculateROCPoints1();
    void CalculateROCPoints2();

    Q_INVOKABLE void calculate();

    Q_INVOKABLE QVariantList getROCPoints() const;
    Q_INVOKABLE QVariantList getROCPoints2() const;


    void SetData(std::vector<DataRow>& data);

signals:
    void accuracyChanged();
    void specifityChanged();
    void recallChanged();
    void precisionChanged();
    void f1Changed();

    void accuracy2Changed();
    void specifity2Changed();
    void recall2Changed();
    void precision2Changed();
    void f12Changed();

    void tpChanged();
    void tnChanged();
    void fpChanged();
    void fnChanged();

    void tp2Changed();
    void tn2Changed();
    void fp2Changed();
    void fn2Changed();

    void rocPointsReady();
    void aucChanged();

    void rocPoints2Ready();
    void auc2Changed();

private:

    void CalculateMatrix();
    void CalculateAccuracy();
    void CalculateSpecifity();
    void CalculateRecall();
    void CalculatePrecision();
    void CalculateF1();
    void CalculateAUC();

private:
    std::vector<DataRow> m_FileData;

    QList<QPointF> m_ROCPoints;
    QList<QPointF> m_ROCPoints2;

    float m_TP;
    float m_TN;
    float m_FP;
    float m_FN;

    float m_TP2;
    float m_TN2;
    float m_FP2;
    float m_FN2;

    float m_accuracy;
    float m_specifity;
    float m_recall;
    float m_precision;
    float m_F1;

    float m_accuracy2;
    float m_specifity2;
    float m_recall2;
    float m_precision2;
    float m_F12;

    float m_AUC;
    float m_AUC2;
};

#endif // MODELANALYSIS_H
